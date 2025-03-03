#pragma once

#include "types.hpp"

/// @defgroup gc gc
/// @ingroup core
/// @brief Garbage Collector

/// @brief root class for all objects
/// @ingroup core
class Object {
    /// @ingroup gc
    /// @{
    bool mark;            ///< marked object in @ref gc
    static Object* pool;  ///< global object @ref pool
    Object* next;         ///< next object in linked list

    /// @}

   public:
    /// @ingroup gc
    /// @{
    static void gc();  ///< single @ref gc pass
    uint ref;          ///< reference counter
    /// @}

    Object();
    virtual ~Object();
    virtual void dump();
};
