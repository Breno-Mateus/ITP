/*Crie uma função redirecionar que recebe um ponteiro para ponteiro (int **q) e um novo endereço (int *novoAlvo). O objetivo da função é fazer com que o ponteiro original (que está na main) deixe de apontar para onde apontava e passe a apontar para o novoAlvo.*/

#include <stdio.h>

void redirecionar (int **q, int *novoAlvo) {
  *q = novoAlvo;
}

int main() {
  int x = 5;
  int *prt = &x;
  int **q = &prt;

  int y = 2;
  
  printf("Valor ANTES de redirecionar: %d\n", *prt);

  redirecionar(q, &y);

  printf("Valor DEPOIS de redirecionar: %d\n", *prt);

  return 0;
}