#include <stdio.h>

int main() {
    float temperatura;
    char escala;

    scanf("%f %c", &temperatura, &escala);
    float temperaturaC, temperaturaF, temperaturaK;

    switch (escala) {
        case 'C':
            temperaturaC = temperatura;
            temperaturaF = temperaturaC * 1.8 + 32;
            temperaturaK = temperaturaC + 273.15;
            break;
        case 'F':
            temperaturaF = temperatura;
            temperaturaC = (temperaturaF - 32) / 1.8;
            temperaturaK = temperaturaC + 273.15;
            break;
        case 'K':
            temperaturaK = temperatura;
            temperaturaC = temperaturaK - 273.15;
            temperaturaF = temperaturaC * 1.8 + 32;
            break;
        default:
            printf("Escala inválida.\n");
            return 1;
    }

    printf("Celsius: %.2f\n", temperaturaC);
    printf("Farenheit: %.2f\n", temperaturaF);
    printf("Kelvin: %.2f\n", temperaturaK);

    return 0;
}