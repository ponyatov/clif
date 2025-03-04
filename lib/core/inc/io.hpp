/// @defgroup io io
/// @ingroup core
/// @{

#pragma once

#include "object.hpp"

class Pin : public Object {
    uint pin;

   public:
    Pin(uint pin);
};

/// @}
