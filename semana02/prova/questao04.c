/*Competições de atletismo são caracterizadas por diferentes provas de saltos, corridas e lançamentos. Uma das tarefas do organizador consiste em distribuir as provas ao longo de um dia ou vários de acordo com a quantidade de atletas em cada prova. Você deve desenvolver um programa para auxiliar o organizador a tomar nessa atividade.

Para isso, você irá desenvolver um programa que analisa as inscrições de cada clube e determina a quantidade de atletas em cada tipo de prova. A primeira entrada do programa consiste na quantidade N de equipes inscritas na competição. Em seguida, para cada equipe inscrita, é fornecida uma quantidade indeterminada de inscrições representadas por um único caractere que pode assumir os valores C, S ou L indicando respectivamente uma prova de corrida, salto ou lançamento. A entrada das inscrições de uma equipe termina com a apresentação do valor F e então são fornecidas as inscrições da próxima equipe até que todas as N equipes sejam apresentadas ao programa.

O programa deve apresentar como saída a quantidade de total de atletas em cada tipo de prova na seguinte ordem: provas de corrida; provas de salto e provas de lançamento. Logo em seguida deve ser apresentado a quantidade total de atletas em todas as provas.

Observe o formato da entrada e saída padrão para ver como esses dados serão inseridos no programa.

Exemplo de entrada	Exemplo de saída
1
S S S C L L F	1 3 2 6
2
S S S F
C L F	1 3 1 5*/
#include <stdio.h>

int main(){
    int n, atletasCorrida = 0, atletasSalto = 0, atletasLancamento = 0, atletasTotal = 0;
    char prova;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %c", &prova);
        while(prova != 'F'){
            if(prova == 'C'){
                atletasCorrida++;
            } else if(prova == 'S'){
                atletasSalto++;
            } else if(prova == 'L'){
                atletasLancamento++;
            }
            scanf(" %c", &prova);
        }
    }
    atletasTotal = atletasCorrida + atletasSalto + atletasLancamento;
    printf("%d %d %d %d\n", atletasCorrida, atletasSalto, atletasLancamento, atletasTotal);
    return 0;
}