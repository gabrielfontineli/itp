/*
Numa escola as médias finais dos alunos estão armazenadas em um vetor cuja ordem é a da lista de chamada da turma. Alunos com média maior ou igual a 7.0 estão aprovados, maior ou igual a 5.0 e menor que 7.0 estão em recuperação, e abaixo de 5.0 estão reprovados. Escreva um programa que lê a quantidade de alunos n da turma, e em seguida as suas nnn médias. Então, crie vetores que guardem a lista de alunos aprovados, em recuperação e reprovados com as respectivas notas.

Entrada​

número n de alunos da turma;
número do aluno na chamada - sua média parcial (n vezes).
Saída​

Listas de alunos aprovados, em recuperação e reprovados identificados pelo seu número e sua nota entre parênteses;
Exemplo de entrada	
5                  
1 - 3.2
2 - 9.2
3 - 6.1
4 - 8.6
5 - 0.3	

Exemplo de saída

Aprovados: 2 (9.2), 4 (8.6)
Recuperação: 3 (6.1)
Reprovados: 1 (3.2), 5 (0.3)

Entrada​

15
1 - 9.0
2 - 5.7
3 - 9.3
4 - 8.1
5 - 4.1
6 - 5.0
7 - 1.6
8 - 5.5
9 - 0.6
10 - 8.8
11 - 7.2
12 - 5.0
13 - 5.7
14 - 0.1
15 - 1.8

Saída

Aprovados: 1 (9.0), 3 (9.3), 4 (8.1), 10 (8.8), 11 (7.2)
Recuperação: 2 (5.7), 6 (5.0), 8 (5.5), 12 (5.0), 13 (5.7)
Reprovados: 5 (4.1), 7 (1.6), 9 (0.6), 14 (0.1), 15 (1.8)*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int alunos[n];
    float medias[n];
    int aprovados[n], reprovados[n], recuperacao[n];
    int tamanhoAprovados = 0, tamanhoReprovados = 0, tamanhoRecuperacao = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d - %f", &alunos[i], &medias[i]);
    }

    for(int i = 0; i < n; i++) {
        if(medias[i] >= 7.0) {
            aprovados[tamanhoAprovados++] = alunos[i];
        } else if(medias[i] >= 5.0) {
            recuperacao[tamanhoRecuperacao++] = alunos[i];
        } else {
            reprovados[tamanhoReprovados++] = alunos[i];
        }
    }

    printf("Aprovados: ");
    for(int i = 0; i < tamanhoAprovados; i++) {
        printf("%d (%.1f)", aprovados[i], medias[aprovados[i]-1]);
        if(i < tamanhoAprovados-1) {
            printf(", ");
        }
    }
    printf("\n");

    printf("Recuperação: ");
    for(int i = 0; i < tamanhoRecuperacao; i++) {
        printf("%d (%.1f)", recuperacao[i], medias[recuperacao[i]-1]);
        if(i < tamanhoRecuperacao-1) {
            printf(", ");
        }
    }
    printf("\n");

    printf("Reprovados: ");
    for(int i = 0; i < tamanhoReprovados; i++) {
        printf("%d (%.1f)", reprovados[i], medias[reprovados[i]-1]);
        if(i < tamanhoReprovados-1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}