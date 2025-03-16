# Target to build the final compiler executable
compiler: lex.yy.c parser.tab.o main.o
	g++ -g -w -o compiler parser.tab.o lex.yy.c main.o -std=c++14

# Compile the parser generated from Bison
parser.tab.o: parser.tab.cc
	g++ -g -w -c parser.tab.cc -std=c++14

# Generate parser from Bison grammar file
parser.tab.cc: parser.yy
	bison parser.yy

# Generate lexer from Flex file
lex.yy.c: lexer.flex parser.tab.cc
	flex lexer.flex

# Compile the main compiler driver
main.o: main.cc SymbolTable.h SymbolTableBuilder.h Node.h irg.h
	g++ -g -w -c main.cc -std=c++14 -o main.o

# Generate a visual PDF for the parse tree
tree:
	dot -Tpdf tree.dot -o tree.pdf

# Generate a visual PDF for the symbol table
st:
	dot -Tpdf st.dot -o st.pdf

# Generate a visual PDF for the control flow graph
cfg:
	dot -Tpdf cfg.dot -o cfg.pdf


# Clean up generated files
clean:
	rm -f parser.tab.* lex.yy.c* compiler stack.hh position.hh location.hh tree.dot tree.pdf st.dot st.pdf cfg.pdf
	rm -f *.o
	rm -R compiler.dSYM
