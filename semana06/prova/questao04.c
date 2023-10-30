#include <stdio.h>

typedef struct {
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} Smartphone;

int cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]) {
    scanf(" %[^\n]s", phones[qnt_cadastrada].modelo);
    scanf("%d", &phones[qnt_cadastrada].memoria);
    scanf("%f", &phones[qnt_cadastrada].processador);
    scanf("%f", &phones[qnt_cadastrada].camera);
    scanf("%f", &phones[qnt_cadastrada].bateria);
    
    return qnt_cadastrada + 1;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[], Smartphone reqMin) {
    int count = 0;
    for (int i = 0; i < qnt_cadastrada; i++) {
        if (phones[i].memoria >= reqMin.memoria &&
            phones[i].processador >= reqMin.processador &&
            phones[i].camera >= reqMin.camera &&
            phones[i].bateria >= reqMin.bateria) {
            printf("Modelo: %s\n", phones[i].modelo);
            printf("Memoria: %dGB\n", phones[i].memoria);
            printf("Processador: %.2fGhz\n", phones[i].processador);
            printf("Camera: %.2fMPixels\n", phones[i].camera);
            printf("Bateria: %.2fmA\n\n", phones[i].bateria);
            count++;
        }
    }
    return count;
}

int main() {
    Smartphone phones[100];
    int qnt_cadastrada = 0;
    char opcao;

    do {
        scanf(" %c", &opcao);
        if (opcao == 's') {
            qnt_cadastrada = cadastraSmartphone(qnt_cadastrada, phones);
        }
    } while (opcao == 's');

    Smartphone reqMin;
    scanf("%d", &reqMin.memoria);
    scanf("%f", &reqMin.processador);
    scanf("%f", &reqMin.camera);
    scanf("%f", &reqMin.bateria);

    int encontrados = pesquisaSmartphones(qnt_cadastrada, phones, reqMin);
    printf("%d smartphones encontrados.\n", encontrados);

    return 0;
}
