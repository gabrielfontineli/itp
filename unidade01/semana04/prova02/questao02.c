#include <stdio.h>

int main() {
  int n, nP, nM;
  scanf("%d", &n);

  int piramide[n][n];

  for(int a = 0; a < n; a++){
    for(int b = 0; b < n; b++){
      piramide[a][b] = 0;
    }
  }

  

  for(int a = 0; a <= (n/2); a++){
    for(int i = a; i < (n-a); i++){
      for(int z = a; z < (n-a); z++){
        piramide[i][z] += 1;
      }
    }
  }

  for(int a = 0; a < n; a++){
    for(int b = 0; b < n; b++){
      printf("%d ", piramide[a][b]);
    }
    printf("\n");
  }
}