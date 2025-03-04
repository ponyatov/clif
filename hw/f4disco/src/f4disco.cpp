#include "f4disco.hpp"

/// - LEDs
///   - LD1 (red/green) for USB communication
///   - LD2 (red) for 3.3 V power on
///   - LD3 (orange)
///   - LD4 (green)
///   - LD5 (red)
///   - LD6 (blue)

LED LD1(Color::GREEN, 1);
LED LD2(Color::RED, 2);
LED LD3(Color::ORANGE, 3);
LED LD4(Color::GREEN, 4);
LED LD5(Color::RED, 5);
LED LD6(Color::BLUE, 6);
