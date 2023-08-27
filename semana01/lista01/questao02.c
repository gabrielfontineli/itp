// escreva um programa que leia dois numeros inteiros a e b. Em seguida, somente no caso de b dividir a, escreva na tela "Resultado: " e o resultado da divisão ba

#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    if (a % b == 0){
        printf("Resultado: %d\n", a/b);
    }
}