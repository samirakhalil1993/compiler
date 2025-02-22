#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "Node.h"
#include "SymbolTable.h"


// ✅ Declare the function before using it in semantic.cc
void checkIdentifierUsage(Node *node, SymbolTable &table, std::string currentClass, std::string currentMethod);

bool buildSymbolTable(Node *root, SymbolTable &table);
bool performSemanticChecks(Node *root, SymbolTable &table);

// ✅ Update declaration to include method name
std::string checkType(Node *node, SymbolTable &table, const std::string &currentClass, const std::string &currentMethod);



// Function prototypes for processing AST nodes
void processClass(Node *node, SymbolTable &table);
void processMethod(std::string className, Node *node, SymbolTable &table);

#endif // SEMANTIC_H