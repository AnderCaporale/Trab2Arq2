#include "logic_arithmetic.h"
#include "inttypes.h"

uint16_t masks[] = {0x00, 0xffff};

uint16_t logicAdd(uint16_t first, uint16_t second, int* overflow) {
    int a;
    int b;
    int carry;
    carry = 0;

    uint16_t res = 0;

    for (int i = 0; i < 16; ++i) {
        a = first >> i & 1;
        b = second >> i & 1;

        res |= (((a ^ b) ^ carry) << i);
        carry = (a & b) | ((a ^ b) & carry);
    }

    if (carry)
        *overflow = 1;

    return res;
}

uint16_t logicSub(uint16_t first, uint16_t second) {
    int a;
    int b;
    int borrow;
    borrow = 0;

    uint16_t res = 0;

    for (int i = 0; i < 16; ++i) {
        a = first >> i & 1;
        b = second >> i & 1;

        res |= (((a ^ b) ^ borrow) << i);
        borrow = ((~a) & b) | ((~(a ^ b)) & borrow);
    }

    return res;
}

uint16_t logicMul(uint16_t first, uint16_t second, int* overflow) {
    uint16_t result = 0;

    for (int shift = 0; shift < 16; ++shift) {
        if (first << (shift-1) & 0x8000)
            *overflow = 1;
        result = logicAdd(result, (first << shift) & masks[(second >> shift) & 1], overflow);
    }

    return result;
}

uint16_t logicDiv(uint16_t first, uint16_t second) {
    uint16_t result = 0;

    for (int shift = 15; shift >= 0; --shift) {
        if (first >= (second << shift)) {
            first = logicSub(first, second << shift);
            result |= 1 << shift;
        }
    }

    return result;
}

uint16_t logicMod(uint16_t first, uint16_t second) {
    for (int shift = 15; shift >= 0; --shift) {
        if (first >= (second << shift))
            first = logicSub(first, second << shift);
    }

    return first;
}