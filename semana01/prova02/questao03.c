#include <stdio.h>

int main() {
    int quantidadeHerois, classeHerois, nivelAmeaca;

    scanf("%d %d %d", &quantidadeHerois, &classeHerois, &nivelAmeaca);

    if (quantidadeHerois == 0) {
        printf("Melhor chamar Saitama!\n");
    } else if ((nivelAmeaca == 1 && (classeHerois >= 2 || quantidadeHerois >= 3)) ||
        (nivelAmeaca == 2 && (classeHerois >= 3 || quantidadeHerois >= 3 && classeHerois == 2)) ||
        (nivelAmeaca == 3 && (classeHerois >= 4 || quantidadeHerois >= 3 && classeHerois == 3)) ||
        (nivelAmeaca == 4 && (classeHerois >= 5 || quantidadeHerois >= 3 && classeHerois == 4)) ||
        (nivelAmeaca == 5 && classeHerois == 5)) {
        printf("Heróis vencerão!\n");
    } else {
        printf("Melhor chamar Saitama!\n");
    }

    return 0;
}
