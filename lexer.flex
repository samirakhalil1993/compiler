%top{
    #include "parser.tab.hh"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "Node.h"
    int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%

"int"                   {  return yy::parser::make_INT(yytext); }
"boolean"               {  return yy::parser::make_BOOLEAN(yytext); }
"("                     {  return yy::parser::make_LP(yytext); }
")"                     {  return yy::parser::make_RP(yytext); }
"+"                     {  return yy::parser::make_PLUS(yytext); }
"-"                     {  return yy::parser::make_MINUS(yytext); }
"*"                     {  return yy::parser::make_TIMES(yytext); }
"public"                {  return yy::parser::make_PUBLIC(); }
"class"                 {  return yy::parser::make_CLASS(); }
"static"                {  return yy::parser::make_STATIC(); }
"void"                  {  return yy::parser::make_VOID(); }
"main"                  {  return yy::parser::make_MAIN(); }
"String"                {  return yy::parser::make_STRING(); }
"if"                    {  return yy::parser::make_IF(); }
"else"                  {  return yy::parser::make_ELSE(); }
"while"                 {  return yy::parser::make_WHILE(); }
"System.out.println"    {  return yy::parser::make_PRINTLN(); }
"return"                {  return yy::parser::make_RETURN(); }
"new"                   {  return yy::parser::make_NEW(); }
"true"                  {  return yy::parser::make_TRUE(); }
"false"                 {  return yy::parser::make_FALSE(); }
"this"                  {  return yy::parser::make_THIS(); }
"!"                     {  return yy::parser::make_NOT(); }
"{"                     {  return yy::parser::make_LBRACE(); }
"}"                     {  return yy::parser::make_RBRACE(); }
":"                     {  return yy::parser::make_COLON(); }
";"                     {  return yy::parser::make_SEMICOLON(); }
"="                     {  return yy::parser::make_EQUALS(); }
"["                     {  return yy::parser::make_LBRACKET(); }
"]"                     {  return yy::parser::make_RBRACKET(); }
","                     {  return yy::parser::make_COMMA(); }
"."                     {  return yy::parser::make_DOT(); }
"&&"                    {  return yy::parser::make_AND(); }
"||"                    {  return yy::parser::make_OR(); }
"<"                     {  return yy::parser::make_LT(); }
">"                     {  return yy::parser::make_GT(); }
"=="                    {  return yy::parser::make_EQUAL(); }
"/"                     {  return yy::parser::make_DIVIDE(); }
"length"                {  return yy::parser::make_LENGTH(); }
[0-9]+                  { return yy::parser::make_INTEGER_LITERAL(std::stoi(yytext)); }
[a-zA-Z_][a-zA-Z_0-9]*  { return yy::parser::make_IDENTIFIER(std::string(yytext)); }

[ \t\n\r]+              {}
"//"[^\n]*              {}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); fprintf(stderr,"\t@error at line %d. Character %s is not recognized\n", yylineno, yytext); lexical_errors = 1;}
<<EOF>>                  {return yy::parser::make_END();}
%%
