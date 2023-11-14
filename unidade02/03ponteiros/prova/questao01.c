#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int numeros[100];
    int tamanho;
} conjunto;

bool existe(conjunto c, int num) {
    for (int i = 0; i < c.tamanho; i++) {
        if (c.numeros[i] == num) {
            return true;
        }
    }
    return false;
}

conjunto uniao(conjunto *A, conjunto *B) {
    conjunto C = { {}, 0 };

    for (int i = 0; i < A->tamanho; i++) {
        if (!existe(C, A->numeros[i])) {
            C.numeros[C.tamanho++] = A->numeros[i];
        }
    }

    for (int i = 0; i < B->tamanho; i++) {
        if (!existe(C, B->numeros[i])) {
            C.numeros[C.tamanho++] = B->numeros[i];
        }
    }

    return C;
}

conjunto intersecao(conjunto *A, conjunto *B) {
    conjunto C = { {}, 0 };

    for (int i = 0; i < B->tamanho; i++) {
        if (existe(*A, B->numeros[i]) && !existe(C, B->numeros[i])) {
            C.numeros[C.tamanho++] = B->numeros[i];
        }
    }

    return C;
}





int main() {
    conjunto A, B;

    scanf("%d", &A.tamanho);
    for (int i = 0; i < A.tamanho; i++) {
        scanf("%d", &A.numeros[i]);
    }

    scanf("%d", &B.tamanho);
    for (int i = 0; i < B.tamanho; i++) {
        scanf("%d", &B.numeros[i]);
    }

    conjunto C1 = uniao(&A, &B);
    conjunto C2 = intersecao(&A, &B);

    printf("A união B == {");
    if (C1.tamanho == 0) {
        printf("vazio");
    } else {
        for (int i = 0; i < C1.tamanho; i++) {
            printf("%d", C1.numeros[i]);
            if (i != C1.tamanho - 1) {
                printf(" ");
            }
        }
    }
    printf("}\n");

    printf("A interseção B == {");
    if (C2.tamanho == 0) {
        printf("vazio");
    } else {
        for (int i = 0; i < C2.tamanho; i++) {
            printf("%d", C2.numeros[i]);
            if (i != C2.tamanho - 1) {
                printf(" ");
            }
        }
    }
    printf("}\n");

    return 0;
}
