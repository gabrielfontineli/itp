#include <stdio.h>

int main(){
    int totalAmount = 0;
    double totalValue = 0;
    int amount;
    double unitPrice;

    while (1){
        scanf("%d %lf", &amount, &unitPrice);

        if(amount == -1){
            break;
        }

        totalAmount += amount;
        totalValue += amount * unitPrice;
    }
    printf("%d %.2lf\n", totalAmount, totalValue);
    return 0;
}