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

// Function to add a class to the symbol table
void addClass(SymbolTable* table, const char* name) {
    // Allocate memory for a new class
    ClassRecord* newClass = (ClassRecord*)malloc(sizeof(ClassRecord));
    
    // Initialize the class data
    strcpy(newClass->name, name);
    newClass->fields = NULL;      // No fields yet
    newClass->methods = NULL;     // No methods yet
    newClass->next = table->classes;  // Insert at the beginning of the list

    // Update the symbol table to point to the new class
    table->classes = newClass;
}

// Function to add a method to a class
void addMethod(ClassRecord* classRecord, const char* name, const char* returnType) {
    // Allocate memory for a new method
    MethodRecord* newMethod = (MethodRecord*)malloc(sizeof(MethodRecord));

    // Initialize the method data
    strcpy(newMethod->name, name);
    strcpy(newMethod->returnType, returnType);
    newMethod->parameters = NULL; // No parameters yet
    newMethod->next = classRecord->methods;  // Insert at the beginning of the list

    // Update the class to point to the new method
    classRecord->methods = newMethod;
}

// Function to add a variable to a list of variables (for fields, parameters, or local variables)
void addVariable(VariableRecord** list, const char* name, const char* type, int scope_level) {
    // Allocate memory for a new variable
    VariableRecord* newVar = (VariableRecord*)malloc(sizeof(VariableRecord));

    // Initialize the variable data
    strcpy(newVar->name, name);
    strcpy(newVar->type, type);
    newVar->scope_level = scope_level;
    newVar->next = *list;  // Insert at the beginning of the list

    // Update the list to point to the new variable
    *list = newVar;
}

// Function to search for a variable in a given list
VariableRecord* lookupVariable(VariableRecord* list, const char* name) {
    while (list != NULL) {  // Traverse the list
        if (strcmp(list->name, name) == 0) {  // Compare names
            return list;  // Found the variable
        }
        list = list->next;  // Move to the next variable
    }
    return NULL;  // Variable not found
}

// Function to search for a class in the symbol table
ClassRecord* lookupClass(SymbolTable* table, const char* name) {
    ClassRecord* current = table->classes;
    while (current != NULL) {  // Traverse the list of classes
        if (strcmp(current->name, name) == 0) {  // Compare names
            return current;  // Found the class
        }
        current = current->next;  // Move to the next class
    }
    return NULL;  // Class not found
}

// Define a structure for an Abstract Syntax Tree (AST) node
typedef struct ASTNode {
    char type[20];        // Type of node (e.g., "class", "method", "variable")
    char name[50];        // Name of the node
    char dataType[20];    // Data type (for variables and methods)
    struct ASTNode* child; // Pointer to the first child node (sub-nodes)
    struct ASTNode* next;  // Pointer to the next sibling node
} ASTNode;

// Function to traverse an Abstract Syntax Tree (AST) and populate the symbol table
void traverseAST(ASTNode* node, SymbolTable* table) {
    while (node != NULL) {  // Traverse the AST nodes
        if (strcmp(node->type, "class") == 0) {
            // If the node represents a class, add it to the symbol table
            addClass(table, node->name);
        } else if (strcmp(node->type, "method") == 0) {
            // If the node represents a method, add it to the current class
            ClassRecord* currentClass = lookupClass(table, "CurrentClassName");  // Needs update
            if (currentClass != NULL) {
                addMethod(currentClass, node->name, node->dataType);
            }
        } else if (strcmp(node->type, "variable") == 0) {
            // Add variable to the current scope (logic needs updating)
        }

        // Recursively traverse child nodes
        traverseAST(node->child, table);
        node = node->next;  // Move to the next sibling node
    }
}

// Function to print the contents of the symbol table
void printSymbolTable(SymbolTable* table) {
    ClassRecord* classPtr = table->classes;
    while (classPtr != NULL) {  // Traverse the list of classes
        printf("Class: %s\n", classPtr->name);

        MethodRecord* methodPtr = classPtr->methods;
        while (methodPtr != NULL) {  // Traverse the methods in the class
            printf("  Method: %s, Return Type: %s\n", methodPtr->name, methodPtr->returnType);
            methodPtr = methodPtr->next;
        }

        VariableRecord* fieldPtr = classPtr->fields;
        while (fieldPtr != NULL) {  // Traverse the fields in the class
            printf("  Field: %s, Type: %s\n", fieldPtr->name, fieldPtr->type);
            fieldPtr = fieldPtr->next;
        }

        classPtr = classPtr->next;  // Move to the next class
    }
}
