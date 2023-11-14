#include <stdio.h>

void bubleSort(int, int[]);
void printArray(int, int[]);

int main(void) {
  int size;
  scanf("%d", &size);
  int array[size];

  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
  printArray(size, array);
  bubleSort(size, array);
  return 0;
}

void bubleSort(int n, int array[n]) {
  int troca;
  do {
    troca = 0;
    for (int i = 1; i < n; i++) {
      if (array[i - 1] > array[i]) {
        int aux = array[i - 1];
        array[i - 1] = array[i];
        array[i] = aux;
        troca++;
      }
    }
    if (troca != 0) {
      printArray(n, array);
    } else {
      break;
    }
  } while (1);
}

void printArray(int n, int array[n]) {
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      printf("%d", array[i]);
    } else {
      printf(" %d", array[i]);
    }
  }
  printf("\n");
}