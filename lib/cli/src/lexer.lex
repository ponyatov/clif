%{
    #include "syntax.hpp"
    char *yyfile = nullptr;
%}

%option yylineno noyywrap

s [+\-]
n [0-9]

%%
#[^\n]*     {}              // line comment
[ \t\r\n]+  {}              // drop spaces

{s}{n}+\.{n}+   TOKEN(Num,NUM)  // float
{s}{n}+         TOKEN(Int,INT)  // integer

.           {yyerror("");}  // any undetected char
