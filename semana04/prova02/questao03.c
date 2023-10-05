#include <stdio.h>

int main() {
  char velha[3][3];

  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      scanf(" %c", &velha[a][b]);
    }
  }

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {

    char time;
    int linha, coluna, linhaT, colunaT, diagonalAT, diagonalBT;
    linhaT = colunaT = diagonalAT = diagonalBT = 0;
    scanf(" %d %d", &linha, &coluna);
    scanf(" %c", &time);

    linha -= 1;
    coluna -= 1;

    if (velha[linha][coluna] != '.') {
      printf("Jogada inválida!");
    } else {
      velha[linha][coluna] = time;

      for (int a = 0; a < 3; a++) {
        if (velha[linha][a] == time) {
          linhaT += 1;
        }
      }
      for (int a = 0; a < 3; a++) {
        if (velha[a][coluna] == time) {
          colunaT += 1;
        }
      }

      for (int a = 0; a < 3; a++) {
        if (velha[a][a] == time) {
          diagonalAT += 1;
        }
      }
      for (int a = 0; a < 3; a++) {
        if (velha[a][2 - a] == time) {
          diagonalBT += 1;
        }
      }

      if (linhaT > 2 || colunaT > 2 || diagonalAT > 2 || diagonalBT > 2) {
        printf("Boa jogada, vai vencer!");
      } else {
        printf("Continua o jogo.");
      }

      velha[linha][coluna] = '.';
      
    }
    printf("\n");
  }
}