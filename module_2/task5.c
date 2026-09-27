#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

uint32_t setn(uint32_t reg, int n) {
    return reg | (1U << n);
}

uint32_t resetn(uint32_t reg, int n) {
    return reg & ~(1U << n);
}

uint32_t invertn(uint32_t reg, int n) {
    return reg ^ (1U << n);
}

uint32_t checkn(uint32_t reg, int n) {
    return reg & (1U << n);
}

int main(void) {

    uint32_t reg = 0b1010;

    assert(setn(reg, 0) == 0b1011);
    assert(setn(reg, 1) == 0b1010);

    assert(resetn(reg, 1) == 0b1000);
    assert(resetn(reg, 0) == 0b1010);

    assert(invertn(reg, 0) == 0b1011);
    assert(invertn(reg, 1) == 0b1000);

    assert(checkn(reg, 1) != 0);
    assert(checkn(reg, 0) == 0);

    printf("All tests passed!\n");

    return 0;
}