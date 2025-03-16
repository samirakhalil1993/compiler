#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <memory>
#include "Node.h"

using namespace std;

// Base class for Three Address Instructions
class ThreeAddressInstr {
public:
    virtual ~ThreeAddressInstr() = default;
    virtual string toString() const = 0;
};

// Different types of Three Address Instructions
class AssignInstr : public ThreeAddressInstr {
    string result, arg;
public:
    AssignInstr(string res, string a) : result(res), arg(a) {}
    string toString() const override { return result + " = " + arg; }
};

class BinaryOpInstr : public ThreeAddressInstr {
    string result, arg1, arg2, op;
public:
    BinaryOpInstr(string res, string a1, string a2, string o) 
        : result(res), arg1(a1), arg2(a2), op(o) {}
    string toString() const override { return result + " = " + arg1 + " " + op + " " + arg2; }
};

class JumpInstr : public ThreeAddressInstr {
    string label;
public:
    JumpInstr(string l) : label(l) {}
    string toString() const override { return "goto " + label; }
};

class CondJumpInstr : public ThreeAddressInstr {
    string condition, label;
public:
    CondJumpInstr(string cond, string l) : condition(cond), label(l) {}
    string toString() const override { return "if " + condition + " goto " + label; }
};

// Basic Block class
class BasicBlock {
public:
    string label;
    vector<unique_ptr<ThreeAddressInstr>> instructions;
    BasicBlock* trueSuccessor;
    BasicBlock* falseSuccessor;

    BasicBlock(string l = "") : label(l), trueSuccessor(nullptr), falseSuccessor(nullptr) {}

    void addInstr(unique_ptr<ThreeAddressInstr> instr) {
        instructions.push_back(std::move(instr));
    }
};

// Control Flow Graph class
class CFG {
private:
    int tempCounter = 0;
    int blockCounter = 0;
    BasicBlock* currentBlock;
    vector<unique_ptr<BasicBlock>> blocks;

public:
    CFG() {
        currentBlock = new BasicBlock("entry");
        blocks.push_back(unique_ptr<BasicBlock>(currentBlock));
    }

    void addBlock(BasicBlock* block) {
        blocks.push_back(unique_ptr<BasicBlock>(block));
    }

    string newTemp() { return "t" + to_string(tempCounter++); }
    string newLabel() { return "L" + to_string(blockCounter++); }

    void printCFG() {
        for (size_t i = 0; i < blocks.size(); ++i) {
            cout << "Block " << i << " (" << blocks[i]->label << "):" << endl;
            for (const auto& instr : blocks[i]->instructions) {
                cout << "  " << instr->toString() << endl;
            }
            cout << endl;
        }
    }

    void generateDotFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error: Unable to create " << filename << endl;
            return;
        }

        outFile << "digraph CFG {\n";

        for (size_t i = 0; i < blocks.size(); ++i) {
            outFile << "  block" << i << " [label=\"Block " << i << "\\n";
            for (const auto& instr : blocks[i]->instructions) {
                outFile << instr->toString() << "\\n";
            }
            outFile << "\"];\n";

            if (blocks[i]->trueSuccessor) {
                auto it = find_if(blocks.begin(), blocks.end(), [&](const unique_ptr<BasicBlock>& b) {
                    return b.get() == blocks[i]->trueSuccessor;
                });
                if (it != blocks.end()) {
                    outFile << "  block" << i << " -> block" << distance(blocks.begin(), it) << " [label=\"true\"];\n";
                }
            }

            if (blocks[i]->falseSuccessor) {
                auto it = find_if(blocks.begin(), blocks.end(), [&](const unique_ptr<BasicBlock>& b) {
                    return b.get() == blocks[i]->falseSuccessor;
                });
                if (it != blocks.end()) {
                    outFile << "  block" << i << " -> block" << distance(blocks.begin(), it) << " [label=\"false\"];\n";
                }
            }
        }

        outFile << "}\n";
        outFile.close();
        cout << "CFG has been written to " << filename << endl;
    }

    void generateIR(Node* node) {
        if (!node) return;

        if (isExpression(node)) {
            handleExpression(node);
        } else {
            handleStatement(node);
        }
    }

