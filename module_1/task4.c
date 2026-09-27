#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    /* --- Configuration and Resource Initialization --- */
    const char *filename = "data.txt";

    /* Open the input file in read-only text mode */
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        /* Defensive check: Log file access failure with location telemetry */
        fprintf(stderr, "fopen() failed in file %s at line #%d", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    /* --- Dynamic Memory Allocation Setup --- */
    size_t capacity = 16U; /* Initial capacity for the line pointer array */
    size_t count = 0U;    /* Current number of successfully stored lines */

    /* Allocate memory for the initial array of string pointers */
    char **lines = malloc(capacity * sizeof(char*));
    char buffer[1024];     /* Static buffer for staging line reads */

    /* --- File Processing Loop --- */
    /* Read the file sequentially until End-Of-File (EOF) or read error */
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {

        /* Check if the pointer array has reached its storage capacity */
        if (count >= capacity) {
            /* Double the capacity using a bitwise shift for efficiency */
            capacity <<= 1;

            /* Attempt to reallocate memory to accommodate the new capacity */
            char **tmp = realloc(lines, capacity * sizeof(char*));
            if (tmp == NULL) {
                /* Memory exhaustion recovery: free all allocated lines and exit */
                fprintf(stderr, "realloc() failed");
                for (size_t i = 0L; i < count; ++i) {
                    free(lines[i]);
                }
                free(lines);
                fclose(fp); /* Ensure file descriptor is not leaked on failure */
                exit(EXIT_FAILURE);
            }
            lines = tmp;
        }

        /* Duplicate the staged buffer into dynamically allocated memory */
        lines[count] = strdup(buffer);
        ++count;
    }

    /* --- Output Processing and Cleanup --- */
    /* Stream all stored lines to the standard output */
    for (size_t i = 0U; i < count; ++i) {
        printf("%s", lines[i]);
    }

    /* Release resource locks and free dynamically allocated memory blocks */
    fclose(fp);

    for (size_t i = 0U; i < count; ++i) {
        free(lines[i]);
    }
    free(lines);

    printf("Allright\n");
    return EXIT_SUCCESS;
}
