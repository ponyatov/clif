/// @defgroup discovery discovery
/// @ingroup hw
/// @defgroup f4disco f4disco
/// @ingroup discovery
/// @brief `cpu:` @ref stm32f407vgt 6
/// - https://www.st.com/en/evaluation-tools/stm32f4discovery.html
/// - https://www.chipdip.ru/product/stm32f407g-disc1-2
///
/// ![](https://static.chipdip.ru/lib/485/DOC001485849.jpg)
///
/// @{
#pragma once

#include "led.hpp"

/// @name LEDs
/// @{
extern LED LD1;  ///< LD1 (red/green) for USB communication
extern LED LD2;  ///< LD2 (red) for 3.3 V power on
extern LED LD3;  ///< LD3 (orange)
extern LED LD4;  ///< LD4 (green)
extern LED LD5;  ///< LD5 (red)
extern LED LD6;  ///< LD6 (blue)
/// @}

/// @}