private:
    bool isExpression(Node* node) {
        return node->type == "Expression" || 
               node->type == "NewObject" || 
               node->type == "MethodCall";
    }

    void handleExpression(Node* node) {
        if (node->type == "Expression") {
            if (node->value == "Add" || node->value == "Subtract" || node->value == "LessThan") {
                Node* left = node->children.front();
                Node* right = node->children.back();
                
                generateIR(left);
                generateIR(right);
                
                string temp = newTemp();
                currentBlock->addInstr(make_unique<BinaryOpInstr>(
                    temp, left->value, right->value, getOperator(node->value)));
                node->value = temp;
            }
        }
        // Handle other expression types...
    }

    void handleStatement(Node* node) {
        if (node->type == "WhileStatement") {
            BasicBlock* headerBlock = new BasicBlock(newLabel());
            BasicBlock* bodyBlock = new BasicBlock(newLabel());
            BasicBlock* exitBlock = new BasicBlock(newLabel());

            // Link current block to header
            currentBlock->addInstr(make_unique<JumpInstr>(headerBlock->label));
            currentBlock->trueSuccessor = headerBlock;

            // Process condition
            currentBlock = headerBlock;
            generateIR(node->children.front());
            currentBlock->addInstr(make_unique<CondJumpInstr>(
                node->children.front()->value, bodyBlock->label));
            currentBlock->trueSuccessor = bodyBlock;
            currentBlock->falseSuccessor = exitBlock;

            // Process body
            currentBlock = bodyBlock;
            generateIR(node->children.back());
            currentBlock->addInstr(make_unique<JumpInstr>(headerBlock->label));
            currentBlock->trueSuccessor = headerBlock;

            currentBlock = exitBlock;
            blocks.push_back(unique_ptr<BasicBlock>(headerBlock));
            blocks.push_back(unique_ptr<BasicBlock>(bodyBlock));
            blocks.push_back(unique_ptr<BasicBlock>(exitBlock));
        }
        // Handle other statement types...
    }

    string getOperator(const string& type) {
        if (type == "Add") return "+";
        if (type == "Subtract") return "-";
        if (type == "LessThan") return "<";
        return "";
    }
};

