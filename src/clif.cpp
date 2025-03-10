#include "clif.hpp"
#ifdef STM32F4
#include <stm32f4xx_hal.h>
#endif
#include "usbd_cdc_if.h"

extern "C" void setup(void) {}

uint8_t buf[0x100];
int n = 0;

extern "C" int __io_putchar(int ch) {
    uint8_t c = ch;
    CDC_Transmit_FS(&c, 1);
    ITM_SendChar(ch);
    return ch;
}

extern "C" int _write(int file, char *ptr, int len) {
    CDC_Transmit_FS((uint8_t *)ptr, len);
    for (int i = 0; i < len; i++) ITM_SendChar(*ptr++);
    return len;
}

extern "C" _ssize_t _write_r(struct _reent *ptr, int fd, const void *buf,
                             size_t cnt) {
    return _write(fd,(char*)buf,cnt);
}

extern "C" void loop(void) {
    sprintf((char *)buf, "Hello, %i\n", n++);
    // printf("Hello, %i\n", n++);
    CDC_Transmit_FS(buf, strlen((char *)buf));
    putchar('A');
    // __io_putchar('A');
    HAL_Delay(2222);
}
