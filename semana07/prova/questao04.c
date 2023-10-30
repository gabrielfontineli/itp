#include <stdio.h>

typedef struct {
    int id;
    char name[100];
    int votes;
} Party;

int compute_votes(int num_votes, int votes[num_votes], int num_parties, Party parties[num_parties], Party **most_voted, Party **second_most_voted) {
    int valid_votes = 0;

    // Inicializando votos das chapas
    for (int i = 0; i < num_parties; i++) {
        parties[i].votes = 0;
    }

    // Contabilizando votos
    for (int i = 0; i < num_votes; i++) {
        int found = 0;
        for (int j = 0; j < num_parties; j++) {
            if (votes[i] == parties[j].id) {
                parties[j].votes++;
                valid_votes++;
                found = 1;
                break;
            }
        }
        // Se não encontrou uma chapa correspondente, o voto é inválido
        if (!found) {
            continue;
        }
    }

    *most_voted = &parties[0];
    *second_most_voted = &parties[1];

    // Encontrando as duas chapas mais votadas
    for (int i = 0; i < num_parties; i++) {
        if (parties[i].votes > (*most_voted)->votes) {
            *second_most_voted = *most_voted;
            *most_voted = &parties[i];
        } else if (parties[i].votes > (*second_most_voted)->votes) {
            *second_most_voted = &parties[i];
        }
    }

    return valid_votes;
}

int main() {
    int N;
    scanf("%d", &N);

    Party parties[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &parties[i].id, parties[i].name);
        parties[i].votes = 0; // Inicializando os votos
    }

    int M;
    scanf("%d", &M);
    
    int votes[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &votes[i]);
    }

    Party *most_voted, *second_most_voted;
    int valid_votes = compute_votes(M, votes, N, parties, &most_voted, &second_most_voted);

    printf("VENCEDOR: %s (%d votos = %.2f%%)\n", most_voted->name, most_voted->votes, 100.0 * most_voted->votes / valid_votes);
    printf("VICE: %s (%d votos = %.2f%%)\n", second_most_voted->name, second_most_voted->votes, 100.0 * second_most_voted->votes / valid_votes);

    return 0;
}
