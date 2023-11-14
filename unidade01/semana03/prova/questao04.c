/*
Escreva uma função chamada ehPar que verifica se um número é par. Essa função deve retornar o valor true em caso afirmativo, e false caso contrário. O programa deve chamar essa função.

Exemplo de entrada	Exemplo de saída
3	false
4	true
*/
#include <stdio.h>
#include <stdbool.h>

bool ehPar(int x){
    if (x % 2 == 0){
        return true;
    } else {
        return false;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    if (ehPar(n)){
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}