#include "object.hpp"
#include "libc.hpp"

Object* Object::pool = nullptr;

Object::Object() {
    ref = 0;
    next = pool;
    pool = this;
    mark = false;
}

Object::~Object() { assert(!ref); }

void Object::rc() { ref++; }

void Object::dump() { printf("<object:> @%p\n", this); }
