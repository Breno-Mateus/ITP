#include <stdio.h>
#include <stdlib.h>

struct Produto{
  char nome[50];
  float preco;
};

int main(){

  struct Produto *carrinho = NULL;
  int n;
  float total = 0.0;

  printf("Quantos produtos você deseja cadastrar?");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Quantidade invalida.\n");
    return 1;
  }

  carrinho = (struct Produto*) malloc(n * sizeof(struct Produto));

  if(carrinho == NULL){
    printf("Erro de alocação!\n");
    return 1;
  }

  for(int i = 0; i < n; i++) printf("%s - %d \n", carrinho[i].nome, carrinho[i].preco);

  printf("\n--- Cadastro de Produtos ---\n");
  for(int i = 0; i < n; i++){
    printf("Produto %d:\n", i + 1);

    printf("Nome: ");
    scanf("%s", carrinho[i].nome);
    printf("Preço: ");
    scanf("%f", &carrinho[i].preco);
  };

  printf("\n--- Nota Fiscal ---\n");
  for (int i = 0; i < n; i++) {
    printf("%d. %-15s R$ %.2f\n", i+1, carrinho[i].nome, carrinho[i].preco);
    total += carrinho[i].preco;
  }
  
  printf("---------------------------\n");
  printf("TOTAL A PAGAR:      R$ %.2f\n", total);

  free(carrinho);
  carrinho = NULL;

  return 0;
}