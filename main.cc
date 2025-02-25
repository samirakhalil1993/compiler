#include <iostream>          // For input/output operations
#include "parser.tab.hh"     // Generated parser header from Bison
#include "Node.h"            // Custom header for AST (Abstract Syntax Tree) nodes
#include "SymbolTable.h"     // Symbol Table implementation
#include "SymbolTableBuilder.h"
#include "SemanticAnalyzer.h"

using namespace std;

// External variables declared in other files
extern Node *root;           // Root of the Abstract Syntax Tree (AST)
extern FILE *yyin;           // Input file for the lexer
extern int yylineno;         // Current line number being processed
extern int lexical_errors;   // Number of lexical errors detected
extern yy::parser::symbol_type yylex(); // Lexer function from Flex

// Enum for different error codes
enum errCodes {
    SUCCESS = 0,             // No error
    LEXICAL_ERROR = 1,       // Error in lexical analysis
    SYNTAX_ERROR = 2,        // Error in syntax analysis
    AST_ERROR = 3,           // Error related to Abstract Syntax Tree
    SEMANTIC_ERROR = 4,      // Error in semantic analysis
    SEGMENTATION_FAULT = 139 // Segmentation fault (runtime memory access error)
};

// Variable to track the current error code
int errCode = errCodes::SUCCESS;

// Function to handle syntax errors found by the parser
void yy::parser::error(string const &err) {
    if (!lexical_errors) {
        cerr << "Syntax errors found! See the logs below:" << endl;
        cerr << "\t@error at line " << yylineno << ". Cannot generate a syntax for this input: " << err << endl;
        cerr << "End of syntax errors!" << endl;
        errCode = errCodes::SYNTAX_ERROR;
    }
}

// Main function: Entry point of the compiler
int main(int argc, char **argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    } else {
        cerr << "No input file provided. Please provide a valid file." << endl;
        return 1;
    }

    #ifndef USE_LEX_ONLY
    #define USE_LEX_ONLY false
    #endif

    if (USE_LEX_ONLY) {
        yylex(); // Perform lexical analysis only
    } else {
        yy::parser parser;
        bool parseSuccess = !parser.parse();

        if (lexical_errors) {
            errCode = errCodes::LEXICAL_ERROR;
        }

        if (parseSuccess && !lexical_errors) {
            printf("\nThe compiler successfully generated a syntax tree for the given input!\n");
            printf("\nPrint Tree:\n");

            if (!root) {
                cerr << "Semantic Analysis Error: AST root is null!" << endl;
                return errCodes::AST_ERROR;
            }

            try {
                //root->print_tree();
                root->generate_tree();

                SymbolTable table;

                // Build the symbol table from the AST
                buildSymbolTable(root, table);

                // Detect undeclared identifiers
                //detectUndeclaredIdentifiers(root, table, "", "");

                // Perform general semantic checks
                performSemanticAnalysis(root, table);

                // Print the symbol table and generate DOT file
                //table.printTable();
                table.generateDotFile("st.dot");

            } catch (const exception &e) {
                cerr << "Exception caught: " << e.what() << endl;
                errCode = errCodes::AST_ERROR;
            } catch (...) {
                cerr << "Unknown exception caught." << endl;
                errCode = errCodes::AST_ERROR;
            }
        }
    }

    return errCode;
}
