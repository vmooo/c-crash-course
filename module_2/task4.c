#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

uint32_t swap_endian(uint32_t value) {
    return ((value >> 24) & 0x000000FF) |
           ((value >> 8) & 0x0000FF00)  |
           ((value << 8) & 0x00FF0000)  |
           ((value << 24) & 0xFF000000);
}

int main() {

    assert(swap_endian(0x01234567U) == 0x67452301U);
    assert(swap_endian(0xAAAAFFFFU) == 0xFFFFAAAAU);

    printf("All tests passed!\n");

    return EXIT_SUCCESS;
}