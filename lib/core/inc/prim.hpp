#pragma once

#include "object.hpp"

/// @defgroup prim prim
/// @ingroup core
/// @brief scalars/primitives

/// @ingroup prim
/// @brief signed integer number
class Int : public Object {
    int value;

   public:
    Int(char* s);
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
