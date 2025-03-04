#pragma once

#include "object.hpp"

/// @defgroup prim prim
/// @ingroup core
/// @brief primitive/scalar

/// @ingroup prim
/// @brief signed integer number
class Int : public Object {
   protected:
    int value;

   public:
    Int(char* s);
    Int(int n);
    void dump();
};

class Hex : public Int {
   public:
    Hex(char* s);
    void dump();
};

/// @ingroup prim
/// @brief floating point number
class Num : public Object {
    float value;

   public:
    Num(char* s);
    void dump();
};
