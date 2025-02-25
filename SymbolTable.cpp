#include "SymbolTable.h"
#include <fstream> // For file operations



// Class to store information about a method (like a function)
MethodRecord::MethodRecord(string n, string rt) : name(n), returnType(rt) {}

// Adds a local variable to the method
void MethodRecord::addVariable(string vname, string vtype) {
    variables[vname] = SymbolRecord(vname, vtype, "local(" + name + ")");
}

// Adds a parameter to the method
void MethodRecord::addParameter(string pname, string ptype) {
    parameters[pname] = SymbolRecord(pname, ptype, "param(" + name + ")");
}


// Prints the method details including its parameters and local variables
void MethodRecord::print() const {
    cout << "    - " << name << " (returns " << returnType << ")" << endl;

    // Print Parameters
    cout << "      Parameters:" << endl;
    if (parameters.empty()) {
        cout << "        - None" << endl;
    } else {
        for (const auto &p : parameters) {
            cout << "        - " << p.second.name << ": " << p.second.type << endl;
        }
    }

    // Print Local Variables
    cout << "      Local Variables:" << endl;
    if (variables.empty()) {
        cout << "        - None" << endl;
    } else {
        for (const auto &v : variables) {
            cout << "        - " << v.second.name << ": " << v.second.type << endl;
        }
    }
}


// Class to store information about a class (like fields and methods)
ClassRecord::ClassRecord(string n) : name(n) {}




// Adds a field (like a class variable) to the class
void ClassRecord::addField(string fname, string ftype) {
    fields[fname] = SymbolRecord(fname, ftype, "class(" + name + ")");
}

// Adds a method to the class
void ClassRecord::addMethod(string mname, string returnType) {
    methods[mname] = MethodRecord(mname, returnType);
}

// Prints the class details including fields and methods
void ClassRecord::print() const {
    cout << "===============================" << endl;
    cout << "Class: " << name << endl;
    cout << "===============================" << endl;

    // Print Fields
    cout << "  Fields:" << endl;
    if (fields.empty()) {
        cout << "    - None" << endl;
    } else {
        for (const auto &f : fields) {
            cout << "    - " << f.second.name << ": " << f.second.type << endl;
        }
    }

    // Print Methods
    cout << "  Methods:" << endl;
    if (methods.empty()) {
        cout << "    - None" << endl;
    } else {
        for (const auto &m : methods) {
            m.second.print();
        }
    }

    cout << endl;
}


// Class to store information about a symbol (like a variable or parameter)*****************************************************************************
SymbolRecord::SymbolRecord(string n, string t, string s) : name(n), type(t), scope(s) {}


// SymbolTable manages all classes, fields, and methods
void SymbolTable::addClass(string cname) {
    classes[cname] = ClassRecord(cname);
}

// Adds a field to a specific class without checking for errors
void SymbolTable::addField(string cname, string fname, string ftype) {
    classes[cname].addField(fname, ftype);
}

// Adds a method to a specific class without checking for errors
void SymbolTable::addMethod(string cname, string mname, string returnType) {
    classes[cname].addMethod(mname, returnType);
}

// Adds a parameter to a specific method in a class without checking for errors
void SymbolTable::addParameter(string cname, string mname, string pname, string ptype) {
    classes[cname].methods[mname].addParameter(pname, ptype);
}

// Adds a variable to a specific method in a class without checking for errors
void SymbolTable::addVariable(string cname, string mname, string vname, string vtype) {
    classes[cname].methods[mname].addVariable(vname, vtype);
}

// Prints the entire symbol table in a structured format
void SymbolTable::printTable() const {
    cout << "\n======= Symbol Table =======\n" << endl;
    for (const auto &c : classes) {
        c.second.print();
    }
    cout << "============================\n" << endl;
}

// Scope management functions using map for deterministic ordering
void SymbolTable::enterScope() {
    scopes.push(map<string, SymbolRecord>());
}


void SymbolTable::exitScope() {
    if (!scopes.empty()) {
        scopes.pop();
    }
}

void SymbolTable::addSymbol(string name, SymbolRecord record) {
    if (!scopes.empty()) {
        scopes.top()[name] = record;
    }
}

// Lookup symbol in all available scopes using map for deterministic ordering
bool SymbolTable::lookup(string name) {
    stack<map<string, SymbolRecord>> temp = scopes;
    while (!temp.empty()) {
        if (temp.top().find(name) != temp.top().end()) {
            return true; // Symbol found
        }
        temp.pop();
    }
    return false; // Symbol not found
}


// Generates a DOT file (graph representation of the symbol table)
void SymbolTable::generateDotFile(const string &filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not create " << filename << endl;
        return;
    }

    outFile << "digraph SymbolTable {" << endl;

    for (const auto &c : classes) {
        outFile << "  " << c.first << " [shape=box, label=\"" << c.first << "\\n(Class)\"];" << endl;

        for (const auto &m : c.second.methods) {
            string methodName = c.first + "_" + m.first;
            outFile << "  " << methodName << " [shape=ellipse, label=\"" << m.first << "\\n(Method)\"];" << endl;
            outFile << "  " << c.first << " -> " << methodName << ";" << endl;

            for (const auto &p : m.second.parameters) {
                string paramName = methodName + "_" + p.first;
                outFile << "  " << paramName << " [shape=diamond, label=\"" << p.first << "\\n(Parameter)\"];" << endl;
                outFile << "  " << methodName << " -> " << paramName << ";" << endl;
            }

            for (const auto &v : m.second.variables) {
                string varName = methodName + "_" + v.first;
                outFile << "  " << varName << " [shape=oval, label=\"" << v.first << "\\n(Variable)\"];" << endl;
                outFile << "  " << methodName << " -> " << varName << ";" << endl;
            }
        }
    }

    outFile << "}" << endl;
    outFile.close();
    cout << "Symbol table written to " << filename << endl;
}
