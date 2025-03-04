#include "prim.hpp"
#include "libc.hpp"

Int::Int(int n) : Object(), value(n) {}
Int::Int(char *s) : Int(atoi(s)) {}

void Int::dump() { printf("<int:%i> @%p\t", value, this); }

// Hex @ hex.ragel
// Oct @ oct.ragel
// Bin @ bin.ragel

Num::Num(char *s) : Object(), value(atof(s)) {}

void Num::dump() { printf("<num:%f> @%p\t", value, this); }
