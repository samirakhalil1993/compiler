#ifndef SYMBOL_TABLE_BUILDER_H
#define SYMBOL_TABLE_BUILDER_H

#include "SymbolTable.h"
#include "Node.h"

void processClass(Node *classNode, SymbolTable &table);
void processMethod(Node *methodNode, SymbolTable &table, std::string className);
void buildSymbolTable(Node *root, SymbolTable &table);

#endif // SYMBOL_TABLE_BUILDER_H
