#include <stdio.h>

int main() {
    int codigoCombo, valorPago;
    int valorCombo = 0;

    // Lê os valores da entrada
    scanf("%d %d", &codigoCombo, &valorPago);

    switch (codigoCombo) {
        case 1:
            valorCombo = 12;
            break;
        case 2:
            valorCombo = 23;
            break;
        case 3:
            valorCombo = 31;
            break;
        case 4:
            valorCombo = 28;
            break;
        case 5:
            valorCombo = 15;
            break;
    }

    if (valorPago > valorCombo) {
        int troco = valorPago - valorCombo;
        printf("Troco = %d reais\n", troco);
    } else if (valorPago == valorCombo) {
        printf("Deu certim!\n");
    } else {
        int falta = valorCombo - valorPago;
        printf("Saldo insuficiente! Falta %d reais\n", falta);
    }

    return 0;
}
