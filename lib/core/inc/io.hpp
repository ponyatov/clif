/// @defgroup io io
/// @ingroup core
/// @{

#pragma once

#include "object.hpp"

class Pin : public Object {
    uint n;

   public:
    Pin(uint n);
};

/// @}
