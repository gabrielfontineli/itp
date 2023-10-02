#include <stdio.h>

int produtoVetorial(int x1, int y1, int x2, int y2) {
    return x1 * y2 - y1 * x2;
}

int naDireita(int x0, int y0, int x1, int y1, int x2, int y2) {
    return produtoVetorial(x1-x0, y1-y0, x2-x0, y2-y0) < 0;
}

int estaDentro(int px, int py, int *x, int *y, int n) {
    for(int i = 0; i < n; i++) {
        if (!naDireita(x[i], y[i], x[(i+1)%n], y[(i+1)%n], px, py)) {
            return 0;
        }
    }
    return 1; 
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int x[N], y[N];
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for(int i = 0; i < M; i++) {
        char id;
        int px, py;
        scanf(" %c %d %d", &id, &px, &py);

        if (estaDentro(px, py, x, y, N)) {
            printf("%c\n", id);
        }
    }

    return 0;
}
