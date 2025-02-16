#ifndef SEMANTIC_HH
#define SEMANTIC_HH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a variable record (stores information about variables)
typedef struct VariableRecord {
    char name[50];                // Name of the variable
    char type[20];                // Data type (e.g., int, float, string)
    int scope_level;              // Scope level of the variable (for scoping rules)
    struct VariableRecord* next;  // Pointer to the next variable in the list
} VariableRecord;

// Define a structure for a method record (stores information about methods in a class)
typedef struct MethodRecord {
    char name[50];                // Name of the method
    char returnType[20];          // Return type of the method
    VariableRecord* parameters;   // Pointer to a list of parameters for the method
    struct MethodRecord* next;    // Pointer to the next method in the class
} MethodRecord;

// Define a structure for a class record (stores information about classes)
typedef struct ClassRecord {
    char name[50];                // Name of the class
    VariableRecord* fields;       // Pointer to a list of class fields (member variables)
    MethodRecord* methods;        // Pointer to a list of methods in the class
    struct ClassRecord* next;     // Pointer to the next class in the symbol table
} ClassRecord;

// Symbol Table structure (stores all classes)
typedef struct SymbolTable {
    ClassRecord* classes;         // Pointer to the first class in the symbol table
} SymbolTable;

// Define a structure for an Abstract Syntax Tree (AST) node
typedef struct ASTNode {
    char type[20];        // Type of node (e.g., "class", "method", "variable")
    char name[50];        // Name of the node
    char dataType[20];    // Data type (for variables and methods)
    struct ASTNode* child; // Pointer to the first child node (sub-nodes)
    struct ASTNode* next;  // Pointer to the next sibling node
} ASTNode;

// Function Prototypes
void addClass(SymbolTable* table, const char* name);
void addMethod(ClassRecord* classRecord, const char* name, const char* returnType);
void addVariable(VariableRecord** list, const char* name, const char* type, int scope_level);
VariableRecord* lookupVariable(VariableRecord* list, const char* name);
ClassRecord* lookupClass(SymbolTable* table, const char* name);
void traverseAST(ASTNode* node, SymbolTable* table);
void printSymbolTable(SymbolTable* table);

#endif // SEMANTIC_HH
