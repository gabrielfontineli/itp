#include <stdio.h>
#include <string.h>

int starts_with(const char *str, const char *prefix) {
    while (*prefix) {
        if (*prefix++ != *str++) {
            return 0;
        }
    }
    return 1;
}

int ends_with(const char *str, const char *suffix) {
    str += strlen(str) - strlen(suffix);
    while (*suffix) {
        if (*suffix++ != *str++) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N, M;
    char prefix[10][11];
    char suffix[10][11];
    char word[101];
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", prefix[i]);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%s", suffix[i]);
    }

    while (1) {
        scanf("%s", word);
        if (strcmp(word, "-1") == 0) {
            break;
        }

        // Remove prefix
        for (int i = 0; i < N; i++) {
            if (starts_with(word, prefix[i])) {
                memmove(word, word + strlen(prefix[i]), strlen(word) - strlen(prefix[i]) + 1);
                break;
            }
        }

        // Remove suffix
        for (int i = 0; i < M; i++) {
            if (ends_with(word, suffix[i])) {
                word[strlen(word) - strlen(suffix[i])] = '\0';
                break;
            }
        }

        if (strlen(word) > 0) {
            printf("%s\n", word);
        }
    }

    return 0;
}
