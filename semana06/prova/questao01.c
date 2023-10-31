#include <stdio.h>
#include <string.h>

#define MAX 200

typedef struct {
    char name[MAX];
    int wins;
    int draws;
    int losses;
    int goals_scored;
    int goals_conceded;
    int points;
    int games_played;
    int goal_difference;
} Team;

void readTeams(Team teams[], int n) {
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n;]; %d %d %d %d %d", teams[i].name, &teams[i].wins, &teams[i].draws, &teams[i].losses, &teams[i].goals_scored, &teams[i].goals_conceded);

        teams[i].points = teams[i].wins * 3 + teams[i].draws;
        teams[i].games_played = teams[i].wins + teams[i].draws + teams[i].losses;
        teams[i].goal_difference = teams[i].goals_scored - teams[i].goals_conceded;
    }
}

void printTable(Team teams[], int n) {
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
    for (int i = 0; i < n; i++) {
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n", teams[i].name, teams[i].points, teams[i].games_played, teams[i].wins, teams[i].draws, teams[i].losses, teams[i].goals_scored, teams[i].goals_conceded, teams[i].goal_difference);
    }

    printf("\nTimes na zona da libertadores: \n");
    for (int i = 0; i < 6; i++) {
        printf("%s\n", teams[i].name);
    }

    printf("\nTimes rebaixados: \n");
    for (int i = n - 1; i >= n - 4; i--) {
        printf("%s\n", teams[i].name);
    }
}

int compareTeams(const void *a, const void *b) {
    Team *teamA = (Team *)a;
    Team *teamB = (Team *)b;

    if (teamA->points != teamB->points)
        return teamB->points - teamA->points;

    if (teamA->wins != teamB->wins)
        return teamB->wins - teamA->wins;

    return teamB->goal_difference - teamA->goal_difference;
}

int main() {
    int T;
    scanf("%d", &T);
    Team teams[T];

    readTeams(teams, T);

    qsort(teams, T, sizeof(Team), compareTeams);

    printTable(teams, T);

    return 0;
}
