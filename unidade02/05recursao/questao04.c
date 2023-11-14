#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função que remove os espaços e normaliza a string
void removeEspacosEConverteParaMinuscula(char *str) {
    char *i = str, *j = str;
    while (*j != '\0') {
        if (*j != ' ') {
            *i = tolower(*j); // Converte para minúscula e copia se não for espaço
            i++;
        }
        j++;
    }
    *i = '\0'; // Finaliza a string
}

// Função recursiva para verificar se a string é um palíndromo
int ehPalindromoRecursivo(char *str, int inicio, int fim) {
    if (inicio >= fim) 
        return 1;
    if (str[inicio] != str[fim]) 
        return 0;
    return ehPalindromoRecursivo(str, inicio + 1, fim - 1);
}

// Função wrapper
int palindromo(char *entrada) {
    char temp[strlen(entrada) + 1];
    strcpy(temp, entrada);
    removeEspacosEConverteParaMinuscula(temp);
    return ehPalindromoRecursivo(temp, 0, strlen(temp) - 1);
}

// Função principal
int main() {
    char texto[1000]; // Tamanho arbitrário para a entrada

    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = 0; // Remove a quebra de linha da entrada

    if (palindromo(texto))
        printf("O texto \"%s\" é palíndromo\n", texto);
    else
        printf("O texto \"%s\" não é palíndromo\n", texto);

    return 0;
}
