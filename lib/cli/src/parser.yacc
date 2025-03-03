%{
    #include "syntax.hpp"
%}

%defines %union { Object *o; }

%token<o> INT NUM
%type<o>  ex

%%

syntax: | syntax ex { $2->dump(); }

ex : INT
   | NUM
