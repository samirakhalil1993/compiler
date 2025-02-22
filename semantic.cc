#include "semantic.h"
#include <iostream>
#include <unordered_set>  


using namespace std;

void processClass(Node *classNode, SymbolTable &table) {
    string className = classNode->value;
    table.addClass(className);
    table.enterScope();
    cout << "[Debug] Entered class: " << className << endl;

    for (Node *member : classNode->children) {
        cout << "[Debug] Node under class: " << member->type << endl;
        if (member->type == "ClassBody") {
            for (Node *classMember : member->children) {
                cout << "[Debug] Class member found: " << classMember->type << " - " << classMember->value << endl;

                if (classMember->type == "MethodDeclaration") {
                    string methodName = classMember->value;
                    string returnType = "int";

                    table.addMethod(className, methodName, returnType);
                    table.enterScope();
                    cout << "[Debug] Added method: " << methodName << " with return type " << returnType << " to class " << className << endl;

                    // Process parameters
                    for (Node *paramSection : classMember->children) {
                        if (paramSection->type == "Parameters") {
                            for (Node *param : paramSection->children) {
                                if (param->type == "Parameter") {
                                    string paramName = param->children.front()->value;
                                    table.addParameter(className, methodName, paramName, "int");
                                    cout << "[Debug] Added parameter: " << paramName << " to method: " << methodName << endl;
                                }
                            }
                        }
                    }

                    // Process local variables
                    for (Node *bodySection : classMember->children) {
                        if (bodySection->type == "MethodBody") {
                            for (Node *stmt : bodySection->children) {
                                if (stmt->type == "VarDeclaration") {
                                    string varName = stmt->children.back()->value;
                                    table.addVariable(className, methodName, varName, "int");
                                    cout << "[Debug] Added local variable: " << varName << " to method: " << methodName << endl;
                                }
                            }
                        }
                    }

                    table.exitScope();
                }
            }
        }
    }

    table.exitScope();
}

#include <iterator> // For std::next

void processMethod(Node *methodNode, SymbolTable &table, string className) {
    auto it = methodNode->children.begin();

    // Extract return type and method name using iterators
    string returnType = (*it)->value; // First child -> return type
    advance(it, 1); // Move iterator to the next element
    string methodName = (*it)->value; // Second child -> method name

    // Add method to symbol table
    table.addMethod(className, methodName, returnType);
    table.enterScope(); // Enter method scope

    // Process parameters (third child)
    advance(it, 1); // Move to parameters list
    Node *parameterList = *it;
    for (Node *param : parameterList->children) {
        if (param->type == "Parameter") {
            string paramName = param->children.front()->value; // Assuming first child has the name
            string paramType = "int"; // Assuming int for simplicity
            table.addParameter(className, methodName, paramName, paramType);
        }
    }

    // Process method body (fourth child)
    advance(it, 1); // Move to method body
    Node *methodBody = *it;
    for (Node *stmt : methodBody->children) {
        if (stmt->type == "VarDeclaration") {
            auto stmtIt = stmt->children.begin();
            string varType = (*stmtIt)->value; // First child -> type
            advance(stmtIt, 1);
            string varName = (*stmtIt)->value; // Second child -> variable name
            table.addVariable(className, methodName, varName, varType);
        }
    }

    table.exitScope(); // Exit method scope
}

bool buildSymbolTable(Node *root, SymbolTable &table) {
    if (!root) {
        cerr << "Semantic Analysis Error: AST root is null!" << endl;
        return false;
    }

    table.enterScope(); // Enter global scope

    // Traverse the AST
    for (Node *child : root->children) {
        if (child->type == "MainClass") {
            string className = child->value;
            table.addClass(className);
            table.enterScope(); // Enter class scope

            for (Node *mainMethod : child->children) {
                if (mainMethod->type == "MainMethod") {
                    string methodName = mainMethod->value;
                    table.addMethod(className, methodName, "void"); // Assume main returns void
                    table.enterScope(); // Enter method scope
                    table.exitScope();  // Exit method scope after processing
                }
            }
            table.exitScope(); // Exit class scope
        }

        else if (child->type == "ClassDeclarations") {
            for (Node *classNode : child->children) {
                if (classNode->type == "ClassDeclaration") {
                    // Use the existing processClass function here
                    processClass(classNode, table);
                }
            }
        }
    }

    table.exitScope(); // Exit global scope
    return true;
}


