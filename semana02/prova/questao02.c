#include <stdio.h>

int main() {
    int n, i, j, k=1;
    scanf("%d", &n);
    if (n <= 0) printf("Você entrou com %d, tente de novo na próxima", n);
    else{
        for(i = 1; i <= n; i++){
            for(j=1; j<=i; j++){
                if (k<=9){
                    printf(" ");
                }
                printf("%d ", k);
                k++;
                }
            printf("\n");
            }
  }

  return 0;
}