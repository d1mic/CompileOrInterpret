regex : lex.yy.o parser.tab.o Regex.o
	g++ -Wall -o $@ $^
lex.yy.o : lex.yy.c parser.tab.hpp
	g++ -Wall -c -o $@ $<
lex.yy.c : lexer.lex
	flex $<
parser.tab.o : parser.tab.cpp parser.tab.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp : parser.ypp
	bison -v -d $<
Regex.o : Regex.cpp Regex.hpp
	g++ -Wall -c -o $@ $<
.PHONY: clean
clean:
	rm  -rf *tab* *.yy.c *.o *.output regex 