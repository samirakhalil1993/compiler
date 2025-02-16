
%top{
    #include "parser.tab.hh"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "Node.h"
    int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 

%%


"main"                  {if(USE_LEX_ONLY) {printf("MAIN "); } else { return yy::parser::make_MAIN(yytext); } }
"String"                {if(USE_LEX_ONLY) {printf("STRING "); } else { return yy::parser::make_STRING(yytext); } }
"System"                {if(USE_LEX_ONLY) {printf("SYSTEM "); } else { return yy::parser::make_SYSTEM(yytext); } }
"out"                   {if(USE_LEX_ONLY) {printf("OUT "); } else { return yy::parser::make_OUT(yytext); } }
"println"               {if(USE_LEX_ONLY) {printf("PRINTLN "); } else { return yy::parser::make_PRINTLN(yytext); } }

"class"                 {if(USE_LEX_ONLY) {printf("CLASS ");} else {return yy::parser::make_CLASS(yytext);}}
"public"                {if(USE_LEX_ONLY) {printf("PUBLIC ");} else {return yy::parser::make_PUBLIC(yytext);}}
"static"                {if(USE_LEX_ONLY) {printf("STATIC ");} else {return yy::parser::make_STATIC(yytext);}}
"void"                  {if(USE_LEX_ONLY) {printf("VOID ");} else {return yy::parser::make_VOID(yytext);}}
"int"                   {if(USE_LEX_ONLY) {printf("INT");} else {return yy::parser::make_INT(yytext);}}

"boolean"               {if(USE_LEX_ONLY) {printf("BOOLEAN ");} else {return yy::parser::make_BOOLEAN(yytext);}}
"if"                    {if(USE_LEX_ONLY) {printf("IF ");} else {return yy::parser::make_IF(yytext);}}
"else"                  {if(USE_LEX_ONLY) {printf("ELSE ");} else {return yy::parser::make_ELSE(yytext);}}
"while"                 {if(USE_LEX_ONLY) {printf("WHILE ");} else {return yy::parser::make_WHILE(yytext);}}
"return"                {if(USE_LEX_ONLY) {printf("RETURN ");} else {return yy::parser::make_RETURN(yytext);}}
"this"                  {if(USE_LEX_ONLY) {printf("THIS ");} else {return yy::parser::make_THIS(yytext);}}
"new"                   {if(USE_LEX_ONLY) {printf("NEW ");} else {return yy::parser::make_NEW(yytext);}}
"length"                {if(USE_LEX_ONLY) {printf("LENGTH "); } else { return yy::parser::make_LENGTH(yytext); } }

"||"                    {if(USE_LEX_ONLY) {printf("ANDOR "); } else { return yy::parser::make_ANDOR(yytext); } }
"=="                    {if(USE_LEX_ONLY) {printf("EQ "); } else { return yy::parser::make_EQ(yytext); } }


"="                     {if(USE_LEX_ONLY) {printf("ASSIGN ");} else {return yy::parser::make_ASSIGN(yytext);}}
"+"                     {if(USE_LEX_ONLY) {printf("PLUSOP ");} else {return yy::parser::make_PLUSOP(yytext);}}
"-"                     {if(USE_LEX_ONLY) {printf("SUBOP ");} else {return yy::parser::make_MINUSOP(yytext);}}
"*"                     {if(USE_LEX_ONLY) {printf("MULTOP ");} else {return yy::parser::make_MULTOP(yytext);}}
"<"                     {if(USE_LEX_ONLY) {printf("LT ");} else {return yy::parser::make_LT(yytext);}}
">"                     {if(USE_LEX_ONLY) { printf("GT "); } else { return yy::parser::make_GT(yytext); } }

"&&"                    {if(USE_LEX_ONLY) {printf("AND ");} else {return yy::parser::make_AND(yytext);}}
"("                     {if(USE_LEX_ONLY) {printf("LP ");} else {return yy::parser::make_LP(yytext);}}
")"                     {if(USE_LEX_ONLY) {printf("RP ");} else {return yy::parser::make_RP(yytext);}}
"{"                     {if(USE_LEX_ONLY) {printf("LBRACE ");} else {return yy::parser::make_LBRACE(yytext);}}
"}"                     {if(USE_LEX_ONLY) {printf("RBRACE ");} else {return yy::parser::make_RBRACE(yytext);}}
";"                     {if(USE_LEX_ONLY) {printf("SEMICOLON ");} else {return yy::parser::make_SEMICOLON(yytext);}}
"]"                     {if(USE_LEX_ONLY) {printf("RBRACKET ");} else {return yy::parser::make_RBRACKET(yytext);}}
"["                     {if(USE_LEX_ONLY) {printf("LBRACKET ");} else {return yy::parser::make_LBRACKET(yytext);}}
"."                     {if(USE_LEX_ONLY) {printf("DOT ");} else {return yy::parser::make_DOT(yytext);}}
","                     {if(USE_LEX_ONLY) {printf("COMMA ");} else {return yy::parser::make_COMMA(yytext);}}
"!"                     {if(USE_LEX_ONLY) {printf("NOT ");} else {return yy::parser::make_NOT(yytext);}}

[a-zA-Z_][a-zA-Z0-9_]*  {if(USE_LEX_ONLY) {printf("IDENTIFIER(%s) ", yytext);} else {return yy::parser::make_IDENTIFIER(yytext);}}
[0-9]+                  {if(USE_LEX_ONLY) {printf("INTEGER(%s) ", yytext);} else {return yy::parser::make_INTEGER_LITERAL(yytext);}}

[ \t\n\r]+              {} /* Ignore whitespace */
"//"[^\n]*              {} /* Ignore single-line comments */


.                   { 
    if (!lexical_errors) {
        fprintf(stderr, "Lexical errors found! See the logs below:\n");
    }
    fprintf(stderr, "\t@error at line %d: Character '%s' is not recognized by the grammar\n", yylineno, yytext);
    lexical_errors = 1; 
}
<<EOF>>                  {return yy::parser::make_END();}
%%

