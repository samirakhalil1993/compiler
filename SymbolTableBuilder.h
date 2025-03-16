#include <iostream>
#include "SymbolTable.h"
using namespace std;

void checkForDuplicate(Node *node, SymbolTable &table, string currentScope = "global", string classScope = "") {
    if (!node) return;

    string prevScope = currentScope;  // Backup previous scope for restoration

    if (node->type == "MainClass") {
        string className = node->children.front()->value;

        //  Check for duplicate BEFORE adding to symbol table
        if (table.isDeclared(className, "Class", "global")) {
            cerr << "@error at line " << node->lineno << ". semantic (Already Declared Class: '" << className << "')" << endl;
        } else {
            table.addSymbol(className, "Class", "global");
        }
    }

    if (node->type == "ClassDeclaration") {
        string className = node->children.front()->value;

        //  Check if the class is already declared in the global scope (including MainClass)
        if (table.isDeclared(className, "Class", "global")) {
            cerr << "@error at line " << node->lineno << ". semantic (Already Declared Class: '" << className << "')" << endl;
        } else {
            table.addSymbol(className, "Class", "global");
        }

        classScope = className;
        currentScope = table.enterScope("", classScope);
    } 

    else if (node->type == "MethodDeclaration") {
        string methodName, returnType;
        for (Node *child : node->children) {
            if (child->type == "Identifier") {
                methodName = child->value;
                break;
            }
        }
        for (Node *child : node->children) {
            if (child->type == "Type") {
                returnType = child->value;
                break;
            }
        }

        currentScope = table.enterScope(classScope, methodName);

        if (table.isDeclared(methodName, "Method", classScope)) {
            cerr << "@error at line " << node->lineno << ". semantic (Already Declared Function: '" << methodName << "')" << endl;
        } else {
            table.addSymbol(methodName, "Method " + returnType, classScope);
        }
    }

    else if (node->type == "VarDeclaration") {
        string varName, varType;
        for (Node *child : node->children) {
            if (child->type == "Identifier") varName = child->value;
            if (child->type == "Type") varType = child->value;
        }
    
        // 🔥 FIX: Check if this variable shadows a parameter
        if (table.isDeclared(varName, "Parameter", currentScope)) {
            cerr << "@error at line " << node->lineno << ". semantic (Already Declared parameter: '" << varName << "')" << endl;
        }
        else if (table.lookupSymbolInScopes(varName, "Variable", currentScope, classScope)) {
            cerr << "@error at line " << node->lineno << ". semantic (Already Declared variable: '" << varName << "')" << endl;
        } 
        else {
            table.addSymbol(varName, "Variable " + varType, currentScope);
        }
    }
    

    else if (node->type == "ParameterList") {
        for (Node *param : node->children) {
            if (param->type == "Parameter") {
                string paramName = param->children.back()->value;
                string paramType = param->children.front()->value;

                if (table.isDeclared(paramName, "Parameter", currentScope)) {
                    cerr << "@error at line " << node->lineno << ". semantic (Already Declared parameter: '" << paramName << "')" << endl;
                } else {
                    table.addSymbol(paramName, "Parameter " + paramType, currentScope);
                }
            }
        }
    }

    //  Recursive traversal of the AST
    for (Node *child : node->children) {
        checkForDuplicate(child, table, currentScope, classScope);
    }

    // Restore previous scope when exiting class/method
    if (node->type == "ClassDeclaration" || node->type == "MethodDeclaration") {
        table.exitScope(currentScope);
        currentScope = prevScope;
    }
}


void checkForUndeclared(Node *node, SymbolTable &table, string currentScope = "global", string classScope = "") {
    //  Base case: If the node is null, return
    if (!node) return;

    //  1️⃣ **Check for undeclared identifiers**
    if (node->type == "Identifier") {
        std::string idValue = node->value;
        SymbolRecord* idRecord = nullptr;

        // 🔍 Search for the identifier in the symbol table
        for (auto &record : table.records) {
            if (record.name == idValue) { 
                idRecord = &record;
                break;
            }
        }

        //  If identifier is not found, print an error
        if (!idRecord) {
            std::cerr << "@error at line " << node->lineno 
                      << ". semantic ('" << idValue << "' does not exist in the current scope)\n";
        }
    }

    //  2️⃣ **Check for method calls in `this.method()` format**
    if (node->type == "AssignmentStatement") {
        Node *left = node->children.back();  

        //  Ensure the assignment involves a method call (`this.method()`)
        if (left->type == "Expression" && left->value == "MethodCall") {
            Node *firstChild = left->children.front();
            Node *methodIdentifier = nullptr;

            // 🔍 Find the method name inside the expression
            for (Node *child : left->children) {
                if (child->type == "Identifier") {
                    methodIdentifier = child;
                    break;
                }
            }

            //  If method call follows `this.method()` syntax, verify existence
            if (firstChild && firstChild->value == "This" && methodIdentifier) {
                std::string methodName = methodIdentifier->value;
                SymbolRecord *methodRecord = table.lookupSymbolInScopes(methodName, "", currentScope, classScope);

                //  Print an error if the method does not exist
                if (!methodRecord) {
                    std::cerr << "@error at line " << node->lineno 
                              << ". semantic ('" << methodName << "' does not exist)\n";
                }
            }
        }
    }

    //  3️⃣ **Check for variable usage before declaration**
    if (node->type == "MethodBodyContent" && !node->children.empty()) {
        Node *firstChild = node->children.front();
        std::string declaredVar;
        int declaredLine = 0;
        Node *assignmentNode = nullptr;

        //  Store variable declaration details
        if (firstChild->type == "VarDeclaration") {
            declaredVar = firstChild->children.back()->value;
            declaredLine = firstChild->children.back()->lineno;

            // 🔍 Look for an assignment statement in the same method
            for (Node *child : node->children) {
                if (child->type == "AssignmentStatement") {
                    assignmentNode = child;
                    break;
                }
            }
        }

        //  If an assignment exists, check if the variable was used before being declared
        if (assignmentNode) {
            Node *left = assignmentNode->children.front();  // Left-hand side of assignment

            if (left->type == "Identifier") {
                std::string usedVar = left->value;
                int usedLine = left->lineno;

                //  Error if variable is used before declaration
                if (usedVar == declaredVar && usedLine < declaredLine) {
                    std::cerr << "@error at line " << usedLine 
                              << ". semantic ('" << usedVar 
                              << "' is not defined yet "")\n";
                }
            }
        }
    }

    //   **Check for variables with undefined types**
    if (node->type == "VarDeclaration") {
        Node *typeNode = node->children.front();
        std::string typeName = typeNode->value;

        //  Ensure the type is valid (`Int`, `Bool`, `Array [int]`)
        if (typeName != "Int" && typeName != "Bool" && typeName != "Array [int]") {
            //  Error if the type is undefined
            if (!table.lookupSymbolInScopes(typeName, "", currentScope, classScope)) {
                std::cerr << "@error at line " << node->lineno 
                          << ". semantic ('" << typeName << "' is undefined)\n";
            }
        }
    }

    //  **Recursively check all child nodes for undeclared identifiers**
    for (Node *child : node->children) {
        checkForUndeclared(child, table, currentScope, classScope);
    }
}
    


