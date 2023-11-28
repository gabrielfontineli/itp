#include "input_helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Safely read a line of text from standard input
int getLine(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        return 0; // Failure or end-of-file
    }

    // Remove newline character if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    return 1; // Success
}

// Read an integer from standard input
int getInt(int *value) {
    char buffer[50];
    if (getLine(buffer, sizeof(buffer))) {
        *value = atoi(buffer);
        return 1; // Success
    }
    return 0; // Failure
}

// Additional helper functions can be added here as needed
