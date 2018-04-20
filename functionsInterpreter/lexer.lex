%option noyywrap
%option nounput

%{
#include <iostream>
#include <string>
#include <cstdlib>
#include "funkcije.hpp"

using namespace std;

#include "parser.tab.hpp"


%}

%%

"function" return function_token;
"sin"       return sin_token;
"cos"       return cos_token;
"x"         return x_token;
[0-9]+(\.[0-9]+)? {     yylval.br = atof(yytext);
                        return num_token; }
[a-wyzA-Z]    {         yylval.ime = *yytext;
                        return id_token;};
[\.\"()+\n=*/\'\[\]\-]  return *yytext;
[\t ] {}
. {
    cerr << "Unknown symbol: " <<  *yytext << endl;
    exit(EXIT_FAILURE);
}

%%