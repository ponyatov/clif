#pragma once

#include "types.hpp"

class Object {
    static void gc();
    bool mark;
    static Object* pool;
    Object* next;
    uint ref;

   public:
    Object();
    virtual ~Object();
    virtual void dump();
};
