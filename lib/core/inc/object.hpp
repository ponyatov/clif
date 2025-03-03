#pragma once

#include "types.hpp"

class Object {
    static void gc();
    static Object* pool;
    Object* next;
    uint ref;
};
