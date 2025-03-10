#include "main.hpp"
#include "parser.hpp"
#include "vm.hpp"

#ifndef BARE
__attribute__((weak)) int main(int argc, char *argv[]) {
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {
        arg(i, argv[i]);
        yyfile = argv[i];
        assert(yyin = fopen(yyfile, "r"));
        yyparse();
        fclose(yyin);
        yyfile = nullptr;
        dot();
    }
}
#endif  // BARE

__attribute__((weak)) void arg(int argc, char *argv) {
    fprintf(stderr, "argv[%i] = <%s>\n", argc, argv);
}

// __attribute__((weak)) void setup(void) {}
__attribute__((weak)) void loop(void) {}
