#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int conjuntoA[N], conjuntoB[M];
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &conjuntoA[i]);
    }
    
    for(int i = 0; i < M; i++) {
        scanf("%d", &conjuntoB[i]);
    }

    int resultado[N + M]; 
    int tamanhoResultado = 0;

    for(int i = 0; i < N; i++) {
        int elemento = conjuntoA[i];
        int pertenceConjuntoB = 0;

        for(int j = 0; j < M; j++) {
            if(conjuntoB[j] == elemento) {
                pertenceConjuntoB = 1;
                break;
            }
        }

        if(!pertenceConjuntoB) {
            resultado[tamanhoResultado++] = elemento;
        }
    }

    for(int i = 0; i < M; i++) {
        int elemento = conjuntoB[i];
        int pertenceConjuntoA = 0;

        for(int j = 0; j < N; j++) {
            if(conjuntoA[j] == elemento) {
                pertenceConjuntoA = 1;
                break;
            }
        }

        if(!pertenceConjuntoA) {
            resultado[tamanhoResultado++] = elemento;
        }
    }

    for(int i = 0; i < tamanhoResultado-1; i++) {
        for(int j = 0; j < tamanhoResultado-i-1; j++) {
            if(resultado[j] > resultado[j+1]) {
                int temp = resultado[j];
                resultado[j] = resultado[j+1];
                resultado[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < tamanhoResultado; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
