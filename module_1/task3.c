#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Allocates memory, copies, and prints a single word token.
 *
 * Safely creates a null-terminated local copy of the specified substring
 * to ensure that the output operation does not cause out-of-bounds reads.
 *
 * @param start Pointer to the beginning of the word in the source string.
 * @param length The exact number of characters in the word.
 * @return void
 */
void print_word(const char *start, size_t length) {
    /* Defensive check against invalid arguments or empty words */
    if ((length == 0U) || (start == NULL)) {
        return;
    }

    /* Allocate buffer with explicit space for the trailing null character */
    char *word = (char*) malloc((length + 1U) * sizeof(char));

    /* Verify dynamic memory allocation success before dereferencing */
    if (word != NULL) {
        (void) strncpy(word, start, length);
        word[length] = '\0'; /* Ensure strict null-termination */

        (void) printf("%s\n", word);

        free(word); /* Prevent memory leaks by freeing the heap immediately */
    }
} /* end of print_word */

/**
 * @brief Tokenizes a string based on a set of delimiter characters.
 *
 * Scans the source string character by character. When a delimiter is
 * encountered, the accumulated word is printed. Operates non-destructively
 * on the input string.
 *
 * @param str The read-only source string to be tokenized.
 * @param delimiter The read-only string containing valid separator characters.
 * @return void
 */
void mini_strtok(const char *str, const char *delimiter) {
    const char *i = str;
    const char *word_start = NULL;
    size_t word_length = 0U;

    /* Main scanning loop over the source text */
    while (*i != '\0') {
        const char *j = delimiter;
        bool f = false;

        /* Check the current character against all registered delimiters */
        while (*j != '\0') {
            if (*i == *j) {
                f = true;

                /* Delimiter hit: process and print the completed word token */
                if (word_length > 0U) {
                    print_word(word_start, word_length);
                    word_length = 0U;
                    word_start = NULL;
                }
                break; /* Halt delimiter search as match is already verified */
            }
            ++j;
        } /* end of delimiter evaluation loop */

        /* If the character is not a delimiter, accumulate it into the word */
        if (!f) {
            if (word_start == NULL) {
                word_start = i; /* Mark the starting boundary of the new word */
            }
            ++word_length;
        }
        ++i;
    } /* end of main scanning loop */

    /* Flush and print the final word if the string did not end with a delimiter */
    if (word_length > 0U) {
        print_word(word_start, word_length);
    }
} /* end of mini_strtok */

/**
 * @brief Application entry point.
 *
 * Demonstrates the string tokenization routine using static mission data.
 *
 * @param void
 * @return int Standard execution status identifier.
 */
int main(void) {
    /* Source string resides in read-only memory segment */
    const char *str = "Str str trs, ababo";

    /* Parse string using space and comma as valid boundaries */
    mini_strtok(str, " ,");

    return EXIT_SUCCESS;
} /* end of main */
