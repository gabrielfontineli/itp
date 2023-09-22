#include <stdio.h>

int main(){
    int i, n, b[15], c[15], d[15], nb = 0, nc = 0, nd = 0;
    for (i = 0; i < 15; i++){
        scanf("%d", &n);
        if (n % 2 == 0){
            b[nb] = n;
            nb++;
        }
        if (n % 3 == 0){
            c[nc] = n;
            nc++;
        }
        if (n % 2 != 0 && n % 3 != 0){
            d[nd] = n;
            nd++;
        }
    }
    printf("B = [");
    for (i = 0; i < nb; i++){
        printf("%d", b[i]);
        if (i < nb-1){
            printf(", ");
        }
    }
    printf("]\n");
    printf("C = [");
    for (i = 0; i < nc; i++){
        printf("%d", c[i]);
        if (i < nc-1){
            printf(", ");
        }
    }
    printf("]\n");
    printf("D = [");
    for (i = 0; i < nd; i++){
        printf("%d", d[i]);
        if (i < nd-1){
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}