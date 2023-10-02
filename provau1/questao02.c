/*
Escreva um programa que leia um valor inteiro n. Em seguida leia uma matriz quadrada n x n. Crie uma função para receber a matriz lida e imprimir suas linhas, colunas e diagonais. Primeiro imprima as linhas, de cima para baixo. Depois imprima as colunas, da esquerda para a direita. Por fim imprima as diagonais primeira e secundária.

Exemplo:  

Entrada:

2

1 5

3 4

Saída:

1 5

3 4

1 3

5 4

1 4

5 3
Exemplo de entrada	
2
1 2
3 4	
Exemplo de saída
1 2
3 4
1 3
2 4
1 4
2 3
Exemplo de entrada
3
1 2 3
4 5 6
7 8 9	
Exemplo de saida
1 2 3
4 5 6
7 8 9
1 4 7
2 5 8
3 6 9
1 5 9
3 5 7
*/

#include <stdio.h>


void imprimirLinhas(int matriz[][100], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("%d\n", matriz[i][N - 1]);
    }
}

void imprimirColunas(int matriz[][100], int N) {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N - 1; i++) {
            printf("%d ", matriz[i][j]);
        }
        printf("%d\n", matriz[N - 1][j]);
    }
}

void imprimirDiagonais(int matriz[][100], int N) {
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", matriz[i][i]);
    }
    printf("%d\n", matriz[N - 1][N - 1]);
    
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", matriz[i][N - 1 - i]);
    }
    printf("%d\n", matriz[N - 1][0]);
}

void lerMatriz(int matriz[][100], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    int matriz[100][100];
    lerMatriz(matriz, N);
    imprimirLinhas(matriz, N);
    imprimirColunas(matriz, N);
    imprimirDiagonais(matriz, N);
    
    return 0;
}
