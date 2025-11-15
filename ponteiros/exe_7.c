/*Exercício: Cadastro Simples de Aluno
Objetivo: Criar um programa que armazene os dados de um aluno, calcule sua média e exiba um relatório. O programa deve ser dividido em funções e usar ponteiros para alterar os dados do aluno*/

#include <stdio.h>

struct Aluno{
  char nome[50];
  float notas[3];
  float notas_trabalhos[2][2];
  float media_final;
};

void preencherAluno(struct Aluno *a){
  printf("Digite o nome do aluno: ");
  scanf("%s", a->nome);

  printf("Cadastre as 3 notas da prova: \n");
  for(int i = 0; i < 3; i++){
    scanf("%f", &a->notas[i]);  
  }

  printf("Cadastre as 4 notas dos trabalhos: \n");
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      scanf("%f", &a->notas_trabalhos[i][j]);
    }
  }
}

void calcularMedia(struct Aluno *a){
  float soma = 0.0;

  for(int i = 0; i < 3; i++){
    soma = soma + a->notas[i];
  }

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      soma = soma + a->notas_trabalhos[i][j];
    }
  }

  a->media_final = soma / 7;
}

void imprimirAluno(struct Aluno a){
  printf("Nome: %s\n", a.nome);

  printf("Notas das provas: ");
  for(int i = 0; i < 3; i++){
    printf("%f, ", a.notas[i]);
  }

  printf("\nNotas dos trabalhos: ");
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      printf("%f, ", a.notas_trabalhos[i][j]);
    }
  }
  
  printf("\nMedia final: %f\n", a.media_final);
}

int main(){
  struct Aluno aluno1;

  preencherAluno(&aluno1);
  calcularMedia(&aluno1);
  imprimirAluno(aluno1);

  return 0;
}