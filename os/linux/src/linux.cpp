#include "clif.hpp"
#include "main.hpp"
#include "libc.hpp"
#include "syntax.hpp"

int main(int argc, char *argv[]) {
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {
        arg(i, argv[i]);
        yyfile = argv[i];
        assert(yyin = fopen(yyfile, "r"));
        fclose(yyin);
        yyfile = nullptr;
    }
}

void arg(int argc, char *argv) {
    fprintf(stderr, "argv[%i] = <%s>\n", argc, argv);
}

void yyerror(char *msg) {
    fprintf(stderr, "\n\n%s:%i %s [%s]\n\n", yyfile, yylineno, msg, yytext);
    exit(-1);
}
