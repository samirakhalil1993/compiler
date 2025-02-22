// Prevents the file from being included multiple times
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <iostream> // For input/output operations
#include <unordered_map> // For using hash maps (key-value pairs)
#include <string> // For using string data type

using namespace std; // To avoid using std:: everywhere

// Class to represent a symbol (like a variable or parameter)
class SymbolRecord {
public:
    string name, type, scope; // Name, type, and scope of the symbol

    // Default constructor - initializes values to empty
    SymbolRecord() : name(""), type(""), scope("") {}

    // Constructor with parameters to set name, type, and scope
    SymbolRecord(string n, string t, string s);

    // Print symbol information
    void print() const;
};

// Class to represent a method (like a function)
class MethodRecord {
public:
    string name, returnType; // Method name and return type
    unordered_map<string, SymbolRecord> parameters; // Method parameters
    unordered_map<string, SymbolRecord> variables;  // Local variables inside the method

    // Default constructor - initializes name and returnType to empty
    MethodRecord() : name(""), returnType("") {}

    // Constructor with parameters to set name and return type
    MethodRecord(string n, string rt);

    // Add a parameter to the method
    void addParameter(string pname, string ptype);

    // Add a local variable to the method
    void addVariable(string vname, string vtype);

    // Print method details
    void print() const;
};

// Class to represent a class (similar to classes in programming languages)
class ClassRecord {
public:
    string name; // Class name
    unordered_map<string, SymbolRecord> fields; // Fields (variables) of the class
    unordered_map<string, MethodRecord> methods; // Methods of the class

    // Default constructor - initializes name to empty
    ClassRecord() : name("") {}

    // Constructor with parameter to set class name
    ClassRecord(string n);

    // Add a field (variable) to the class
    void addField(string fname, string ftype);

    // Add a method to the class
    void addMethod(string mname, string returnType);

    // Print class details
    void print() const;
};

// SymbolTable class manages all classes, fields, methods, and symbols
#include <stack> // For managing scopes

class SymbolTable {
public:
    unordered_map<string, ClassRecord> classes;
    stack<unordered_map<string, SymbolRecord>> scopes; // Stack for nested scopes

    void enterScope();  // Start a new scope
    void exitScope();   // End the current scope
    void addSymbol(string name, SymbolRecord record); // Add symbol to the current scope
    bool lookup(string name); // Check if a symbol exists in the current scope or outer scopes

    void addClass(string cname);
    void addField(string cname, string fname, string ftype);
    void addMethod(string cname, string mname, string returnType);
    void addParameter(string cname, string mname, string pname, string ptype);
    void addVariable(string cname, string mname, string vname, string vtype);
    void printTable() const;
    void generateDotFile(const string &filename) const;
};


// End of the header file guard
#endif // SYMBOL_TABLE_H
