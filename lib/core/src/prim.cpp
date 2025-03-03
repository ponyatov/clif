#include "prim.hpp"
#include "libc.hpp"

Int::Int(char *s) : Object(), value(atoi(s)) {}

void Int::dump() { printf("<int:%i> @%p\n", value, this); }

Num::Num(char *s) : Object(), value(atof(s)) {}

void Num::dump() { printf("<num:%f> @%p\n", value, this); }
