#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
	FEMININO,
	MASCULINO,
	NAO_INFORMADO
} Sexo;

typedef struct
{
	char *nome;
	int idade;
	Sexo sexo;
} Pessoa;

typedef struct
{
	int size;
	Pessoa **array;
} Lista;

Pessoa *createPerson();
Lista *createLista();
void clearBuffer();
void printPerson(Pessoa *);
void add(Lista *, Pessoa *);
void deletar(Lista *, Pessoa *);
void removeFromIndex(Lista *, int);
Pessoa *lerPessoa();
void imprimir(Lista *);

int main()
{

	int isBreak = 0;
	Lista *lista = createLista();

	while (1)
	{
		char command;
		scanf("%c", &command);
		clearBuffer();
		if (command == 'i')
		{
			Pessoa *p = lerPessoa();
			add(lista, p);
		}
		else if (command == 'd')
		{
			Pessoa *p = lerPessoa();
			deletar(lista, p);
		}
		else
		{
			isBreak = 1;
		}

		if (isBreak)
			break;
	}

	imprimir(lista);
	return 0;
}

void imprimir(Lista *lista)
{
	for (int i = 0; i < lista->size; i++)
	{
		if (lista->array[i]->idade == -1)
			continue;
		printPerson(lista->array[i]);
	}
}

void deletar(Lista *lista, Pessoa *p)
{
	if (lista->size == 0)
		return;

	for (int i = 0; i < lista->size; i++)
	{
		if (strcmp(lista->array[i]->nome, p->nome) == 0 && lista->array[i]->idade == p->idade && lista->array[i]->sexo == p->sexo)
		{
			removeFromIndex(lista, i);
		}
	}
}

void removeFromIndex(Lista *lista, int index)
{

	if (index == 0 && lista->size == 1)
	{
		lista->array = realloc(lista->array, 0 * sizeof(Pessoa *));
		lista->size = 0;
		return;
	}
	for (int i = index; i < lista->size - 1; i++)
	{
		Pessoa aux = *lista->array[i];
		*(lista->array[i]) = *(lista->array[i + 1]);
		*lista->array[i + 1] = aux;
	}
	free(lista->array[lista->size - 1]);
	lista->array = realloc(lista->array, (lista->size - 1) * sizeof(Pessoa *));
	lista->size = lista->size - 1;
}

void add(Lista *lista, Pessoa *p)
{
	lista->array = realloc(lista->array, (lista->size + 1) * sizeof(Pessoa *));
	lista->array[lista->size] = p;
	lista->size = lista->size + 1;
}

Pessoa *lerPessoa()
{
	Pessoa *p = createPerson();
	char *nome = calloc(0, sizeof(char));
	int posNome = 0;
	while (1)
	{
		char c;
		scanf("%c", &c);
		if (c == '\n')
		{
			c = '\0';
		}
		nome = realloc(nome, (posNome + 1) * sizeof(char));
		nome[posNome] = c;
		posNome++;
		if (c == '\0')
			break;
	}
	p->nome = nome;

	scanf("%d", &p->idade);
	clearBuffer();

	char sexo;
	scanf("%c", &sexo);
	clearBuffer();

	if (sexo == 'M')
	{
		p->sexo = MASCULINO;
	}
	else if (sexo == 'F')
	{
		p->sexo = FEMININO;
	}
	else
	{
		p->sexo = NAO_INFORMADO;
	}

	return p;
}

void printPerson(Pessoa *p)
{
	printf("%s,%d,", p->nome, p->idade);
	if (p->sexo == FEMININO)
	{
		printf("F\n");
	}
	else if (p->sexo == MASCULINO)
	{
		printf("M\n");
	}
	else
	{
		printf("N\n");
	}
}

Lista *createLista()
{
	Lista *l = calloc(1, sizeof(Lista));
	l->size = 0;
	l->array = calloc(0, sizeof(Pessoa *));
	return l;
}

Pessoa *createPerson()
{
	Pessoa *p;
	p = calloc(1, sizeof(Pessoa));
	p->nome = calloc(0, sizeof(char));
}

void clearBuffer()
{
	char trash[2] = {0};
	fgets(trash, 2, stdin);
}