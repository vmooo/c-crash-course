#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>

size_t strlen(const char *str) {
    const char *end_of_str = str;

    while (*end_of_str != '\0') {
        ++end_of_str;
    }

    return (size_t)(end_of_str - str);
}

char *strcpy(char *dest, const char *src) {
    const char *s = src;
    char *d = dest;

    while (*s != '\0') {
        *d = *s;
        ++d;
        ++s;
    }
    *d = '\0';

    return dest;
}

char *strcat(char *dest, const char *src) {
    char *d = dest;
    while (*d) {
        ++d;
    }
    strcpy(d, src);

    return dest;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

void *my_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char*)dest;
    const unsigned char *s = (const unsigned char*)src;

    while (n >= 8) {
        *(uint64_t*)d = *(const uint64_t*)s;

        d += 8;
        s += 8;
        n -= 8;
    }

    while (n > 0) {
        *d = *s;
        ++s;
        ++d;
        --n;
    }

    return dest;
}

void *my_memset(void *dest, int c, size_t n) {
    unsigned char *d = (unsigned char*)dest;

    unsigned char val = (unsigned char)c;

    uint32_t wide_val = ((uint32_t)val << 24) |
                        ((uint32_t)val << 16) |
                        ((uint32_t)val << 8) | val;

    while (n >= 4) {
        *(uint32_t*)d = wide_val;

        d += 4;
        n -= 4;
    }

    while (n > 0) {
        *d = val;
        ++d;
        --n;
    }

    return dest;
}

int main(void) {

    char *str = "Hello";
    assert(strlen(str) == 5);

    char dest[6];
    assert(strcmp(str, strcpy(dest, str)) == 0);

    char dest2[11];
    strcpy(dest2, str);
    assert(strcmp("HelloHello", strcat(dest2, str)) == 0);

    assert(strcmp(str, (char*)my_memcpy((void*)dest, str, 6)) == 0);

    char buf[9];
    my_memset(buf, 'A', 8);
    buf[8] = '\0';
    assert(strcmp("AAAAAAAA", buf) == 0);

    printf("All tests passed!\n");

    return 0;
}