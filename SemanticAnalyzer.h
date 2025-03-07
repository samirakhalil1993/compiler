


#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "Node.h"
#include "SymbolTable.h"
#include <iostream>
#include <set>

using namespace std;

// ✅ Utility function to find a symbol in the symbol table
static SymbolRecord* lookupSymbol(SymbolTable& table, string name, string scope) {
    for (auto& record : table.records) {
        if (record.name == name && record.scope == scope) {
            return &record;
        }
    }
    return nullptr;
}

// ✅ Check return types in functions
static void detectInvalidReturnTypes(Node* node, SymbolTable& table, string currentClass, string currentMethod, int& methodBodyLine) {
    if (!node) return;

    if (node->type == "ClassDeclaration") {
        currentClass = node->children.front()->value;
    }

    if (node->type == "MethodDeclaration") {
        currentMethod = node->children[1]->value;
    }

    if (node->type == "MethodBody") {
        methodBodyLine = node->lineno;
    }

    if (node->type == "ReturnStatement") {
        SymbolRecord* methodRecord = lookupSymbol(table, currentMethod, currentClass);
        if (!methodRecord) return;

        string expectedReturnType = methodRecord->type.substr(7); // Remove "Method " prefix
        string actualReturnType = "void";

        if (!node->children.empty()) {
            Node* returnValue = node->children.front();
            actualReturnType = getExpressionType(returnValue, table, currentClass, currentMethod);
        }

        if (actualReturnType != expectedReturnType) {
            cerr << "@error at line " << methodBodyLine << ". semantic (invalid return type: expected " 
                 << expectedReturnType << " but got " << actualReturnType << ")" << endl;
        }
    }

    for (Node* child : node->children) {
        detectInvalidReturnTypes(child, table, currentClass, currentMethod, methodBodyLine);
    }
}

// ✅ Get the type of an expression
static string getExpressionType(Node* node, SymbolTable& table, string currentClass, string currentMethod) {
    if (!node) return "Unknown";

    if (node->type == "IntegerLiteral") return "int";
    if (node->type == "BooleanLiteral") return "boolean";

    if (node->type == "Identifier") {
        SymbolRecord* var = lookupSymbol(table, node->value, currentMethod);
        if (!var) var = lookupSymbol(table, node->value, currentClass);
        if (!var) var = lookupSymbol(table, node->value, "global");

        return (var) ? var->type : "Unknown";
    }

    if (node->type == "MethodCall") {
        SymbolRecord* method = lookupSymbol(table, node->value, currentClass);
        return (method) ? method->type.substr(7) : "Unknown"; // Remove "Method " prefix
    }

    return "Unknown";
}

// ✅ Detect invalid array operations
static void detectInvalidArrayOperations(Node* node, SymbolTable& table, string currentClass, string currentMethod) {
    if (!node) return;

    if (node->type == "ArrayAccess" && node->children.size() >= 1) {
        Node* arrayNode = node->children.front();
        string arrayType = getExpressionType(arrayNode, table, currentClass, currentMethod);

        if (arrayType != "int[]") {
            cerr << "@error at line " << node->lineno << ". semantic (Invalid array access)" << endl;
        }
    }

    for (Node* child : node->children) {
        detectInvalidArrayOperations(child, table, currentClass, currentMethod);
    }
}

// ✅ Detect undefined identifiers
static void detectUndefinedIdentifiers(Node* node, SymbolTable& table, string currentClass, string currentMethod, set<string>& declaredVars) {
    if (!node) return;

    if (node->type == "ClassDeclaration") {
        currentClass = node->children.front()->value;
    }

    if (node->type == "MethodDeclaration") {
        currentMethod = node->children[1]->value;
    }

    if (node->type == "VarDeclaration") {
        string varName = node->children.back()->value;
        declaredVars.insert(varName);
    }

    if (node->type == "AssignmentStatement") {
        string varName = node->children.front()->value;
        if (!declaredVars.count(varName) && !lookupSymbol(table, varName, currentMethod) &&
            !lookupSymbol(table, varName, currentClass) && !lookupSymbol(table, varName, "global")) {
            cerr << "@error at line " << node->lineno << ". semantic ('" << varName << "' is not defined)" << endl;
        }
    }

    for (Node* child : node->children) {
        detectUndefinedIdentifiers(child, table, currentClass, currentMethod, declaredVars);
    }
}

#endif // SEMANTIC_ANALYZER_H
