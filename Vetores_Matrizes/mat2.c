//Faça um programa que leia duas matrizes 2x3 de números reais e calcule a matriz resultante da soma das duas.

#include <stdio.h>

int main(){
  int matriz1 [2][3];
  int matriz2 [2][3];
  int soma [2][3];

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      printf("Digite o elemento [%d][%d] da matriz 1:", i, j);
      scanf("%d", &matriz1[i][j]);
      printf("Digite o elemento [%d][%d] da matriz 2:", i, j);
      scanf("%d", &matriz2[i][j]);
    }
  }

  for(int i=0; i<2; i++){
    for(int j=0; j<3; j++){
      soma[i][j] = matriz1[i][j] + matriz2[i][j];
    }
  }

  printf("A soma da matriz 1 e 2 é: \n");

  for(int i=0; i<2; i++){
    for(int j=0; j<3; j++){
      printf("%d ", soma[i][j]);
    }
    printf("\n");
  }
}