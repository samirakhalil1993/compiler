#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Stores information about variables, parameters, methods, and fields
struct SymbolRecord {
    string name;
    string type;
    string scope; // e.g., "global", "ClassA", "ClassA.MethodX"

    SymbolRecord(string n, string t, string s) : name(n), type(t), scope(s) {}
};

class SymbolTable {
public:
    vector<SymbolRecord> records; // Flat storage of all symbols

    // ✅ Add a symbol to the table
    void addSymbol(const string& name, const string& type, const string& scope) {
        if (!isDuplicateSymbol(name, scope)) {
            records.push_back(SymbolRecord(name, type, scope));
            cout << "Added symbol: " << name << " (Type: " << type << ", Scope: " << scope << ")" << endl;
        }
    }

    // ✅ Lookup a symbol in a specific scope
    SymbolRecord* lookupSymbol(const string& name, const string& scope) {
        for (auto& record : records) {
            if (record.name == name && record.scope == scope) {
                return &record; // Return pointer to symbol record
            }
        }
        return nullptr;
    }

    // ✅ Check if a symbol exists in the table
    bool isDeclared(const string& name, const string& scope) {
        return lookupSymbol(name, scope) != nullptr;
    }

    // ✅ Print the Symbol Table
    void printTable() const {
        cout << "\n======= Symbol Table =======\n";
        for (const auto& record : records) {
            cout << "Name: " << record.name 
                 << ", Type: " << record.type 
                 << ", Scope: " << record.scope << endl;
        }
        cout << "============================\n";
    }

    // ✅ Write the Symbol Table to a DOT file for visualization
    void generateDotFile(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error: Could not create " << filename << endl;
            return;
        }

        outFile << "digraph SymbolTable {" << endl;
        outFile << "  rankdir=LR;" << endl;
        outFile << "  node [shape=record];" << endl;

        for (const auto& record : records) {
            outFile << "  \"" << record.name << "\" [label=\"{" << record.name 
                    << "|" << record.type << "|" << record.scope << "}\"];" << endl;
        }

        outFile << "}" << endl;
        outFile.close();
        cout << "Symbol table written to " << filename << endl;
    }

private:
    // Check if a symbol is already declared in the given scope
    bool isDuplicateSymbol(const string& name, const string& scope) {
        return lookupSymbol(name, scope) != nullptr;
    }
};


#endif // SYMBOL_TABLE_H
