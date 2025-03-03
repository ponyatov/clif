#pragma once

#include "core.hpp"

#define Dsz 0x10

extern Object* D[Dsz];
extern uint Dp;

extern void push(Object*);
extern Object* pop();

extern void nop();
extern void halt();

extern void dump();
