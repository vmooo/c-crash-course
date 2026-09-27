#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Absence of nested parentheses:
 * If the arguments passed to the macro themselves contain an operation,
 * its precedence may turn out to be lower than that of the > operator.
 *
 * Absence of outer parentheses:
 * The ternary operator has one of the lowest precedence levels;
 * this can break a macro if it is used within another expression.
 */
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(void) {

    assert(MAX(2, 3) == 3);
    assert(MAX(1 + 2, 2) == 3);

    assert(1 + MAX(1, 2) == 3);

    printf("All tests passed!\n");

    return EXIT_SUCCESS;
}