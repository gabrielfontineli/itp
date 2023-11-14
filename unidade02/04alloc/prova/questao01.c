#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int nlin, ncol;
  int **mat;
} Matrix;

Matrix *createMatrix(int, int);
void readMatrix(Matrix *m);
void printMatrix(Matrix *m);
void destroyMatrix(Matrix **m);

int main() {
  int lin, col;
  Matrix *mat;
  scanf("%i %i", &lin, &col);
  mat = createMatrix(lin, col);
  readMatrix(mat);
  printMatrix(mat);

  destroyMatrix(&mat);

  if (mat == NULL) {
    printf("OK\n");
  }
  return 0;
}

void destroyMatrix(Matrix **mat) {
  for (int i = 0; i < (*mat)->nlin; i++) {
    free((*mat)->mat[i]);
  }

  free((*mat)->mat);
  free(*mat);
  *mat = NULL;
}

void printMatrix(Matrix *m) {
  for (int i = 0; i < m->nlin; i++) {
    for (int j = 0; j < m->ncol; j++) {
      printf("%d ", m->mat[i][j]);
    }
    printf("\n");
  }
}

void readMatrix(Matrix *m) {
  for (int i = 0; i < m->nlin; i++) {
    for (int j = 0; j < m->ncol; j++) {
      scanf("%d", &m->mat[i][j]);
    }
  }
}

Matrix *createMatrix(int l, int c) {
  Matrix *mat;
  mat = calloc(1, sizeof(Matrix));
  mat->nlin = l;
  mat->ncol = c;
  mat->mat = calloc(l, sizeof(int *));
  for (int i = 0; i < l; i++) {
    mat->mat[i] = calloc(c, sizeof(int));
  }
  return mat;
}