#include <stdio.h>
#include <string.h>

// Define a estrutura Time
typedef struct {
    char nome[50];
    int gols_marcados;
    int gols_sofridos;
} Time;

// Função para realizar a troca de dois times
void trocar(Time *a, Time *b) {
    Time temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ordenar os times pelo número de gols marcados (decrescente)
void ordenarTimes(Time times[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (times[j].gols_marcados < times[j+1].gols_marcados) {
                trocar(&times[j], &times[j+1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); // Lê o número de times

    Time times[n];

    // Lê as informações de cada time
    for (int i = 0; i < n; i++) {
        getchar(); // Consume newline left by previous input
        fgets(times[i].nome, 50, stdin);
        times[i].nome[strlen(times[i].nome) - 1] = '\0'; // Remove newline at the end of the string
        scanf("%d", &times[i].gols_marcados);
        scanf("%d", &times[i].gols_sofridos);
    }

    // Chama a função para ordenar os times
    ordenarTimes(times, n);

    // Exibe as informações dos times ordenados
    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", i+1, times[i].nome);
        printf("Gols marcados: %d\n", times[i].gols_marcados);
        printf("Gols sofridos: %d\n", times[i].gols_sofridos);
    }

    return 0;
}
