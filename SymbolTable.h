// Prevents the file from being included multiple times
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <iostream> // For input/output operations
#include <unordered_map> // For using hash maps (key-value pairs)
#include <string> // For using string data type
#include <map> // Replace unordered_map with map for stable lookups
#include <stack> // For managing scopes


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
    //void print() const;
};

// Class to represent a method (like a function)


  
class MethodRecord {
    public:
        string name, returnType; // Method name and return type
        map<string, SymbolRecord> parameters; // Method parameters
        map<string, SymbolRecord> variables;  // Local variables inside the method
    
        MethodRecord() : name(""), returnType("") {}
        MethodRecord(string n, string rt);
    
        void addParameter(string pname, string ptype);
        void addVariable(string vname, string vtype);
        void print() const;
    };

    
    
    
    
// Class to represent a class (similar to classes in programming languages)
class ClassRecord {
    public:
        string name; // Class name
        map<string, SymbolRecord> fields; // Class fields (variables)
        map<string, MethodRecord> methods; // Class methods
    
        ClassRecord() : name("") {}
        ClassRecord(string n);
    
        void addField(string fname, string ftype);
        void addMethod(string mname, string returnType);
        void print() const;
    };

// SymbolTable class manages all classes, fields, methods, and symbols


class SymbolTable {
    public:
        map<string, ClassRecord> classes; // Use map for deterministic ordering
        stack<map<string, SymbolRecord>> scopes; // Stack for nested scopes using map
    
        void enterScope();  // Start a new scope
        void exitScope();   // End the current scope
        void addSymbol(string name, SymbolRecord record); // Add symbol to the current scope
        bool lookup(string name); // Check if a symbol exists in any scope
    
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
