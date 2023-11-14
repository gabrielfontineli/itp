#include <stdio.h>

int testa_divisor(int numero, int divisor){
  if (numero % divisor == 0) {
    return 1;
  } else {
    return 0;
  }
}
int soma_divisores(int value){
  int soma = 0;
  for (int i = 1; i < value; i++) {
    if (testa_divisor(value, i)) {
      soma += i;
    }
  }
  return soma;
}
int testa_amigos(int a, int b){
  if (a != b && soma_divisores(a) == b && soma_divisores(b) == a) {
    return 1;
  } else {
    return 0;
  }
}
int main(){
  int a, b, c, d;
  int amigosEncontrados = 0;

  scanf("%d %d %d %d", &a, &b, &c, &d);
  for (int i = a; i <= b; i++) {
    for (int j = c; j <= d; j++) {
      if (testa_amigos(i, j)) {
        amigosEncontrados++;
        printf("O %d possui um amigo!\n", i);
      }
    }
  }
    if (amigosEncontrados == 0) {
        printf("Os intervalos nao apresentam amigos!\n");
    }

  
  return 0;
}