#include <stdio.h>

int main(){
    int n;
    char c;
    scanf("%d %c", &n, &c);
    n--;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || i + j == n - 1){
                printf("%c", c);
            } else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}