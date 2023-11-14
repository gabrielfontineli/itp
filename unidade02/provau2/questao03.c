#include <stdio.h>

int comb(int n, int p) {
    if (p == 0 || p == n) {
        return 1;
    }
    if (p == 1) {
        return n;
    }
    return comb(n - 1, p - 1) + comb(n - 1, p);
}

int main() {
    int N, P, resultado;

    if (scanf("%d %d", &N, &P) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    if (P > N || N < 0 || P < 0) {
        printf("Invalid values for N and P.\n");
        return 1;
    }

    resultado = comb(N, P);

    printf("%d\n", resultado);

    return 0;
}
