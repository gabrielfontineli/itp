#include <stdio.h>
#include <stdlib.h>

// Função comparativa para o qsort()
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, i;
    int numbers[1000]; // Supondo um limite máximo de 1000 números, ajuste conforme necessário.

    // Lê a linha e salva quantos números foram lidos
    n = 0;
    while (scanf("%d", &numbers[n]) == 1) {
        n++;
    }

    // Ordena os números
    qsort(numbers, n, sizeof(int), compare);

    // Imprime os números ordenados
    for (i = 0; i < n; i++) {
        printf("%d", numbers[i]);
        if (i < n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    return 0;
}
