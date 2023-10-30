// FALTA FAZER

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int pontos;
    int jogos;
    int vitorias;
    int empates;
    int derrotas;
    int golsPro;
    int golsContra;
    int saldoGols;
} Time;

int compararTimes(const void *a, const void *b) {
    Time *timeA = (Time *)a;
    Time *timeB = (Time *)b;

    if (timeA->pontos != timeB->pontos) {
        return timeB->pontos - timeA->pontos;
    }
    if (timeA->vitorias != timeB->vitorias) {
        return timeB->vitorias - timeA->vitorias;
    }
    if (timeA->saldoGols != timeB->saldoGols) {
        return timeB->saldoGols - timeA->saldoGols;
    }
    return strcmp(timeA->nome, timeB->nome);  // ordem alfabética
}

int main() {
    int n = 20;
    Time times[n];

    for (int i = 0; i < n; i++) {
        scanf("%[^|]| %d| %d| %d| %d| %d| %d| %d| %d", 
              times[i].nome, &times[i].pontos, &times[i].jogos, &times[i].vitorias, 
              &times[i].empates, &times[i].derrotas, &times[i].golsPro, 
              &times[i].golsContra, &times[i].saldoGols);
        getchar();
    }

    qsort(times, n, sizeof(Time), compararTimes);

    printf("Tabela do campeonato:\n");
    for (int i = 0; i < n; i++) {
        printf("%s|%d|%d|%d|%d|%d|%d|%d|%d\n",
               times[i].nome, times[i].pontos, times[i].jogos, times[i].vitorias, 
               times[i].empates, times[i].derrotas, times[i].golsPro, 
               times[i].golsContra, times[i].saldoGols);
    }

    printf("\nTimes na zona da libertadores:\n");
    for (int i = 0; i < 6; i++) {
        printf("%s\n", times[i].nome);
    }

    printf("\nTimes rebaixados:\n");
    for (int i = n - 4; i < n; i++) {
        printf("%s\n", times[i].nome);
    }

    return 0;
}
