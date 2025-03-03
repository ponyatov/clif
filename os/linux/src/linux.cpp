#include "clif.hpp"

int main(int argc, char *argv[]) { arg(0, argv[0]); }

void arg(int argc, char *argv) {
    fprintf(stderr, "argv[%i] = <%s>\n", argc, argv);
}

void yyerror(char *msg) {
    fprintf(stderr, "\n\n%s:%i %s [%s]\n\n", yyfile, yylineno, msg, yytext);
    exit(-1);
}
