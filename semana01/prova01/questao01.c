#include <stdio.h>
int main()
{
    int quantidade_dias, anos, meses, dias;
    scanf("%d", &quantidade_dias);
    anos = quantidade_dias / 360;
    quantidade_dias %= 360;
    meses = quantidade_dias / 30;
    quantidade_dias %= 30;
    dias = quantidade_dias;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
    return 0;
}