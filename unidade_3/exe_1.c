#include <stdio.h>
#include <stdlib.h>

enum TipoForma { CIRCULO, RETANGULO };

union Dimensoes {
  float raio;
  float lados[2];
};

struct Forma {
  char cor[20];
  enum TipoForma tipo;
  union Dimensoes medida;
  float area_calculada;
};

void calcularArea(struct Forma *f){
  
  if(f->tipo == 0){
    f->area_calculada = 3.14 * (f->medida.raio * f->medida.raio);
  } else {
    f->area_calculada = f->medida.lados[0] * f->medida.lados[1];
  }

}

int main(){
  
  int n;

  printf("Quantas formas deseja desenhar? ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Quantidade invalida.\n");
    return 1;
  }

  struct Forma *vetor = (struct Forma*) malloc(n * sizeof(struct Forma));

  if(vetor == NULL){
    printf("Erro de alocação!\n");
    return 1;
  }

  for(int i = 0; i < n; i++){
    printf("---- Figura %d ---- \n", i+1);
    printf("Qual a cor? ");
    scanf("%s", vetor[i].cor);

    printf("Qual o tipo? (0 - CIRCULO; 1 - RETANGULO) ");
    scanf("%d", (int*)&vetor[i].tipo);

    if(vetor[i].tipo == 0){
      printf("Qual o valor do raio? ");
      scanf("%f", &vetor[i].medida.raio); 
    } else {
      printf("Qual o valor da largura? ");
      scanf("%f", &vetor[i].medida.lados[0]);
      printf("Qual o valor da altura? ");
      scanf("%f", &vetor[i].medida.lados[1]);
    }
  }

  for(int i = 0; i < n; i++){
    calcularArea(&vetor[i]);
    printf("Forma %d: Cor %s | Área: %f \n", vetor[i].tipo, vetor[i].cor, vetor[i].area_calculada);
  }

  free(vetor);
  vetor = NULL;
  
  return 0;
}