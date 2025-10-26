/*Escreva um programa que leia dois valores inteiros, A e B. Em seguida, crie dois ponteiros, ptrA e ptrB. Usando apenas os ponteiros, troque os valores armazenados em A e B. Ao final, imprima os valores de A e B para mostrar que foram trocados.*/

#include <stdio.h>

int main() {
  
  int a, b;
  int *ptrA, *ptrB;
  int aux;

  printf("Digite um valor inteiro para A:");
  scanf("%d", &a);
  printf("Digite um valor inteiro para B:");
  scanf("%d", &b);

  printf("Valores iniciais de A (%d) e B (%d)\n", a, b);

  ptrA = &a;
  ptrB = &b;
  aux = *ptrA;
  *ptrA = *ptrB;
  *ptrB = aux;
  
  printf("Valores finais de A (%d) e B (%d)", a, b);

  return 0;
}

