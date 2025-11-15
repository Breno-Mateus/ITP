#include <stdio.h>
#include <string.h>

struct Aluno{
  char nome[50];
  float notas[3];
  float media;
};

void calcularMedias(struct Aluno turma[], int tam){
  
  float soma = 0.0;

  for(int i = 0; i < tam; i++){
    for(int j = 0; j < tam; j++){
       soma = turma[i].notas[j] + soma;
    }

    turma[i].media = soma / 3;

    soma = 0.0;
  }

}

struct Aluno* encontrarDestaque(struct Aluno turma[], int tam){
  
  struct Aluno *alunoDestaque = &turma[0];

  for(int i = 1; i < tam; i++){
    if(turma[i].media > alunoDestaque->media){
      alunoDestaque = &turma[i];
    }
  }

  return alunoDestaque;
}

int main(){
  
  struct Aluno turma[3];

  //aluno 0
  strcpy(turma[0].nome, "Ana");
  turma[0].notas[0] = 10.0;
  turma[0].notas[1] = 8.0;
  turma[0].notas[2] = 7.0;
  turma[0].media = 0.0;

  //aluno 1
  strcpy(turma[1].nome, "Breno");
  turma[1].notas[0] = 5.0;
  turma[1].notas[1] = 6.5;
  turma[1].notas[2] = 7.5;
  turma[1].media = 0.0;
  
  //aluno 2
  strcpy(turma[2].nome, "Carla");
  turma[2].notas[0] = 9.0;
  turma[2].notas[1] = 9.5;
  turma[2].notas[2] = 10.0;
  turma[2].media = 0.0;

  calcularMedias(turma, 3);

  struct Aluno *destaque = encontrarDestaque(turma, 3);

  for(int i = 0; i < 3; i++){
    printf("Media do aluno %d: %f \n", i, turma[i].media);
  }

  printf("O aluno(a) destaque foi %s!!!!", destaque->nome);

  return 0;

}