#include <iostream>
#include "parser.tab.hh"

// External variables from the lexer/parser
extern Node *root;       // Pointer to the root of the syntax tree
extern FILE *yyin;       // File pointer for input file
extern int yylineno;     // Keeps track of the current line number
extern int lexical_errors;  // Counts the number of lexical errors
extern yy::parser::symbol_type yylex(); // Function for lexical analysis

// Enumeration for different error codes
enum errCodes
{
	SUCCESS = 0,            // No errors
	LEXICAL_ERROR = 1,      // Lexical error (invalid tokens)
	SYNTAX_ERROR = 2,       // Syntax error (invalid grammar)
	AST_ERROR = 3,          // Error in Abstract Syntax Tree (AST) generation
	SEMANTIC_ERROR = 4,     // Semantic error (not implemented in this code)
	SEGMENTATION_FAULT = 139 // Segmentation fault (crash)
};

// Global variable to store error status
int errCode = errCodes::SUCCESS;

// Function to handle syntax errors during parsing
void yy::parser::error(std::string const &err)
{
	if (!lexical_errors) // Only report syntax errors if there are no lexical errors
	{
		std::cerr << "Syntax errors found! See the logs below:" << std::endl;
		std::cerr << "\t@error at line " << yylineno << ". Cannot generate a syntax for this input: " 
		          << err.c_str() << std::endl;
		std::cerr << "End of syntax errors!" << std::endl;
		errCode = errCodes::SYNTAX_ERROR; // Set error code to syntax error
	}
}

int main(int argc, char **argv)
{
	// Check if a file is provided as an argument
	if (argc > 1)
	{
		// Try to open the file for reading
		if (!(yyin = fopen(argv[1], "r")))
		{
			perror(argv[1]); // Print error if file cannot be opened
			return 1; // Exit with error code 1
		}
	}
	
	// If only lexical analysis is required, call yylex() and exit
	if (USE_LEX_ONLY)
		yylex();
	else
	{
		yy::parser parser; // Create a parser object

		// Parse the input and check if parsing was successful
		bool parseSuccess = !parser.parse(); // parser.parse() returns 0 on success

		// If there were lexical errors, update error code
		if (lexical_errors)
			errCode = errCodes::LEXICAL_ERROR;

		// If parsing was successful and there were no lexical errors
		if (parseSuccess && !lexical_errors)
		{
			printf("\nThe compiler successfully generated a syntax tree for the given input! \n");

			printf("\nPrint Tree:  \n");
			try
			{
				root->print_tree();    // Print the syntax tree
				root->generate_tree(); // Generate tree structure
			}
			catch (...)
			{
				errCode = errCodes::AST_ERROR; // Set error code if AST generation fails
			}
		}
	}

	return errCode; // Return the final error code
}
