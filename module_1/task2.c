#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void swap(char *c1, char *c2) {
    char buf = *c1;
    *c1 = *c2;
    *c2 = buf;
}

void reverse_string(char *str) {
    char *l = str;
    char *r = str;

    while (*r != '\0') {
        ++r;
    }
    --r;

    while (l < r) {
        swap(l, r);
        ++l;
        --r;
    }
}

int main(void) {

    char c1 = 'A';
    char c2 = 'B';
    swap(&c1, &c2);
    assert(c1 == 'B');

    char str[] = "ABCDF";
    reverse_string(str);
    assert(strcmp(str, "FDCBA") == 0);

    printf("All tests passed!\n");

    return EXIT_SUCCESS;
}