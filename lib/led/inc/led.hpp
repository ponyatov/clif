/// @defgroup led led
/// @ingroup io
/// @brief LED control
/// @{

#pragma once

#include "object.hpp"
#include "io.hpp"

enum class Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE,
    WHITE,
};

class LED : public Object {
    Color color;
    Pin pin;

   public:
    LED(Color c, Pin p);
    void on();
    void off();
    void toggle();
};

/// @}
