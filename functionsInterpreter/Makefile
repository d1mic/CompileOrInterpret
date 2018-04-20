func : lex.yy.o parser.tab.o funkcije.o
	g++ -Wall -o $@ $^
lex.yy.o : lex.yy.c parser.tab.hpp funkcije.hpp
	g++ -Wall -c -o $@ $<
lex.yy.c: lexer.lex funkcije.cpp funkcije.hpp
	flex $<
parser.tab.o : parser.tab.cpp parser.tab.hpp funkcije.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp : parser.ypp 
	bison -d -v $<
funkcije.o : funkcije.cpp funkcije.hpp
	g++ -Wall -c -o $@ $<

.PHONY:
clean:
	rm -rf func *.o *.output *.tab* *.yy.c