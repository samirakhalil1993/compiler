#include <iostream>          // For input/output operations
#include "parser.tab.hh"     // Generated parser header from Bison
#include "Node.h"            // Custom header for AST (Abstract Syntax Tree) nodes
#include "semantic.h"        // For semantic analysis functions
#include "SymbolTable.h"     // Symbol Table implementation

using namespace std; // Allows usage of standard library functions without "std::"

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
    if (!lexical_errors) { // Only show syntax errors if no lexical errors were found
        cerr << "Syntax errors found! See the logs below:" << endl;
        cerr << "\t@error at line " << yylineno << ". Cannot generate a syntax for this input: " << err << endl;
        cerr << "End of syntax errors!" << endl;
        errCode = errCodes::SYNTAX_ERROR; // Update the error code for syntax error
    }
}

// Main function: Entry point of the compiler
int main(int argc, char **argv) {
    // Check if an input file is provided as a command-line argument
    if (argc > 1) {
        // Open the input file for reading
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]); // Print error if file cannot be opened
            return 1; // Exit with an error code
        }
    } else {
        cerr << "No input file provided. Please provide a valid file." << endl;
        return 1; // Exit if no input file is provided
    }

    // Define USE_LEX_ONLY if not already defined (used for running lexer only)
    #ifndef USE_LEX_ONLY
    #define USE_LEX_ONLY false
    #endif

    // If only lexical analysis is required, run the lexer
    if (USE_LEX_ONLY) {
        yylex(); // Perform lexical analysis only
    } else {
        yy::parser parser; // Create a parser object
        bool parseSuccess = !parser.parse(); // Run parsing and check if it was successful

        // If lexical errors were found, update the error code
        if (lexical_errors) {
            errCode = errCodes::LEXICAL_ERROR;
        }

        // Proceed if parsing was successful and no lexical errors occurred
        if (parseSuccess && !lexical_errors) {
            printf("\nThe compiler successfully generated a syntax tree for the given input! \n");
            printf("\nPrint Tree:  \n");

            // Check if the AST root is null (to prevent crashes)
            if (!root) {
                cerr << "Semantic Analysis Error: AST root is null!" << endl;
                return errCodes::AST_ERROR; // Return error if AST is invalid
            }

            try {
                // Generate a visual representation of the syntax tree
                root->print_tree();
                root->generate_tree();

                // Run semantic analysis using the Symbol Table
                SymbolTable table; // Create a symbol table

                // First step: Build the symbol table from the AST
                bool symbolTableBuilt = buildSymbolTable(root, table);

                // If the symbol table is successfully built, perform semantic checks
                if (symbolTableBuilt) {
                    bool semanticSuccess = performSemanticChecks(root, table);

                    // If semantic checks are successful, print the symbol table and generate a DOT file
                    if (semanticSuccess) {
                        table.printTable(); // Print the symbol table to console
                        table.generateDotFile("st.dot"); // Export the symbol table as a DOT file for visualization
                    } else {
                        errCode = errCodes::SEMANTIC_ERROR; // Update error code for semantic errors
                    }
                } else {
                    cerr << "Failed to build the symbol table." << endl;
                    errCode = errCodes::SEMANTIC_ERROR; // Update error code if symbol table fails
                }

            } catch (const exception &e) { // Catch standard C++ exceptions
                cerr << "Exception caught: " << e.what() << endl;
                errCode = errCodes::AST_ERROR; // Update error code for AST generation errors
            } catch (...) { // Catch unknown exceptions
                cerr << "Unknown exception caught." << endl;
                errCode = errCodes::AST_ERROR; // Update error code for unexpected AST errors
            }
        }
    }

    return errCode; // Return the final error code to indicate the result of the compilation process
}
