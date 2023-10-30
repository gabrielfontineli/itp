// falta fazer

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int valores[MAX_SIZE];
    int tamanho;
} conjunto;

bool contem(conjunto *c, int valor) {
    for(int i = 0; i < c->tamanho; i++) {
        if(c->valores[i] == valor) return true;
    }
    return false;
}

conjunto uniao(conjunto *A, conjunto *B) {
    conjunto result;
    result.tamanho = 0;

    for(int i = 0; i < A->tamanho; i++) {
        if(!contem(&result, A->valores[i])) {
            result.valores[result.tamanho++] = A->valores[i];
        }
    }
    
    for(int i = 0; i < B->tamanho; i++) {
        if(!contem(&result, B->valores[i])) {
            result.valores[result.tamanho++] = B->valores[i];
        }
    }

    // Ordenação
    for(int i = 0; i < result.tamanho - 1; i++) {
        for(int j = i + 1; j < result.tamanho; j++) {
            if(result.valores[i] > result.valores[j]) {
                int temp = result.valores[i];
                result.valores[i] = result.valores[j];
                result.valores[j] = temp;
            }
        }
    }

    return result;
}

conjunto intersecao(conjunto *A, conjunto *B) {
    conjunto result;
    result.tamanho = 0;

    for(int i = 0; i < A->tamanho; i++) {
        if(contem(B, A->valores[i]) && !contem(&result, A->valores[i])) {
            result.valores[result.tamanho++] = A->valores[i];
        }
    }

    return result; // Não é necessário ordenar a interseção pois ela já estará em ordem devido ao modo como foi construída.
}

int main() {
    conjunto A, B;

    // Leitura do conjunto A
    scanf("%d", &A.tamanho);
    for(int i = 0; i < A.tamanho; i++) {
        scanf("%d", &A.valores[i]);
    }

    // Leitura do conjunto B
    scanf("%d", &B.tamanho);
    for(int i = 0; i < B.tamanho; i++) {
        scanf("%d", &B.valores[i]);
    }

    conjunto un = uniao(&A, &B);
    conjunto inter = intersecao(&A, &B);

    // Imprimindo união
    printf("A união B == {");
    for(int i = 0; i < un.tamanho; i++) {
        printf("%d", un.valores[i]);
        if(i < un.tamanho - 1) printf(" ");
    }
    printf("}\n");

    // Imprimindo interseção
    printf("A interseção B == {");
    for(int i = 0; i < inter.tamanho; i++) {
        printf("%d", inter.valores[i]);
        if(i < inter.tamanho - 1) printf(" ");
    }
    printf("}\n");

    return 0;
}
