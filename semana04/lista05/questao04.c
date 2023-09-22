/*
Depois que você trabalhou na equipe de desenvolvimento do próximo Assassin's Creed, gerando pirâmides do Egito, uma nova equipe te contratou para trabalhar em um jogo similar, com estruturas similares a pirâmides... mas diferentes. A nova estrutura cresce em blocos e tem base quadrada, como as pirâmides, mas ao invés de crescer em camadas quadradas, cada camada é um losango.

Por exemplo, numa pirâmide que tem 3 blocos de largura, teremos 3 camadas. A primeira (a base da estrutura) será quadrada e terá altura de um único bloco. A segunda camada terá altura de dois blocos e será um losango. Por fim, a última terá altura de 3 blocos (bem no centro), como ilustrado a seguir:

1 2 1
2 3 2
1 2 1

Para uma pirâmide com 4 blocos de largura, teremos também 3 camadas, com a seguinte estrutura:
1 2 2 1
2 3 3 2
2 3 3 2
1 2 2 1

Para uma pirâmide com 5 blocos de largura, teremos a seguinte estrutura:
1 2 3 2 1
2 3 4 3 2
3 4 5 4 3
2 3 4 3 2
1 2 3 2 1

...e assim por diante.

Escreva então um programa que crie uma matriz quadrada com as alturas (número de blocos) dessa nova estrutura, dada sua a largura.

​Entrada

Seu programa deve ser um único valor inteiro N representando a quantidade de blocos da largura da estrutura.

Saída

Considerando que a estrutura possui uma base quadrada (largura e profundidade são iguais), seu programa deve enviar para a saída-padrão uma matriz com a altura de cada uma de suas posições.

*/

#include <stdio.h>

int main(){
    int n, i, j, k, l, aux;
    scanf("%d", &n);
    int v[n][n];
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            v[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            aux = 0;
            for (k = 0; k < n; k++){
                for (l = 0; l < n; l++){
                    if (k == i && l == j){
                        aux = 1;
                    }
                    if (aux == 1){
                        v[k][l]++;
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    return 0;
}