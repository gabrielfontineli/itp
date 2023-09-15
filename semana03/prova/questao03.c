/*
Na matemática, um número perfeito é um número inteiro para o qual a soma de todos os seus divisores positivos próprios (excluindo ele mesmo) é igual ao próprio número. Por exemplo o número 6 é perfeito, pois 1+2+3 é igual a 6. 

Sua tarefa é escrever um programa que utiliza uma função com tipo de retorno bool, que recebe um inteiro x e retorna true se x for perfeito ou false caso contrário. Seu programa deve utilizar a função para determinar se um número é perfeito ou não. 

A primeira linha da entrada contém um inteiro N, indicando o número de casos a serem verificados. Cada uma das N linhas seguintes contém um valor inteiro X, que pode ser ou não, um número perfeito. Para cada caso de teste de entrada, imprima a mensagem “X eh perfeito” ou “X nao eh perfeito”, de acordo com a especificação fornecida.

Exemplo de entrada	
3
6
5
28
Exemplo de saída

6 eh perfeito
5 nao eh perfeito
28 eh perfeito

Exemplo de entrada	
4
5
10
4
496

Exemplo de saída

5 nao eh perfeito
10 nao eh perfeito
4 nao eh perfeito
496 eh perfeito
*/

#include <stdio.h>

int numeroPerfeito(int x){
    int soma, i;
    soma = 0;
    for (i = 1; i < x; i++){
        if (x % i == 0){
            soma += i;
        }
    }
    if (soma == x){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int n, i, n2;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &n2);
        if (numeroPerfeito(n2)){
            printf("%d eh perfeito\n", n2);
        } else {
            printf("%d nao eh perfeito\n", n2);
        }
    }
    return 0;
}