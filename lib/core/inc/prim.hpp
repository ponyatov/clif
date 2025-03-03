#pragma once

#include "object.hpp"

class Int : public Object {
    int value;

   public:
    Int(char* s);
    void dump();
};

class Num : public Object {
    float value;

   public:
    Num(char* s);
    void dump();
};
