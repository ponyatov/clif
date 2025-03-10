#include "clif.hpp"
// #include <stm32f4xx_hal.h>
#include "usbd_cdc_if.h"

extern "C" void setup(void) {}

uint8_t buf[0x100];
int n = 0;

extern "C" int __io_putchar(int ch) {
    //     uint8_t c = ch;
    //     CDC_Transmit_FS(&c, 1);
    return ch;
}

extern "C" void loop(void) {
    sprintf((char*)buf, "Hello, %i\n", n++);
    printf("Hello, %i\n", n++);
    CDC_Transmit_FS(buf, strlen((char*)buf));
    HAL_Delay(2222);
}
