#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int is_power_of_two(int number) {
    return number && !(number & (number - 1));
}

int main(void) {

    assert(is_power_of_two(2) == 1);
    assert(is_power_of_two(4) == 1);
    assert(is_power_of_two(8) == 1);
    assert(is_power_of_two(16) == 1);
    assert(is_power_of_two(0) == 0);
    assert(is_power_of_two(5) == 0);
    assert(is_power_of_two(6) == 0);

    printf("All tests passed\n");

    return EXIT_SUCCESS;
}