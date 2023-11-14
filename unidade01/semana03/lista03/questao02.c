/*Diz-se que um número primo nnn​ é gêmeo de um número n+2n+2n+2​ se este também for primo. Por exemplo, 3 é primo gêmeo de 5; 5 é primo gêmeio de 7; 23 não é primo gêmeo de 25. Implemente uma função que receba como entrada um número inteiro positivo e retorne verdadeiro caso o número seja primo e falso caso contrário. Após isto, implemente também a função main, que deve ler do usuário um número inteiro e imprimir uma mensagem informando se ele forma um par de gêmeos, de acordo com uma chamada à função implementada. Observe que, mesmo que a sua resposta seja dada como correta pelo sistema, a implementação e chamada da função como especificado deverá ser considerada para resposta completa do exercício.*/

#include <stdio.h>

int primo(int n){
    int i;
    if(n == 1){
        return 0;
    }
    for(i = 2; i < n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    if(primo(n) && primo(n+2)){
        printf("Numero forma par de gemeos\n");
    }else{
        printf("Numero nao forma par de gemeos\n");
    }
    return 0;
}