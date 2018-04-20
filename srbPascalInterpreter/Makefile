pascal : lex.yy.o parser.tab.o Structures.o
	g++ -Wall -o $@ $^
lex.yy.o : lex.yy.c parser.tab.hpp
	g++ -Wall -c -o $@ $<
parser.tab.o : parser.tab.cpp parser.tab.hpp 
	g++ -Wall -c -o $@ $<
lex.yy.c : lexer.lex
	flex $<
parser.tab.cpp parser.tab.hpp : parser.ypp
	bison -v -d $<
Structures.o : Structures.cpp Structures.hpp
	g++ -Wall -c -o $@ $<
	
.PHONY: clean

clean: 	
	rm  *.output *tab* lex.yy.* pascal