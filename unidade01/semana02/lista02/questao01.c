#include <stdio.h>
#include <math.h>

double media_harmonica(double nums[], int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += 1.0 / nums[i];
    }
    return n / soma;
}

double media_geometrica(double nums[], int n) {
    double produto = 1;
    for (int i = 0; i < n; i++) {
        produto *= nums[i];
    }
    return pow(produto, 1.0 / n);
}

int main() {
    double numeros[10];
    
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &numeros[i]);
    }
    
    double media_aritmetica = 0;
    for (int i = 0; i < 10; i++) {
        media_aritmetica += numeros[i];
    }
    media_aritmetica /= 10;
    
    double media_harmonica_result = media_harmonica(numeros, 10);
    double media_geometrica_result = media_geometrica(numeros, 10);
    
    double erro_harmonica = (media_harmonica_result - media_aritmetica) / media_aritmetica;
    double erro_geometrica = (media_geometrica_result - media_aritmetica) / media_aritmetica;
    double erro_medio = (fabs(erro_harmonica) + fabs(erro_geometrica)) / 2;

    printf("Média aritmética é %.2lf\n", media_aritmetica);
    printf("Média harmônica é %.2lf\n", media_harmonica_result);
    printf("Média geométrica é %.2lf\n", media_geometrica_result);
    printf("Erro médio é -%.2lf %%\n", erro_medio * 100);

    return 0;
}