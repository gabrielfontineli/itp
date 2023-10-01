#include <stdio.h>
#include <stdbool.h>

bool isBomb(int i, int j, int N, int M, int map[N][M]) {
    if ((i > 0 && map[i][j] <= map[i-1][j]) ||
        (i < N-1 && map[i][j] <= map[i+1][j]) ||
        (j > 0 && map[i][j] <= map[i][j-1]) ||
        (j < M-1 && map[i][j] <= map[i][j+1]) ||
        (i > 0 && j > 0 && map[i][j] <= map[i-1][j-1]) ||   // diagonal superior esquerdo
        (i > 0 && j < M-1 && map[i][j] <= map[i-1][j+1]) || // diagonal superior direito
        (i < N-1 && j > 0 && map[i][j] <= map[i+1][j-1]) || // diagonal inferior esquerdo
        (i < N-1 && j < M-1 && map[i][j] <= map[i+1][j+1])) { // diagonal inferior direito
        return false;
    }
    return true;
}


int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int jediX, jediY;
    scanf("%d %d", &jediX, &jediY);

    int map[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    bool rescued = false;
    int count = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(isBomb(i, j, N, M, map)) {
                count++;
                printf("Local %d: %d %d\n", count, i + 1, j + 1);
                if (i + 1 == jediX && j + 1 == jediY) {
                    rescued = true;
                }
            }
        }
    }

    if(rescued) {
        printf("Descanse na Força...\n\n");
    } else {
        printf("Ao resgate!\n\n");
    }

    return 0;
}
