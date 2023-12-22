#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char **m;
    int linhas;
    int colunas;
} Grade;

typedef struct {
    int linha;
    int coluna;
    int tamanho;
    char direcao;
} PalavraAchada;

// Função para comparar caracteres, ignorando maiúsculas e minúsculas
int comparaChar(char a, char b) {
    return tolower(a) == tolower(b);
}

// Função para buscar a palavra em uma direção específica
int buscaDirecao(Grade *g, char *p, int x, int y, int dx, int dy) {
    int len = strlen(p);

    // Verifica se a palavra cabe na direção escolhida
    if (x + dx * (len - 1) < 0 || x + dx * (len - 1) >= g->linhas || 
        y + dy * (len - 1) < 0 || y + dy * (len - 1) >= g->colunas) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!comparaChar(g->m[x + i * dx][y + i * dy], p[i])) {
            return 0;
        }
    }

    return 1;
}

// Implementação da função achaPalavra
PalavraAchada achaPalavra(Grade *g, char *p) {
    PalavraAchada pa = {0, 0, 0, '0'};
    int len = strlen(p);

    // Direções: cima, baixo, esquerda, direita, diagonais
    int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    char direcaoLetras[8] = {'c', 'b', 'e', 'd', '1', '2', '3', '4'};

    for (int i = 0; i < g->linhas; i++) {
        for (int j = 0; j < g->colunas; j++) {
            if (comparaChar(g->m[i][j], p[0])) {
                for (int d = 0; d < 8; d++) {
                    if (buscaDirecao(g, p, i, j, direcoes[d][0], direcoes[d][1])) {
                        pa.linha = i + 1; // Ajuste para indexação base-1
                        pa.coluna = j + 1; // Ajuste para indexação base-1
                        pa.tamanho = len;
                        pa.direcao = direcaoLetras[d];
                        return pa;
                    }
                }
            }
        }
    }

    // Palavra não encontrada
    return pa;
}
// Função para imprimir os detalhes de uma palavra encontrada
void imprimePalavra(char *p, PalavraAchada pa) {
    if (pa.direcao == '0') {
        printf("%s,0,0,0\n", p);
    } else {
        printf("%s,%d,%d,%c\n", p, pa.linha, pa.coluna, pa.direcao);
    }
}

int main() {
    int N, L, C;
    scanf("%d %d %d", &N, &L, &C);

    // Alocação da grade
    Grade g;
    g.linhas = L;
    g.colunas = C;
    g.m = (char **)malloc(L * sizeof(char *));
    for (int i = 0; i < L; i++) {
        g.m[i] = (char *)malloc((C + 1) * sizeof(char)); // +1 para o caractere nulo
        scanf("%s", g.m[i]);
    }

    // Processamento das palavras
    char palavra[101];
    for (int i = 0; i < N; i++) {
        scanf("%s", palavra);
        PalavraAchada pa = achaPalavra(&g, palavra);
        imprimePalavra(palavra, pa);
    }

    // Liberação da memória
    for (int i = 0; i < L; i++) {
        free(g.m[i]);
    }
    free(g.m);

    return 0;
}
