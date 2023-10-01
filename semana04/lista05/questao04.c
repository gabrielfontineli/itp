#include <stdio.h>

void imprimir_piramide(int N) {
    int matriz[N][N];
    
    // Inicializar toda a matriz com zeros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = 0;
        }
    }
    
    int camada = 1;
    for (int inicio = 0, fim = N - 1; inicio <= fim; inicio++, fim--, camada++) {
        for (int i = inicio; i <= fim; i++) {
            for (int j = inicio; j <= fim; j++) {
                matriz[i][j] = camada;
            }
        }
    }

    // Imprimir a matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", matriz[i][j]);
            if (j != N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);
    imprimir_piramide(N);
    return 0;
}
