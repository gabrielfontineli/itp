#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int idade;
    char sexo; 
} Pessoa;

Pessoa criar(char *nome, int idade, char sexo);
void inserir(Pessoa **vetor, int *tamanho, Pessoa novaPessoa);
int comparar(Pessoa a, Pessoa b);
void deletar(Pessoa **vetor, int *tamanho, Pessoa pessoa);
void imprimir(Pessoa *vetor, int tamanho);

int main() {
    Pessoa *vetor = NULL;
    int tamanho = 0;
    char comando;

    while (scanf(" %c", &comando) && comando != 'p') {
        if (comando == 'i') {
            char nome[1024];
            int idade;
            char sexo;

            scanf(" %[^\n]s", nome);
            scanf("%d %c", &idade, &sexo);

            Pessoa novaPessoa = criar(nome, idade, sexo);
            inserir(&vetor, &tamanho, novaPessoa);
        } else if (comando == 'd') {
            char nome[1024];
            int idade;
            char sexo;

            scanf(" %[^\n]s", nome);
            scanf("%d %c", &idade, &sexo);

            Pessoa pessoa = criar(nome, idade, sexo);
            deletar(&vetor, &tamanho, pessoa);
            free(pessoa.nome); 
        }
    }

    imprimir(vetor, tamanho);

    for (int i = 0; i < tamanho; i++) {
        free(vetor[i].nome);
    }
    free(vetor);

    return 0;
}

Pessoa criar(char *nome, int idade, char sexo) {
    Pessoa p;
    p.nome = strdup(nome); 
    p.idade = idade;
    p.sexo = sexo;
    return p;
}

void inserir(Pessoa **vetor, int *tamanho, Pessoa novaPessoa) {
    *vetor = realloc(*vetor, (*tamanho + 1) * sizeof(Pessoa));
    (*vetor)[*tamanho] = novaPessoa;
    (*tamanho)++;
}

int comparar(Pessoa a, Pessoa b) {
    return strcmp(a.nome, b.nome) == 0 && a.idade == b.idade && a.sexo == b.sexo;
}

void deletar(Pessoa **vetor, int *tamanho, Pessoa pessoa) {
    for (int i = 0; i < *tamanho; i++) {
        if (comparar((*vetor)[i], pessoa)) {
            free((*vetor)[i].nome); 
            for (int j = i; j < *tamanho - 1; j++) {
                (*vetor)[j] = (*vetor)[j + 1];
            }
            *vetor = realloc(*vetor, (*tamanho - 1) * sizeof(Pessoa));
            (*tamanho)--;
            break;
        }
    }
}

void imprimir(Pessoa *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s,%d,%c\n", vetor[i].nome, vetor[i].idade, vetor[i].sexo);
    }
}
