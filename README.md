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

## Module 2: Bitwise Arithmetic 

1. Popcount: Write a function `int count_set_bits(unsigned int x)` that counts the number of set bits (1s) in a number. Implement this in two ways: a naive loop and Brian Kernighan's algorithm (`x &= (x - 1)`).
2. Power of Two Check: Write `int is_power_of_two(unsigned int x)`. (Hint: `x && !(x & (x - 1))`).
3. Nibble Swap: Swap the high 4 bits and the low 4 bits of a byte (e.g., `0xAB` -> `0xBA`).
4. Endianness Swap: Write a function `uint32_t swap_endian(uint32_t val)` that swaps the byte order (Little-endian to Big-endian and vice versa).
5. Register Manipulation (Simulation): Given a `uint32_t reg`, write macros/functions to: 
   - Set bit N to 1. 
   - Clear bit N to 0. 
   - Toggle bit N. 
   - Check if bit N is set.
6. Find Most Significant Bit: Write a function that finds the position of the highest set bit (MSB).