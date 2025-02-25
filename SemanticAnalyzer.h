#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "SymbolTable.h"
#include "Node.h"
#include <string>

// Main semantic analysis function that runs all checks
void performSemanticAnalysis(Node* root, SymbolTable& table);

// Duplicate identifier detection: Classes, Methods, Variables, Parameters
void checkForDuplicateIdentifiers(Node* root, SymbolTable& table);

// Undeclared identifier detection
void detectUndeclaredIdentifiers(Node* node, SymbolTable& table, std::string currentClass, std::string currentMethod);

// Type checking for expressions, return statements, method calls, array access, and more
string checkType(Node* node, SymbolTable& table, string currentClass, string currentMethod) ;

#endif // SEMANTIC_ANALYZER_H