void detectInvalidReturnTypes(Node* node, SymbolTable& table, string currentClass, string currentMethod) {
    // Base case: If node is null, return
    if (!node) return;

    // Check if the node is a method declaration
    if (node->type == "MethodDeclaration") {
        std::string expectedReturnType = "Unknown";  // Expected return type
        std::string methodName = "Unknown";         // Method name
        int methodDeclarationLine = node->lineno;   // Store method declaration line

        // Extract method name and return type
        for (Node* child : node->children) {
            if (child->type == "Type") {
                expectedReturnType = child->value;
            } else if (child->type == "Identifier") {
                methodName = child->value;
            }
        }

        // Search for return statements inside the method body
        for (Node* child : node->children) {
            if (child->type == "MethodBody") {
                for (Node* stmt : child->children) {
                    if (stmt->type == "ReturnStatement") {
                        int returnStatementLine = stmt->lineno;  // Store return statement line
                        Node* returnExprNode = stmt->children.front();
                        std::string actualReturnType = "Unknown";  // The actual type being returned

                        // Identify the return expression type
                        if (returnExprNode->type == "IntegerLiteral") {
                            actualReturnType = "Int";
                        } 
                        else if (returnExprNode->type == "BooleanLiteral") {
                            actualReturnType = "Bool";
                        } 
                        else if (returnExprNode->type == "Identifier") {
                            // Check if the identifier is a variable and fetch its type
                            SymbolRecord* varRecord = table.lookupSymbolInScopes(returnExprNode->value, "Variable", currentClass, methodName);
                            if (varRecord) {
                                actualReturnType = varRecord->type;
                            }
                        } 
                        else if (returnExprNode->type == "MethodCall") {
                            // Check if the method exists and fetch its return type
                            SymbolRecord* methodRecord = table.lookupSymbolInScopes(returnExprNode->value, "Method", currentClass, methodName);
                            if (methodRecord) {
                                actualReturnType = methodRecord->type;
                            }
                        } 
                        else if (returnExprNode->type == "ArrayAccess") {
                            // Handle array access expressions
                            Node* arrayNode = returnExprNode->children.front();
                            std::string arrayType = "Unknown";

                            // Fetch the type of the array
                            if (arrayNode->type == "Identifier") {
                                SymbolRecord* arrayRecord = table.lookupSymbolInScopes(arrayNode->value, "Variable", currentClass, methodName);
                                if (arrayRecord) {
                                    arrayType = arrayRecord->type;
                                }
                            }

                            // Validate the array index type
                            Node* indexNode = returnExprNode->children.back();
                            std::string indexType = "Unknown";
                            if (indexNode->type == "IntegerLiteral") {
                                indexType = "Int";
                            } else if (indexNode->type == "Identifier") {
                                SymbolRecord* indexRecord = table.lookupSymbolInScopes(indexNode->value, "Variable", currentClass, methodName);
                                if (indexRecord) {
                                    indexType = indexRecord->type;
                                }
                            }

                            // A valid array access should return an int if the array type is int[]
                            if (arrayType == "Array [int]" && indexType == "Int") {
                                actualReturnType = "Int";
                            }
                        }

                        // If return type mismatches, report the error
                        if (expectedReturnType != actualReturnType) {
                            std::cerr << "@error at line " 
                                      << (returnExprNode->type == "ArrayAccess" ? returnStatementLine : methodDeclarationLine)
                                      << ". semantic (Invalid return type: expected '" << expectedReturnType 
                                      << "', got '" << actualReturnType << "') in method '" << methodName << "'" 
                                      << std::endl;
                        }
                    }
                }
            }
        }
    }

    // Recursively check child nodes
    for (Node* child : node->children) {
        detectInvalidReturnTypes(child, table, currentClass, currentMethod);
    }
}
