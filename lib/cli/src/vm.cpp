#include "vm.hpp"
#include "libc.hpp"

Object* D[Dsz];
uint Dp = 0;

void dump() {
    printf("\n[ ");
    for (uint i = 0; i < Dp; i++) D[i]->dump();
    printf("\t]\n");
}

void push(Object* o) {
    assert(Dp < Dsz);
    D[Dp++] = o;
    o->rc();
}
