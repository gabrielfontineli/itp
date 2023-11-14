#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int size;
  char **nomes;
} List;

List *createNameList();
void clearString(char *nome);
void addName(List *, char *);

int main() {
  List *listNames = createNameList();
  while (1) {
    char *name = calloc(52, sizeof(char));
    fgets(name, 52, stdin);
    clearString(name);
    if (!strcmp(name, "acabou"))
      break;
    addName(listNames, name);
  }

  int n = listNames->size;

  int seed;
  scanf("%d", &seed);
  srand(seed);
  int cont = 0;

  while (cont < n) {
    int indiceParticipante = rand() % n;
    if (strcmp("X\0", listNames->nomes[indiceParticipante]) == 0) {
      continue;
    }
    printf("%s\n", listNames->nomes[indiceParticipante]);

    listNames->nomes[indiceParticipante] = "X\0";
    cont++;
  }

  return 0;
}

void addName(List *lista, char *nome) {
  lista->size = lista->size + 1;
  lista->nomes = realloc(lista->nomes, sizeof(char *) * lista->size);
  lista->nomes[lista->size - 1] = nome;
}

List *createNameList() {
  List *list;
  list = calloc(1, sizeof(List));
  list->size = 0;
  list->nomes = calloc(0, sizeof(char *));

  return list;
}

void clearString(char *nome) {
  for (int i = 0; i < strlen(nome); i++) {
    if (nome[i] == '\n') {
      nome[i] = '\0';
      break;
    }
  }
}