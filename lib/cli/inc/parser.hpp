#pragma once

#include "libc.hpp"
#include "core.hpp"

/// @defgroup parser parser
/// @ingroup cli
/// @brief parser interface
/// @{

extern int yylex();              ///< lexer (`flex`)
extern int yylineno;             ///< current line
extern char *yytext;             ///< lexeme value
extern char *yyfile;             ///< current file name
extern FILE *yyin;               ///< current file handler
extern int yyparse();            ///< parser (`bison`)
extern void yyerror(char *msg);  ///< syntax error callback

#include "parser.yacc.hpp"

/// @brief construct token `(Class,ID)`
/// @param[in] C class name: calls `C(char*)` constructor
/// @param[in] X .yacc token identifier
#define TOKEN(C, X)               \
    {                             \
        yylval.o = new C(yytext); \
        return X;                 \
    }

/// @}
