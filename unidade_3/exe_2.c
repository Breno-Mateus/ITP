#include <stdio.h>
#include <stdlib.h>

enum Classe { GUERREIRO, MAGO };

union Atributo {
  int forca;
  int inteligencia;
};

struct Habilidade {
  char nome[30];
  enum Classe tipo;
  union Atributo dados;
};

void lançarHabilidade(struct Habilidade *h){

  int dano = 0;

  if(h->tipo == GUERREIRO){
    dano = h->dados.forca * 5;
  } else {
    dano = h->dados.inteligencia * 10;
  }

  printf("Habilidade %s lançada! Dano causado: %d \n", h->nome, dano);

}

int main(){
  
  int n;

  printf("Quantas habilidades deseja cadastrar? ");
  scanf("%d", &n);

  if(n <= 0){
    printf("Valor inválido!");
    return 1;
  }

  struct Habilidade *h = (struct Habilidade*) malloc(n * (sizeof(struct Habilidade)));

  if(h == NULL){
    printf("Erro de alocação!\n");
    return 1;
  }

  for(int i = 0; i < n; i++){
    printf("--- Habilidade %d ---\n", i+1);
    
    printf("Nome da habilidade: ");
    scanf(" %[^\n]", h[i].nome);

    printf("Tipo (0 - GUERREIRO; 1 - MAGO): ");
    scanf("%d", (int*)&h[i].tipo);

    if(h[i].tipo == GUERREIRO){
      printf("Digite a força: ");
      scanf("%d", &h[i].dados.forca);
    } else{
      printf("Digite a inteligência: ");
      scanf("%d", &h[i].dados.inteligencia);
    }
  }

  for(int i = 0; i < n; i++){
    lançarHabilidade(&h[i]);
  }

  free(h);
  h = NULL;

  return 0;
}
