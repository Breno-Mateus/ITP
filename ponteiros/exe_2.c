/*Crie uma função chamada minMax que recebe um vetor de inteiros, seu tamanho, e os endereços de duas variáveis (que estarão na main) chamadas min e max. A função deve percorrer o vetor e armazenar o menor e o maior valor encontrado nas variáveis min e max da função main.*/

#include <stdio.h>

void minMax(int vetor[], int tamanho, int *menor, int *maior) {
  
  int auxMenor = vetor[0];
  int auxMaior = vetor[0];

  for (int i = 0; i < tamanho; i++) {
    
    if (vetor[i] < auxMenor) {
      auxMenor = vetor[i];
    }

    if (vetor[i] > auxMaior) {
      auxMaior = vetor[i];
    }
  }

  *menor = auxMenor;
  *maior = auxMaior;
}


int main() {
  
  int vetor[] = {5, 6, 3, 7, 1};
  int tamanho = 5;

  int min, max;

  minMax(vetor, tamanho, &min, &max);

  printf("O menor valor (%d) e o maior valor (%d)", min, max);

  return 0;
}