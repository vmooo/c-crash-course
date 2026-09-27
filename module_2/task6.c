#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

/**
 * @brief Isolates the Most Significant Bit (MSB) of a 32-bit unsigned telemetry word.
 * @details Utilizes a deterministic, branchless bit-spreading cascade to saturate all
 *          bits to the right of the MSB, followed by a scalar alignment.
 *          Time Complexity: O(1) execution profile, invariant to input bit weight.
 *          Space Complexity: O(1) auxiliary storage.
 * @param[in] value Input data word to be evaluated.
 * @return uint32_t A single-bit mask isolating the highest power of 2 present in the input.
 *                  Returns 0x00000000 if the input word is null.
 */
uint32_t get_msb(uint32_t value) {
    /* Null vector check: if telemetry word contains no active bits, abort execution */
    if (value == 0) return 0;

    /* Cascade Phase: Propagate the MSB dominant state across lower magnitude bits */
    value |= value >> 1;  /* Saturate 2 consecutive bits  */
    value |= value >> 2;  /* Saturate 4 consecutive bits  */
    value |= value >> 4;  /* Saturate 8 consecutive bits  */
    value |= value >> 8;  /* Saturate 16 consecutive bits */
    value |= value >> 16; /* Saturate all 32 bits maximum  */

    /* Isolation Phase: Subtract the shifted replica to eliminate lower magnitude noise.
       This prevents unsigned integer wrap-around (overflow) on maximum scale vectors. */
    return value - (value >> 1);
}

/**
 * @brief Subsystem verification and validation routine.
 * @details Executes a comprehensive test matrix covering boundary conditions, nominal
 *          operational profiles, and maximum scale vectors to guarantee flight readiness.
 * @return EXIT_SUCCESS upon nominal validation of all telemetry criteria.
 */
int main(void) {

    /* --- Test Vector 01: Boundary Condition (Null Input) --- */
    assert(get_msb(0) == 0);

    /* --- Test Vector 02: Unit Values (Exact Powers of Two) --- */
    assert(get_msb(1) == 1);
    assert(get_msb(2) == 2);
    assert(get_msb(4) == 4);
    assert(get_msb(1024) == 1024);

    /* --- Test Vector 03: Nominal Telemetry Profiles (Mixed Bits) --- */
    assert(get_msb(3) == 2);    /* Binary: 0011 -> 0010 */
    assert(get_msb(5) == 4);    /* Binary: 0101 -> 0100 */
    assert(get_msb(12) == 8);   /* Binary: 1100 -> 1000 */
    assert(get_msb(18) == 16);  /* Binary: 00010010 -> 00010000 */
    assert(get_msb(255) == 128);/* Binary: 11111111 -> 10000000 */

    /* --- Test Vector 04: Maximum Scale & Edge Validation --- */
    assert(get_msb(0x80000000) == 0x80000000); /* Highest single bit active */
    assert(get_msb(0xFFFFFFFF) == 0x80000000); /* All bits active (UINT32_MAX) */

    /* --- Telemetry Verification Subsystem Output --- */
    printf("All tests passed!\n");

    return EXIT_SUCCESS;
}
