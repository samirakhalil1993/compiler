#include <set>
#include "SemanticAnalyzer.h"
#include <iostream>

using namespace std;

// ===========================
// Main Semantic Checks Driver
// ===========================
void performSemanticAnalysis(Node* root, SymbolTable& table) {
    if (!root) {
        cerr << "Semantic Analysis Error: AST root is null!" << endl;
        return;
    }

    // Perform all semantic checks
    checkForDuplicateIdentifiers(root, table);
    //detectUndeclaredIdentifiers(root, table, "", "");

    // Perform type checks
    checkType(root, table, "", "");

    cout << "Semantic Analysis Complete!" << endl;
}


// ===========================
// Duplicate Identifier Checks
// ===========================
#include <set> // Use set instead of unordered_set

void checkForDuplicateIdentifiers(Node* root, SymbolTable& table) {
    if (!root) return;

    // Track already declared class names globally using set for deterministic ordering
    static set<string> declaredClasses;

    // Check MainClass declaration for duplicates
    if (root->type == "MainClass") {
        string className = root->value;

        if (declaredClasses.count(className)) {
            std::cerr << "@error at line " << root->lineno << ". semantic (Already Declared Class: '" << className << "')" << std::endl;
        } else {
            declaredClasses.insert(className);
        }
    }

    // Explicitly handle ClassDeclarations node
    if (root->type == "ClassDeclarations") {
        for (Node* classNode : root->children) {
            if (classNode->type == "ClassDeclaration") {
                string className = classNode->value;

                int declarationLine = classNode->lineno;
                if (!classNode->children.empty()) {
                    declarationLine = classNode->children.front()->lineno;
                }

                if (declaredClasses.count(className)) {
                    std::cerr << "@error at line " << declarationLine << ". semantic (Already Declared Class: '" << className << "')" << std::endl;
                } else {
                    declaredClasses.insert(className);
                }

                set<string> fieldNames;  // Track class fields
                set<string> methodNames; // Track class methods

                // Traverse class body for fields and methods
                for (Node* member : classNode->children) {
                    if (member->type == "ClassBody") {
                        for (Node* classMember : member->children) {
                            // Detect duplicate fields
                            if (classMember->type == "VarDeclaration") {
                                string varName = classMember->children.back()->value;
                                if (fieldNames.count(varName)) {
                                    std::cerr << "@error at line " << classMember->lineno << ". semantic (Already Declared variable: '" << varName << "')" << std::endl;
                                } else {
                                    fieldNames.insert(varName);
                                }
                            }

                           
                            
                            using namespace std;
                            
                            // Detect duplicate methods
                            if (classMember->type == "MethodDeclaration") {
                                string methodName = classMember->value;
                            
                                int methodDeclarationLine = classMember->lineno;
                                if (!classMember->children.empty()) {
                                    methodDeclarationLine = classMember->children.front()->lineno;
                                }
                            
                            
                            
                                if (methodNames.count(methodName)) {
                                    std::cerr << "@error at line " << methodDeclarationLine << ". semantic (Already Declared Function: '" << methodName << "')" << std::endl;
                                } else {
                                    methodNames.insert(methodName);
                                }
                            
                                set<string> localIdentifiers;
                            
                                // ✅ Debug parameters addition
                                for (Node* paramSection : classMember->children) {
                                    if (paramSection->type == "Parameters") {
                                        for (Node* param : paramSection->children) {
                                            if (param->type == "Parameter") {
                                                string paramName = param->children.front()->value;
                            
                                                if (localIdentifiers.count(paramName)) {
                                                    std::cerr << "@error at line " << param->lineno << ". semantic (Already Declared parameter: '" << paramName << "')" << std::endl;
                                                } else {
                                                    localIdentifiers.insert(paramName);
                                                }
                                            }
                                        }
                                    }
                                }
                            
                                // ✅ Debug local variable addition
                                for (Node* bodySection : classMember->children) {
                                    if (bodySection->type == "MethodBody") {
                                        for (Node* stmt : bodySection->children) {
                                            if (stmt->type == "VarDeclaration") {
                                                string varName = stmt->children.back()->value;
                            
                                                if (localIdentifiers.count(varName)) {
                                                    std::cerr << "@error at line " << stmt->lineno << ". semantic (Already Declared parameter: '" << varName << "')" << std::endl;
                                                } else {
                                                    localIdentifiers.insert(varName);
                                                }
                                            }
                                        }
                                    }
                                }
                            
                            }
                        }
                    }
                }
            }
        }
    }
    


    // Recursively check child nodes
    for (Node* child : root->children) {
        checkForDuplicateIdentifiers(child, table);
    }
}






