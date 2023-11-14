#include <stdio.h>

int main(){
    int numero;
    scanf("%d", &numero);
    if (numero < 1 || numero > 100000)
    {
        printf("Número fora do intervalo permitido.\n");
        return 1;
    }
    int divisor = 1;
    int temp = numero;
    while (temp >= 10)
    {
        divisor *= 10;
        temp /= 10;
    }
    while (divisor > 0)
    {
        int digito = numero / divisor;
        printf("%d\n", digito);
        numero %= divisor;
        divisor /= 10;
    }

    return 0;
}