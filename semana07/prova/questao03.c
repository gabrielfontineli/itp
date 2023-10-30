#include <stdio.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
    int count[11] = {0}; // inicializando vetor de contagem com 0

    for (int i = 0; i < n; i++) {
        count[votes[i]]++; // contando votos
    }

    *most_voted = 0;
    *second_most_voted = 0;

    for (int i = 1; i <= 10; i++) {
        if (count[i] > count[*most_voted]) {
            *second_most_voted = *most_voted;
            *most_voted = i;
        } else if (count[i] > count[*second_most_voted]) {
            *second_most_voted = i;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int votes[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &votes[i]);
    }

    int most_voted, second_most_voted;
    compute_votes(N, votes, &most_voted, &second_most_voted);

    printf("%d %d\n", most_voted, second_most_voted);

    return 0;
}
