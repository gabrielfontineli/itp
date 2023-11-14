#include <stdio.h>

void converteParaBinario(int n) {
    if (n == 0) {
        return;
    }

    converteParaBinario(n / 2);
    printf("%d", n % 2);
}

int main() {
    int numero;

    scanf("%d", &numero);

    if (numero < 0) {
        printf("Número inválido. Por favor, digite um número não negativo.\n");
    } else {
        if (numero == 0) { // Caso especial para o número 0
            printf("0");
        } else {
            converteParaBinario(numero);
        }
        printf("\n");
    }

    return 0;
}
