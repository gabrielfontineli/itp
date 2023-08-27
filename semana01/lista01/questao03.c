// Escreva um programa que leia quatro números inteiros (podem ser negativos) e escreva na tela string "Maior: " seguida do maior deles. Se houver empate, escreva somente um deles.

#include <stdio.h>
int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a >= b && a >= c && a >= d){
        printf("Maior: %d\n", a);
    } else if (b >= a && b >= c && b >= d){
        printf("Maior: %d\n", b);
    } else if (c >= a && c >= b && c >= d){
        printf("Maior: %d\n", c);
    } else if (d >= a && d >= b && d >= c){
        printf("Maior: %d\n", d);
    }
}
