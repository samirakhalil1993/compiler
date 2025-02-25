#include "SymbolTableBuilder.h"
#include <iostream>
using namespace std;

void buildSymbolTable(Node *root, SymbolTable &table) {
    if (!root) {
        cerr << "Semantic Analysis Error: AST root is null!" << endl;
        return;
    }

    table.enterScope(); // Enter global scope

    // ✅ Process MainClass and ClassDeclarations together
    for (Node *child : root->children) {
        // ✅ Handle MainClass
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

        // Handle ClassDeclarations
        if (child->type == "ClassDeclarations") {
            for (Node *classNode : child->children) {
                if (classNode->type == "ClassDeclaration") {
                    string className = classNode->value;
                    table.addClass(className);
                    table.enterScope(); // Enter class scope

                    for (Node *member : classNode->children) {
                        if (member->type == "ClassBody") {
                            for (Node *classMember : member->children) {
                                // Handle class fields (variables)
                                if (classMember->type == "VarDeclaration") {
                                    string fieldTypeNode = classMember->children.front()->type;
                                    string fieldType;

                                    if (fieldTypeNode == "int[]") {
                                        fieldType = "int[]";
                                    } else if (fieldTypeNode == "int") {
                                        fieldType = "int";
                                    } else if (fieldTypeNode == "boolean") {
                                        fieldType = "boolean";
                                    } else {
                                        fieldType = "undefined";
                                    }

                                    string fieldName = classMember->children.back()->value;
                                    table.addField(className, fieldName, fieldType);
                                }

                                // ✅ Handle methods
                                if (classMember->type == "MethodDeclaration") {
                                    string methodName = classMember->value;
                                    string returnType = "int"; // Default return type

                                    table.addMethod(className, methodName, returnType);
                                    table.enterScope(); // Enter method scope

                                    // ✅ Process parameters
                                    for (Node *paramSection : classMember->children) {
                                        if (paramSection->type == "Parameters") {
                                            for (Node *param : paramSection->children) {
                                                if (param->type == "Parameter") {
                                                    string paramType = param->children.front()->type;
                                                    string paramName = param->children.back()->value;
                                                    table.addParameter(className, methodName, paramName, paramType);
                                                    table.addSymbol(paramName, SymbolRecord(paramName, paramType, "param(" + methodName + ")"));
                                                }
                                            }
                                        }
                                    }

                                    // ✅ Process local variables
                                    for (Node *bodySection : classMember->children) {
                                        if (bodySection->type == "MethodBody") {
                                            for (Node *stmt : bodySection->children) {
                                                if (stmt->type == "VarDeclaration") {
                                                    string varType = stmt->children.front()->type;
                                                    string varName = stmt->children.back()->value;
                                                    table.addVariable(className, methodName, varName, varType);
                                                    table.addSymbol(varName, SymbolRecord(varName, varType, "local(" + methodName + ")"));
                                                }
                                            }
                                        }
                                    }

                                    table.exitScope(); // Exit method scope
                                }
                            }
                        }
                    }

                    table.exitScope(); // Exit class scope
                }
            }
        }
    }

    table.exitScope(); // Exit global scope
}
