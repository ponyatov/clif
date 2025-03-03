#pragma once

#include "types.hpp"

class Object {
    static void gc();
    bool mark;
    static Object* pool;
    Object* next;
    uint ref;

   public:
    void rc(); //< @ref ref ++
    Object();
    virtual ~Object();
    virtual void dump();
};
