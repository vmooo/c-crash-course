#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void mini_strtok(const char *str, char *delimiter) {

    const char *i = str;
    const char *word_start = NULL;
    size_t word_length = 0;

    while (*i != '\0') {
        char *j = delimiter;

        bool f = false;

        while (*j != '\0') {
            if (*i == *j) {
                f = true;
                if (word_length > 0) {
                    char *word = (char*) malloc((word_length + 1) * sizeof(char));
                    strncpy(word, word_start, word_length);
                    word[word_length] = '\0';
                    printf("%s\n", word);
                    free(word);
                    word_length = 0;
                    word_start = NULL;
                    break;
                }
            }
            ++j;
        }

        if (!f) {
            if (word_start == NULL) {
                word_start = i;
            }
            ++word_length;
        }
        ++i;
    }

    if (word_length > 0) {
        char *word = (char*) malloc((word_length + 1) * sizeof(char));
        strncpy(word, word_start, word_length);
        word[word_length] = '\0';
        printf("%s\n", word);
        free(word);
        word_length = 0;
        word_start = NULL;
    }

}

int main(void) {

    char *str = "Str str trs, ababo";

    mini_strtok(str, " ,");

    return EXIT_SUCCESS;
}