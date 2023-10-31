#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a character exists in a given string
bool containsChar(const char *str, char c) {
    while (*str) {
        if (*str == c) return true;
        str++;
    }
    return false;
}

int main() {
    char text[51], pattern[51];
    scanf("%s %s", text, pattern);

    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int i = 0;
    bool patternFound = false;

    while (i <= textLen - patternLen) {
        bool isMatch = true;

        for (int j = 0; j < patternLen; j++) {
            printf("%c ", text[i + j]);
            if (text[i + j] != pattern[j]) {
                printf("não\n");
                isMatch = false;

                // if the current char in the text is not in the pattern, move i to the next char after current char
                if (!containsChar(pattern, text[i + j])) {
                    i += j + 1;
                    break;
                }

                i++;  // Move to the next character for the next iteration
                break;
            }
        }

        if (isMatch) {
            printf("sim\n");
            printf("Achei o padrão no índice %d\n", i);
            patternFound = true;
            i += patternLen;  // Skip the length of the pattern to prevent unnecessary repeated matching
        }
    }

    if (!patternFound) {
        printf("Não achei o padrão\n");
    }

    return 0;
}
