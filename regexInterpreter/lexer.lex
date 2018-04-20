%option noyywrap
%option nounput

%{
    #include <iostream>
    #include <string>
    #include <cstdlib>
    #include "Regex.hpp"
    using namespace std;
    
    #include "parser.tab.hpp"

%}


%%
"DEFINITION" return definition_token;
"BASIC" return basic_token;
"MINLEN"    return minlen_token;
[a-z]   {   yylval.var = *yytext;
            return id_token;}
[A-Z]   {   yylval.var = *yytext;
            return name_token;
                            }
[\|\*\n()\+\[\]=\{\}-]  return *yytext;
[ \t]   {}
. {
    cerr << "Unknown character: " << yytext << endl;
    exit(EXIT_FAILURE);
}



%%