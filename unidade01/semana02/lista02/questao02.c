#include <stdio.h>

int main(){
    int num, originalNum, reversedNum = 0, remainder;

    scanf("%d", &num);
    originalNum = num;

    while( num != 0){
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }
    if (originalNum == reversedNum){
        printf("%d é Palíndromo e ", originalNum);
        if(originalNum % 2 == 0){
            printf("par.\n");
    } else{
        printf("impar.\n");
    }
    } else{
        printf("%d não é Palíndromo e ", originalNum);
        if(originalNum % 2 == 0){
            printf("par.\n");
    } else{
        printf("impar.\n");
    }
    } 
    return 0;
}