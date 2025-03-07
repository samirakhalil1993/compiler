#include <iostream>
#include "SymbolTable.h"
using namespace std;

void buildSymbolTable(Node *node, SymbolTable &table, string currentScope = "global", string classScope = "") {
    if (!node) return;

    // ✅ Handle Main Class
    if (node->type == "MainClass") {
        classScope = node->children.front()->value; 
        currentScope = classScope;
        
        table.addSymbol(classScope, "Class", "global");
        cout << "Added CLASS: " << classScope << endl;

        for (Node *child : node->children) {
            if (child->type == "MainMethod") {
                string methodName = "main";
                string methodScope = classScope + "." + methodName;

                if (!table.isDeclared(methodName, classScope)) {
                    table.addSymbol(methodName, "Method void", classScope);
                    cout << "Added METHOD: main (Returns: void) in class " << classScope << endl;
                }

                buildSymbolTable(child, table, methodScope, classScope);
            }
        }
    }

    // ✅ Handle Class Declaration
    else if (node->type == "ClassDeclaration") {
        classScope = node->children.front()->value; 
        currentScope = classScope;
        
        if (!table.isDeclared(classScope, "global")) {
            table.addSymbol(classScope, "Class", "global");
            cout << "Added CLASS: " << classScope << endl;
        }

        for (Node *child : node->children) {
            buildSymbolTable(child, table, currentScope, classScope);
        }
    }

    // ✅ Handle Method Declaration
    else if (node->type == "MethodDeclaration") {
        string methodName, returnType;

        for (Node *child : node->children) {
            if (child->type == "Identifier") {
                methodName = child->value;
            } else if (child->type == "Type") {
                returnType = child->value;
            }
        }

        string methodScope = classScope + "." + methodName;
        if (!table.isDeclared(methodName, classScope)) {
            table.addSymbol(methodName, "Method " + returnType, classScope);
            cout << "Added METHOD: " << methodName << " (Returns: " << returnType << ") in class " << classScope << endl;
        }

        currentScope = methodScope;

        for (Node *child : node->children) {
            buildSymbolTable(child, table, currentScope, classScope);
        }
    }

    // ✅ Handle Variable Declarations (Fields & Local Variables)
    else if (node->type == "VarDeclaration") {
        string varName = "", varType = "";

        if (node->children.size() >= 2) { 
            varType = node->children.front()->value;   
            varName = node->children.back()->value;    
        }

        if (!varName.empty() && !varType.empty() && !table.isDeclared(varName, currentScope)) {
            table.addSymbol(varName, "Variable " + varType, currentScope);
            cout << "Added VARIABLE: " << varName << " (Type: " << varType << ") in scope " << currentScope << endl;
        }
    }

    // ✅ Handle Parameter Declarations
    else if (node->type == "ParameterList") {
        for (Node *param : node->children) {
            if (param->type == "Parameter" && param->children.size() >= 2) {
                string paramType = param->children.front()->value;
                string paramName = param->children.back()->value;

                if (!table.isDeclared(paramName, currentScope)) {
                    table.addSymbol(paramName, "Parameter " + paramType, currentScope);
                    cout << "Added PARAMETER: " << paramName << " (Type: " << paramType << ") in scope " << currentScope << endl;
                }
            }
        }
    }

    for (Node *child : node->children) {
        buildSymbolTable(child, table, currentScope, classScope);
    }
}
