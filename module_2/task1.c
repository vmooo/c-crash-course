#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @brief Computes the population count (hamming weight) using a linear bit-shift approach.
 * @details Iterates through all bits via logical right shifts. Time complexity is
 *          proportional to the position of the highest set bit: O(N) where N is bit width.
 * @param[in] number Input telemetry or data word.
 * @return int Total count of active (1) bits.
 * @note This implementation relies on undefined behavior if a negative integer is passed,
 *       due to sign-extension during right shifts on signed types.
 */
int naive_popcount(int number) {
    int ans = 0;
    while (number) {
        /* Verify LSB status via bitwise AND mask */
        if (number & 0b1) {
            ++ans;
        }
        /* Shift right to process the next bit magnitude */
        number >>= 1;
    }
    return ans;
}

/**
 * @brief Computes the population count using Brian Kernighan’s optimization algorithm.
 * @details Clears the lowest set bit in each iteration using the expression (X & (X - 1)).
 *          Execution profile is strictly deterministic relative to weight: O(K) where K
 *          is the number of set bits. Highly efficient for sparse bitmasks.
 * @param[in] number Input telemetry or data word.
 * @return int Total count of active (1) bits.
 */
int popcount(int number) {
    int ans = 0;
    while (number) {
        /* Subtraction isolates and clears the least significant set bit */
        number &= number - 1;
        ++ans;
    }
    return ans;
}

/**
 * @brief Subsystem verification and validation routine.
 * @details Executes deterministic test vectors to validate popcount algorithm performance
 *          against flight software specifications.
 * @return EXIT_SUCCESS upon nominal validation of all criteria.
 */
int main(void) {

    /* --- Verification Phase: Naive Implementation Baseline --- */
    assert(naive_popcount(4) == 1);
    assert(naive_popcount(5) == 2);

    /* --- Verification Phase: Optimized Kernighan Algorithm --- */
    assert(popcount(4) == 1);
    assert(popcount(5) == 2);

    /* --- Telemetry Output --- */
    printf("All tests passed!\n");

    return EXIT_SUCCESS;
}
