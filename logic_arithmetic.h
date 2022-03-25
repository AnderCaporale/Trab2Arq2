#ifndef TRAB2ARQ2_LOGIC_ARITHMETIC_H
#define TRAB2ARQ2_LOGIC_ARITHMETIC_H

#include "inttypes.h"

uint16_t logicAdd(uint16_t first, uint16_t second, int* overflow);

uint16_t logicSub(uint16_t first, uint16_t second);

uint16_t logicMul(uint16_t first, uint16_t second, int* overflow);

uint16_t logicDiv(uint16_t first, uint16_t second);

uint16_t logicMod(uint16_t first, uint16_t second);

#endif //TRAB2ARQ2_LOGIC_ARITHMETIC_H
