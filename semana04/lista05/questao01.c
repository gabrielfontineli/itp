/*
Após a ordem 66, os Jedis passaram a ser caçados impiedosamente pelo exército de Clones da República galática, agora sob o comando do Império Sith. Àqueles que não sucumbiram no ataque inicial, fugiram para locais isolados do universo, em busca de abrigo e aguardando um momento oportuno para um contra ataque.

Para tentar auxiliar os Jedis, a Aliança Rebelde faz buscas em planetas atacados pelos Clones, na esperança de encontrar sobreviventes. Como os Jedis são adversários formidáveis, os Clones bombardearam os planetas com ogivas radioativas, na esperança de eliminar os cavaleiros da força à distância. Após os ataques, a comunicação com o planeta é cortada, porém os Rebeldes conhecem a última posição onde cada Jedi estava escondido.

Seu programa deverá fazer uma leitura de um mapa de radiação do planeta, definido por dois valores inteiros N e M, o tamanho N x M do mapa. Em seguida, ele lerá dois valores inteiros, as últimas coordenadas conhecidas do Jedi que estava escondido no planeta. Essas coordenadas são respectivamente a linha (de 1 até N) e a coluna (de 1 até M) do ponto no mapa.

A partir daí, seu programa deve ler N x M valores inteiros, representando os índices de radiação de um planeta. Os locais onde as bombas de ataque foram lançados apresentam picos de radiação, ou seja, o valor de radiação é mais alto do que todos os locais ao redor. Veja esse exemplo de um mapa 3x3:

                                                                                                                2 3 3

                                                                                                                1 8 4

                                                                                                                3 1 2

Podemos ver que houve um ataque na 2° linha e na 2º coluna do mapa, onde o valor é 8, porque é maior do que todos os oito valores em volta. Todo mapa possui pelo menos uma bomba, e não há bombas em posições adjacentes, porque o império é poderoso mas precisa economizar no arsenal.

Seu programa deverá identificar no mapa e imprimir os locais onde as bombas caíram, e uma mensagem "Descanse na força..." quando o Jedi for atingido por uma bomba, e "Ao resgate!" quando ele sobreviver aos ataques. Observe os exemplos de entrada e saída para ver o formato correto para impressão dos resultados.

Exemplo de entrada	Exemplo de saída
3 3
1 1
2 3 3
1 8 4
3 1 2	Local 1: 2 2
Ao resgate!
5 5
5 3
1 1 2 7 11
8 8 8 9 9
8 8 8 10 3
8 8 8 5 -1
3 7 9 -2 4	Local 1: 1 5
Local 2: 3 4
Local 3: 5 3
Descanse na Força...
*/

#include <stdio.h>

int main(){
    int n, m, i, j, k, l, aux, bomba = 0;
    scanf("%d %d", &n, &m);
    int v[n][m];
    scanf("%d %d", &i, &j);
    for (k = 0; k < n; k++){
        for (l = 0; l < m; l++){
            scanf("%d", &v[k][l]);
        }
    }
    for (k = 0; k < n; k++){
        for (l = 0; l < m; l++){
            if (v[k][l] > v[k-1][l] && v[k][l] > v[k+1][l] && v[k][l] > v[k][l-1] && v[k][l] > v[k][l+1]){
                printf("Local %d: %d %d\n", bomba+1, k+1, l+1);
                bomba++;
            }
        }
    }
    if (v[i-1][j-1] > v[i-2][j-1] && v[i-1][j-1] > v[i][j-1] && v[i-1][j-1] > v[i-1][j-2] && v[i-1][j-1] > v[i-1][j]){
        printf("Descanse na Força...\n");
    } else {
        printf("Ao resgate!\n");
    }
    return 0;
}