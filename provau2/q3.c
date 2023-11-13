#include <stdio.h>

// Função para calcular combinações de forma recursiva
int calcularCombinacoes(int total, int selecionados) {
    // Casos base: se selecionados é 0 ou igual ao total, retorna 1
    if (selecionados == 0 || selecionados == total) {
        return 1;
    }
    // Caso base: se selecionados é 1, retorna o total
    if (selecionados == 1) {
        return total;
    }
    // Chamada recursiva considerando a inclusão e exclusão de um elemento
    return calcularCombinacoes(total - 1, selecionados - 1) + calcularCombinacoes(total - 1, selecionados);
}

int main() {
    int totalElementos, elementosSelecionados, resultado;

    // Solicita ao usuário os valores para total de elementos e elementos a serem selecionados
    printf("Informe o total de elementos e o numero de elementos a selecionar: ");
    scanf("%d %d", &totalElementos, &elementosSelecionados);

    // Calcula as combinações
    resultado = calcularCombinacoes(totalElementos, elementosSelecionados);

    // Exibe o resultado
    printf("Numero de combinacoes de %d elementos tomados %d a %d: %d\n", totalElementos, elementosSelecionados, elementosSelecionados, resultado);

    return 0;
}