// ===================================
// Undeclared Identifiers Detection
// ===================================
void detectUndeclaredIdentifiers(Node* node, SymbolTable& table, string currentClass, string currentMethod) {
    if (!node) return;

    if (node->type == "Identifier") {
        string identifierName = node->value;
        bool isDeclared = false;

        if (identifierName == "true" || identifierName == "false") {
            isDeclared = true;
        }
        else if (table.classes[currentClass].fields.count(identifierName)) {
            isDeclared = true;
        }
        else if (!currentMethod.empty()) {
            auto& method = table.classes[currentClass].methods[currentMethod];
            if (method.parameters.count(identifierName) || method.variables.count(identifierName)) {
                isDeclared = true;
            }
        }
        else if (table.classes.count(identifierName)) {
            isDeclared = true;
        }

        if (!isDeclared) {
            cerr << "Line " << node->lineno << ": semantic (Undeclared identifier: '" << identifierName << "')" << endl;
        }
    }

    for (Node* child : node->children) {
        string updatedClass = currentClass;
        string updatedMethod = currentMethod;

        if (child->type == "ClassDeclaration") {
            updatedClass = child->value;
        }
        if (child->type == "MethodDeclaration") {
            updatedMethod = child->value;
        }

        detectUndeclaredIdentifiers(child, table, updatedClass, updatedMethod);
    }
}





// Helper function to determine the type of a node's expression with added null checks
string checkType(Node* node, SymbolTable& table, string currentClass, string currentMethod) {
    if (!node) return "Unknown";


    // ✅ Handle identifiers (variables, parameters, and fields)
    if (node->type == "Identifier") {
        if (!currentMethod.empty() && table.classes.count(currentClass)) {
            auto& classRecord = table.classes[currentClass];
            if (classRecord.methods.count(currentMethod)) {
                auto& method = classRecord.methods[currentMethod];
                if (method.parameters.count(node->value)) return method.parameters[node->value].type;
                if (method.variables.count(node->value)) return method.variables[node->value].type;
            }
        }

        if (table.classes[currentClass].fields.count(node->value)) {
            return table.classes[currentClass].fields[node->value].type;
        }
    }

    // Detect invalid array indexing (Line 11)
    if (node->type == "ArrayAssignment" && node->children.size() >= 3) {
        auto it = node->children.begin();
        
        string valueType = checkType(*it, table, currentClass, currentMethod);

        
        if (valueType != "int") {
            cerr << "Line " << node->lineno << ": semantic (Invalid type of array index-----)" << endl;
        }
    }
    // Check return type for method declarations
    if (node->type == "ReturnStatement" && currentMethod.empty()) {
        string returnType = table.classes[currentClass].methods[currentMethod].returnType;
        if (!node->children.empty()) {
            string returnValueType = checkType(node->children.front(), table, currentClass, currentMethod);

            if (returnType != returnValueType) {
                cerr << "Line " << node->lineno << ": semantic (Type mismatch)" << endl;
            }
        }
    }


    // Detect invalid array access (e.g., accessing non-array as an array) (Lines 22 & 24)
    if (node->type == "ArrayAccess" && node->children.size() >= 2) {
        string arrayType = checkType(node->children.front(), table, currentClass, currentMethod);
        string indexType = checkType(node->children.back(), table, currentClass, currentMethod);

        
        if (indexType != "int") {
            cerr << "Line " << node->lineno << ": semantic (Invalid type of array index 2)" << endl;
        }
        return "int";
    }

    // Detect invalid use of member .length (Line 18)
    if (node->type == "ArrayLength" && !node->children.empty()) {
        string arrayType = checkType(node->children.front(), table, currentClass, currentMethod);
        if (arrayType != "int[]") {
            cerr << "Line " << node->lineno << ": semantic (Member .length is used incorrectly)" << endl;
        }
        return "int";
    }

    // Detect type mismatch in assignment (Line 22)
    if (node->type == "Assignment" && node->children.size() >= 2) {
        string leftType = checkType(node->children.front(), table, currentClass, currentMethod);
        string rightType = checkType(node->children.back(), table, currentClass, currentMethod);

        if (leftType != rightType) {
            cerr << "Line " << node->lineno << ": semantic (Type mismatch in assignment)" << endl;
        }
    }

    // Recursively check child nodes
    for (Node* child : node->children) {
        checkType(child, table, currentClass, currentMethod);
    }

    return "Unknown";
}
