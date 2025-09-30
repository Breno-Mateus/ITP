//Crie um programa que leia 10 números inteiros, armazene-os em um vetor e, em seguida, imprima os elementos na tela.

#include <stdio.h>

int main(){

  int vetor[10];

  for (int i = 0; i < 10; i++){
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  for (int i = 0; i < 10; i++){
    printf("O %dº número é: %d\n", i + 1, vetor[i]);
  }

}