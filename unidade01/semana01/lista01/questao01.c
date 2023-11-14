#include <stdio.h>

int main(){
    int l1, l2, l3;

    scanf("%d", &l1);
    scanf("%d", &l2);
    scanf("%d", &l3);

    if (l1 < l2 + l3 && l2 < l1 + l3 && l3 < l1 + l2){
        printf("possivel\n");
    } else {
        printf("impossivel\n");
    }

    return 0;
}
