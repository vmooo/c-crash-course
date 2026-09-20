# c-crash-course

Next are the problem statements. The problems are grouped into thematic modules.

## Module 1. Strings and memory

### own `string.h` library

1. Custom string.h library: Implement the functions without using the standard library (use only pointer arithmetic, no array indexing `[]`):
- `size_t my_strlen(const char *str); `
- `char *my_strcpy(char *dest, const char *src);`
- `char *my_strcat(char *dest, const char *src);`
- `int my_strcmp(const char *s1, const char *s2);` 
- `void *my_memcpy(void *dest, const void *src, size_t n);` 
- `void *my_memset(void *s, int c, size_t n);`
2. String reversal: Write `void reverse_string(char *str);` to reverse the string in-place (without allocating new memory).
3. String parser (mini-strtok): Write a function that takes a string and a delimiter, and returns an array of words (or prints them one by one, like `strtok`).
4. Dynamic array of strings: Read a file line by line (or generate an array of strings in the code) and store them in a `char **`. Don't forget `malloc` and `free`.
