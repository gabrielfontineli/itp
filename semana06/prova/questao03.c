#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PEOPLE 1000 // Define um limite máximo para simplificar a implementação

typedef struct {
    char nome[MAX_NAME_LENGTH];
    int idade;
    char sexo;
} Pessoa;

Pessoa criar(char nome[], int idade, char sexo) {
    Pessoa p;
    strncpy(p.nome, nome, MAX_NAME_LENGTH);
    p.idade = idade;
    p.sexo = sexo;
    return p;
}

void inserir(Pessoa **array, int *size, Pessoa p) {
    *array = realloc(*array, (*size + 1) * sizeof(Pessoa));
    (*array)[*size] = p;
    (*size)++;
}

void deletar(Pessoa *array, int *size, Pessoa p) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(array[i].nome, p.nome) == 0 && array[i].idade == p.idade && array[i].sexo == p.sexo) {
            for (int j = i; j < *size - 1; j++) {
                array[j] = array[j + 1];
            }
            (*size)--;
            return;
        }
    }
}

void imprimir(Pessoa *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s,%d,%c\n", array[i].nome, array[i].idade, array[i].sexo);
    }
}

int main() {
    Pessoa *array = NULL;
    int size = 0;
    char command;
    char nome[MAX_NAME_LENGTH];
    int idade;
    char sexo;

    while (1) {
        scanf(" %c", &command);

        if (command == 'i') {
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            Pessoa p = criar(nome, idade, sexo);
            inserir(&array, &size, p);
        } else if (command == 'd') {
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            Pessoa p = criar(nome, idade, sexo);
            deletar(array, &size, p);
        } else if (command == 'p') {
            imprimir(array, size);
            break;
        }
    }

    free(array);
    return 0;
}
