#pragma once

#include "types.hpp"

/// @defgroup gc gc
/// @ingroup core

class Object {
/// @ingroup core
/// @{
    static void gc();
    bool mark;
    static Object* pool;
    Object* next;
    uint ref;
/// @}

   public:
    /// @brief @ref ref ++
    /// @ingroup gc
    void rc();  
    Object();
    virtual ~Object();
    virtual void dump();
};
