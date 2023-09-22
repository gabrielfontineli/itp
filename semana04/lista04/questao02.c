#include <stdio.h>

// Função para verificar se um elemento pertence a um conjunto
int pertence(int valor, int conjunto[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (conjunto[i] == valor) {
            return 1; // O elemento pertence ao conjunto
        }
    }
    return 0; // O elemento não pertence ao conjunto
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int conjuntoA[N], conjuntoB[M];

    // Lendo os valores do conjunto A
    for (int i = 0; i < N; i++) {
        scanf("%d", &conjuntoA[i]);
    }

    // Lendo os valores do conjunto B
    for (int i = 0; i < M; i++) {
        scanf("%d", &conjuntoB[i]);
    }

    // Encontrando a interseção e imprimindo os resultados
    int intersecao[N + M];
    int tamanhoIntersecao = 0;

    for (int i = 0; i < N; i++) {
        if (pertence(conjuntoA[i], conjuntoB, M)) {
            intersecao[tamanhoIntersecao] = conjuntoA[i];
            tamanhoIntersecao++;
        }
    }

    // Imprimindo a interseção
    for (int i = 0; i < tamanhoIntersecao; i++) {
        printf("%d ", intersecao[i]);
    }

    return 0;
}