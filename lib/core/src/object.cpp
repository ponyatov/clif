#include "object.hpp"
#include "libc.hpp"
#include "vm.hpp"

Object* Object::pool = nullptr;

Object::Object() {
    ref = 0;
    next = pool;
    pool = this;
    mark = false;
}

Object::~Object() { assert(ref == 0); }

void Object::dump() { printf("<object:> @%p\n", this); }

void Object::gc() { assert(!Dp); }
