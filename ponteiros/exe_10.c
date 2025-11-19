#include <stdio.h>
#include <string.h>

enum TipoVeiculo {CARRO, CAMINHAO};

union Especificacoes {
  int num_passageiros;
  float capacidade_carga;
};

struct Veiculo {
  char placa[10];
  enum TipoVeiculo tipo;
  union Especificacoes specs;
};


void imprimirRelatorio(struct Veiculo *v){

}

int main(){

  struct Veiculo frota[3];

  //veiculo 1
  strcpy(frota[0].placa, "ABC-123");
  frota[0].tipo = 0;
  frota[0].specs.num_passageiros = 5;

  //veiculo 2
  strcpy(frota[1].placa, "DEF-456");
  frota[1].tipo = 1;
  frota[1].specs.capacidade_carga = 12.5;

  //veiculo 3
  strcpy(frota[0].placa, "GHI-789");
  frota[0].tipo = 0;
  frota[0].specs.num_passageiros = 2;

  return 0;
}