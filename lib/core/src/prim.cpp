#include "prim.hpp"
#include "libc.hpp"

Int::Int(char *s) : Object(),value(atoi(s)) {}

void Int::dump() { printf("<int:%i> @%p\n", value, this); }
