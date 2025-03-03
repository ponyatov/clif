#pragma once

#include "object.hpp"

class Int : public Object {
    int value;

   public:
    Int(char* s);
    void dump();
};