// Function to perform semantic analysis using the previously built Symbol Table
bool performSemanticChecks(Node *root, SymbolTable &table) {
    if (!root) {
        cerr << "Semantic Analysis Error: AST root is null!" << endl;
        return false;
    }

    cout << "Performing Semantic Analysis..." << endl;

    for (Node *child : root->children) {
        if (child->type == "ClassDeclarations") {
            for (Node *classNode : child->children) {
                if (classNode->type == "ClassDeclaration") {
                    string className = classNode->value;

                    for (Node *member : classNode->children) {
                        if (member->type == "MethodDeclaration") {
                            string methodName = member->value;

                            // Check for correct usage of identifiers
                            checkIdentifierUsage(member, table, className, methodName);

                            // Type checking for assignments and return statements
                            for (Node *stmt : member->children) {
                                if (stmt->type == "Assignment") {
                                    string lhs = stmt->value;
                                    string lhsType = checkType(stmt->children.front(), table, className, methodName);
                                    string rhsType = checkType(stmt->children.back(), table, className, methodName);

                                    if (lhsType != rhsType) {
                                        cerr << "[Semantic Error] Type mismatch in assignment: " << lhs << " (" 
                                             << lhsType << ") = " << rhsType << endl;
                                    }
                                }

                                if (stmt->type == "ReturnStatement") {
                                    string returnType = checkType(stmt->children.front(), table, className, methodName);
                                    string expectedType = table.classes[className].methods[methodName].returnType;

                                    if (returnType != expectedType) {
                                        cerr << "[Semantic Error] Return type mismatch in method '" << methodName
                                             << "': expected '" << expectedType << "', but found '" << returnType << "'" << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "Semantic Analysis Complete!" << endl;
    return true;
}

void checkIdentifierUsage(Node *node, SymbolTable &table, string currentClass, string currentMethod) {
    if (!node) return;

    // If the node is an identifier, check if it's declared
    if (node->type == "Identifier") {
        string identifierName = node->value;

        bool isDeclared = false;

        // Check if it's a class field
        if (table.classes[currentClass].fields.count(identifierName)) {
            isDeclared = true;
        }
        // Check if it's a local variable or parameter
        else if (!currentMethod.empty()) {
            auto &method = table.classes[currentClass].methods[currentMethod];
            if (method.parameters.count(identifierName) || method.variables.count(identifierName)) {
                isDeclared = true;
            }
        }

        // If not declared, print an error
        if (!isDeclared) {
            cerr << "[Semantic Error] Undeclared identifier: '" << identifierName 
                 << "' in method '" << currentMethod << "' of class '" << currentClass << "'" << endl;
        }
    }

    // Recursively check all children
    for (Node *child : node->children) {
        checkIdentifierUsage(child, table, currentClass, currentMethod);
    }
}



string checkType(Node *node, SymbolTable &table, const string &currentClass, const string &currentMethod) {
    if (!node) return "undefined";

    if (node->type == "IntegerLiteral") {
        return "int";
    }

    if (node->type == "BooleanLiteral") {
        return "boolean";
    }

    if (node->type == "Identifier") {
        auto classIt = table.classes.find(currentClass);
        if (classIt != table.classes.end()) {
            auto &classRecord = classIt->second;

            // Check local scope first (method variables, parameters)
            if (classRecord.methods.find(currentMethod) != classRecord.methods.end()) {
                auto &methodRecord = classRecord.methods[currentMethod];

                if (methodRecord.variables.find(node->value) != methodRecord.variables.end()) {
                    return methodRecord.variables[node->value].type;
                }

                if (methodRecord.parameters.find(node->value) != methodRecord.parameters.end()) {
                    return methodRecord.parameters[node->value].type;
                }
            }

            // Check class fields
            if (classRecord.fields.find(node->value) != classRecord.fields.end()) {
                return classRecord.fields[node->value].type;
            }
        }

        cerr << "@error at line " << node->lineno << ". Undeclared Identifier: '" << node->value << "'" << endl;
        return "undefined";
    }

    // Array Access Validation
    if (node->type == "ArrayAccess") {
        string arrayType = checkType(node->children.front(), table, currentClass, currentMethod);
        string indexType = checkType(node->children.back(), table, currentClass, currentMethod);

        if (indexType != "int") {
            cerr << "@error at line " << node->lineno << ". Invalid type of array index (expected 'int', got '" << indexType << "')." << endl;
        }

        if (arrayType != "int[]") {
            cerr << "@error at line " << node->lineno << ". Attempt to access non-array variable as array." << endl;
        }

        return "int";
    }

    // Array Length Validation
    if (node->type == "ArrayLength") {
        string arrayType = checkType(node->children.front(), table, currentClass, currentMethod);
        if (arrayType != "int[]") {
            cerr << "@error at line " << node->lineno << ". Member '.length' used incorrectly. Expected an array type." << endl;
        }
        return "int";
    }

    // Type Checking for Arithmetic Operations
    if (node->type == "AddExpression" || node->type == "SubExpression" || node->type == "MultExpression") {
        string leftType = checkType(node->children.front(), table, currentClass, currentMethod);
        string rightType = checkType(node->children.back(), table, currentClass, currentMethod);

        if (leftType != "int" || rightType != "int") {
            cerr << "@error at line " << node->lineno << ". Arithmetic operations require integer operands." << endl;
        }
        return "int";
    }

    // Method Call Validation
    if (node->type == "MethodCall") {
        string objectType = checkType(node->children.front(), table, currentClass, currentMethod);
        string methodName = node->value;

        if (table.classes.find(objectType) != table.classes.end()) {
            auto &classRecord = table.classes[objectType];
            if (classRecord.methods.find(methodName) != classRecord.methods.end()) {
                return classRecord.methods[methodName].returnType;
            } else {
                cerr << "@error at line " << node->lineno << ". Method '" << methodName << "' not found in class '" << objectType << "'" << endl;
            }
        } else {
            cerr << "@error at line " << node->lineno << ". Object of type '" << objectType << "' does not exist." << endl;
        }
        return "undefined";
    }

    //  Return type mismatch check
    if (node->type == "ReturnStatement") {
        string returnType = checkType(node->children.front(), table, currentClass, currentMethod);
        auto classIt = table.classes.find(currentClass);
        if (classIt != table.classes.end() && classIt->second.methods.find(currentMethod) != classIt->second.methods.end()) {
            string expectedReturnType = classIt->second.methods[currentMethod].returnType;
            if (returnType != expectedReturnType) {
                cerr << "@error at line " << node->lineno << ". Type mismatch in return statement. Expected '" << expectedReturnType << "', got '" << returnType << "'." << endl;
            }
        }
    }

    return "undefined";
}
