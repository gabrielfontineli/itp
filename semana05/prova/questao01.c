#include <stdio.h>
#include <string.h>

const char S[] =
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};

int getIndexOfChar(char c) {
    for (int i = 0; i < 40; i++) {
        if (S[i] == c) {
            return i;
        }
    }
    return -1;
}

int isValidMessage(char P[]) {
    int len = strlen(P);
    for (int i = 0; i < len; i++) {
        if (getIndexOfChar(P[i]) == -1) {
            return 0;
        }
    }
    return 1;
}

void vigenereCipher(char P[], char K[], char C[]) {
    int len = strlen(P);
    for (int i = 0; i < len; i++) {
        int indexP = getIndexOfChar(P[i]);
        int indexK = K[i % 4] - '0';

        int indexC = (indexP + indexK) % 40;
        C[i] = S[indexC];
    }
    C[len] = '\0';
}

int main() {
    char K[5], P[201], C[201];

    scanf("%s", K);
    getchar();  // to consume the newline
    fgets(P, 201, stdin);
    P[strcspn(P, "\n")] = 0;  // remove the newline

    if (strlen(K) != 4) {
        printf("Chave invalida!\n");
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (K[i] < '0' || K[i] > '9') {
            printf("Chave invalida!\n");
            return 0;
        }
    }

    if (!isValidMessage(P)) {
        printf("Caractere invalido na entrada!\n");
        return 0;
    }

    vigenereCipher(P, K, C);
    printf("%s\n", C);

    return 0;
}
