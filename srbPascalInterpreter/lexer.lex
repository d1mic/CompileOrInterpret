%option noyywrap
%option nounput

%{

    using namespace std;
    #include <cstdlib>
    #include <iostream>
    #include <map>
    #include <string>
    #include <vector>
    #include "Structures.hpp"

    #include "parser.tab.hpp"
%}

%%

"pocetak"   return pocetak_token;
"kraj"      return kraj_token;
"ako_je"    return ako_je_token;
"onda"      return onda_token;
"ispisi"    return ispisi_token;
"inace"     return inace_token;
"sve_dok"   return sve_dok;
[A-Za-z]+   {   yylval.str = new string(yytext);
                return id_token;
            }
\"([^\"]*)\" {      yylval.str  = new string(yytext);
                    return string_token;}
[0-9]+(\.[0-9]+)? { yylval.num = atof(yytext);
                    return num_token;}
[()\+\*;\.\=\-]   return *yytext;
[\n\t ]     {}
. {
    cerr << "Unknown character " << yytext << endl;
    exit(EXIT_FAILURE);

}

%%