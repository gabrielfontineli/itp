#include <stdio.h>

int main(){
    int n, i, j, aux;
    scanf("%d", &n);
    int v[n];
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    for (i = 0; i < n-1; i++){
        for (j = i+1; j < n; j++){
            if (v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
        for (j = 0; j < n; j++){
            printf("%d ", v[j]);
        }
        printf("\n");
    }
    return 0;
}