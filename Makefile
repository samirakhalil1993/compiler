compiler: lex.yy.c parser.tab.o semantic.o SymbolTable.o main.o
		g++ -g -w -o compiler parser.tab.o lex.yy.c semantic.o SymbolTable.o main.o -std=c++14

parser.tab.o: parser.tab.cc
		g++ -g -w -c parser.tab.cc -std=c++14

parser.tab.cc: parser.yy
		bison parser.yy

lex.yy.c: lexer.flex parser.tab.cc
		flex lexer.flex

semantic.o: semantic.cc semantic.h SymbolTable.h
		g++ -g -w -c semantic.cc -std=c++14 -o semantic.o

SymbolTable.o: SymbolTable.cpp SymbolTable.h
		g++ -g -w -c SymbolTable.cpp -std=c++14 -o SymbolTable.o

main.o: main.cc semantic.h SymbolTable.h
		g++ -g -w -c main.cc -std=c++14 -o main.o

tree: 
		dot -Tpdf tree.dot -o tree.pdf

sta: 
	    dot -Tpdf st.dot -o st.pdf

clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh position.hh location.hh tree.dot tree.pdf st.dot st.pdf
		rm -f *.o
		rm -R compiler.dSYM  
