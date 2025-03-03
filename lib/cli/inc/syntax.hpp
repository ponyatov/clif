#pragma once

#include "libc.hpp"
#include "core.hpp"

extern int yylex();
extern int yylineno;
extern char *yytext;
extern char *yyfile;
extern FILE *yyin;
extern int yyparse();
extern void yyerror(char *msg);
#include "parser.yacc.hpp"
#define TOKEN(C, X)               \
    {                             \
        yylval.o = new C(yytext); \
        return X;                 \
    }
