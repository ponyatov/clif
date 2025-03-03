#pragma once

extern int yylex();
extern int yylineno;
extern char *yytext;
extern char *yyfile;
extern FILE *yyin;
extern int yyparse();
extern void yyerror(char *msg);
#include "parser.yacc.hpp"