void generateIR(Node* node, CFG& cfg, BasicBlock* block) {
    if (!node) return;

    cout << "Processing node type: " << node->type << ", value: " << node->value << endl;

    if (node->type == "AssignmentStatement") {
        std::string varName = node->children.front()->value; // Left-hand side variable
        Node* expr = node->children.back(); // Right-hand side expression

        generateIR(expr, cfg, block); // Generate IR for expression first

        // Generate Three-Address Code (TAC)
        block->addInstr(make_unique<AssignInstr>(varName, expr->value));
    }

    else if (node->type == "IfElseStatement") {
        BasicBlock* condBlock = new BasicBlock("cond");
        BasicBlock* trueBlock = new BasicBlock("true");
        BasicBlock* falseBlock = new BasicBlock("false");
        BasicBlock* exitBlock = new BasicBlock("exit");

        cfg.addBlock(condBlock);
        cfg.addBlock(trueBlock);
        cfg.addBlock(falseBlock);
        cfg.addBlock(exitBlock);

        Node* condition = node->children.front();
        generateIR(condition, cfg, condBlock);

        condBlock->addInstr(make_unique<CondJumpInstr>(condition->value, "true"));
        condBlock->trueSuccessor = trueBlock;
        condBlock->falseSuccessor = falseBlock;

        generateIR(node->children.back()->children.front(), cfg, trueBlock);  // If-branch
        generateIR(node->children.back()->children.back(), cfg, falseBlock); // Else-branch

        trueBlock->trueSuccessor = exitBlock;
        falseBlock->trueSuccessor = exitBlock;
    }

    else if (node->type == "PrintStatement") {
        Node* expr = node->children.front();
        generateIR(expr, cfg, block);
        block->addInstr(make_unique<AssignInstr>("print", expr->value));
    }

    else if (node->type == "MethodCall") {
        // Handle MethodCall node type
        Node* object = node->children.front();
        Node* method = node->children.back();
    
        // Generate IR for the object (if it's a NewObject)
        generateIR(object, cfg, block);
    
        // Generate IR for method arguments
        vector<string> args;
        if (node->children.size() > 2) {
            auto it = node->children.begin();
            std::advance(it, 2);
            for (; it != node->children.end(); ++it) {
                generateIR(*it, cfg, block);
                args.push_back((*it)->value);
            }
        }
    
        std::string tempVar = cfg.newTemp();
        std::string methodCallStr = object->value + "." + method->value;
        if (!args.empty()) {
            methodCallStr += "(" + args[0] + ")";
        }
    
        block->addInstr(make_unique<AssignInstr>(tempVar, methodCallStr));
        node->value = tempVar;
    }

    else if (node->type == "NewObject") {
        // Handle NewObject node type
        std::string className = node->children.front()->value;
        std::string tempVar = cfg.newTemp();
        block->addInstr(make_unique<AssignInstr>(tempVar, className));
        node->value = tempVar; // Update node value to the temporary variable
    }

    else if (node->type == "Expression") {
        if (node->value == "LessThan") {
            Node* left = node->children.front();
            Node* right = node->children.back();
            generateIR(left, cfg, block);
            generateIR(right, cfg, block);
            std::string tempVar = cfg.newTemp();
            block->addInstr(make_unique<BinaryOpInstr>(tempVar, left->value, right->value, "<"));
            node->value = tempVar; // Update node value to the temporary variable
        }
        else if (node->value == "Subtract") {
            Node* left = node->children.front();
            Node* right = node->children.back();
            generateIR(left, cfg, block);
            generateIR(right, cfg, block);
            std::string tempVar = cfg.newTemp();
            block->addInstr(make_unique<BinaryOpInstr>(tempVar, left->value, right->value, "-"));
            node->value = tempVar; // Update node value to the temporary variable
        } else if (node->value == "Add") {
            Node* left = node->children.front();
            Node* right = node->children.back();
            generateIR(left, cfg, block);
            generateIR(right, cfg, block);
            std::string tempVar = cfg.newTemp();
            block->addInstr(make_unique<BinaryOpInstr>(tempVar, left->value, right->value, "+"));
            node->value = tempVar; // Update node value to the temporary variable
        } else if (node->value == "Identifier") {
            node->value = node->children.front()->value;
        } else if (node->type == "IntegerLiteral") {
            node->value = node->value;
        }
    }

    else if (node->type == "WhileStatement") {
        BasicBlock* condBlock = new BasicBlock("while_cond");
        BasicBlock* bodyBlock = new BasicBlock("while_body");
        BasicBlock* exitBlock = new BasicBlock("while_exit");

        cfg.addBlock(condBlock);
        cfg.addBlock(bodyBlock);
        cfg.addBlock(exitBlock);

        // Process the condition
        Node* condition = node->children.front();
        generateIR(condition, cfg, condBlock);
        std::string tempVar = cfg.newTemp();
        condBlock->addInstr(make_unique<BinaryOpInstr>(tempVar, "0", "num", "<"));
        
        // Add conditional branch
        condBlock->addInstr(make_unique<CondJumpInstr>(tempVar, "while_body"));
        condBlock->addInstr(make_unique<JumpInstr>("while_exit"));
        condBlock->trueSuccessor = bodyBlock;
        condBlock->falseSuccessor = exitBlock;

        // Process the body
        generateIR(node->children.back(), cfg, bodyBlock);
        bodyBlock->addInstr(make_unique<JumpInstr>("while_cond"));
        bodyBlock->trueSuccessor = condBlock;

        // Connect current block to condition block
        block->addInstr(make_unique<JumpInstr>("while_cond"));
        block->trueSuccessor = condBlock;
    }

    else if (node->type == "ReturnStatement") {
        Node* expr = node->children.front();
        generateIR(expr, cfg, block);
    
        block->addInstr(make_unique<AssignInstr>("return", expr->value));
    }

    else {
        // Recursively process all child nodes
        for (Node* child : node->children) {
            generateIR(child, cfg, block);
        }
    }
}