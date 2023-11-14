/*
Escreva uma função somaFat , que recebe dois números inteiros x e y e retorna oresultado de x! + y!. Faça também uma função auxiliar fatorial , que recebe um númeron e retorna o resultado de n!. A função somaFat deve chamar a função fatorial parafazer o cálculo do fatorial de um número.

Exemplo de entrada
3
5	
Exemplo de saída
3! + 5! = 126

Exemplo de entrada
6
4	
Exemplo de saida
6! + 4! = 744
*/

#include <stdio.h>

int fatorial(int n) {
    int fat = 1;
    for (int i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int somaFat(int x, int y) {
    return fatorial(x) + fatorial(y);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d! + %d! = %d\n", x, y, somaFat(x, y));
    return 0;
}