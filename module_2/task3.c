#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

uint8_t nibble_swap(uint8_t byte) {
    uint8_t low_nibble = byte & 0x0F;
    low_nibble <<= 4;
    byte >>= 4;
    byte += low_nibble;
    return byte;

    // return (byte >> 4) | (byte << 4);
}

int main(void) {

    assert(nibble_swap(0xAB) == 0xBA);

    printf("All tests passed!\n");

    return EXIT_SUCCESS;
}