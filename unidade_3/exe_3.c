#include <stdio.h>
#include <stdlib.h>

struct Musica {
  char titulo[50];
  char artista[30];
  int duracao_segundos;
};

struct Playlist {
  char nome[50];
  int qtd_musicas;
  struct Musica *lista_musicas;
};

void montarPlaylist(struct Playlist *p){
  printf("Qual o nome da playlist? ");
  scanf("%[^\n]", p->nome);

  printf("Quantas músicas a playlist terá: ");
  scanf("%d", &p->qtd_musicas);

  p->lista_musicas = (struct Musica*) malloc(p->qtd_musicas * sizeof(struct Musica));
  
  if(p->lista_musicas == NULL){
    printf("Erro de alocação!\n");
    exit(1);
  }

  for(int i = 0; i < p->qtd_musicas; i++){
    printf("--- Música %d ---\n", i+1);
    printf("Título: ");
    scanf(" %[^\n]", p->lista_musicas[i].titulo);
    printf("Artista: ");
    scanf(" %[^\n]", p->lista_musicas[i].artista);
    printf("Duração: ");
    scanf("%d", &p->lista_musicas[i].duracao_segundos);
  }
};

void exibirPlaylist(struct Playlist *p){
  int tempoTotalSegundos = 0;
  
  printf("--- Músicas da playlist %s ---\n", p->nome);
  
  for(int i = 0; i < p->qtd_musicas; i++){    
    printf("%d. %s - %s\n", i+1, p->lista_musicas[i].titulo, p->lista_musicas[i].artista);
    
    tempoTotalSegundos += p->lista_musicas[i].duracao_segundos;
  }

  int minutos = tempoTotalSegundos / 60;
  int segundos = tempoTotalSegundos % 60;

  printf("--- Tempo Total: %d minutos e %d segundos ---\n", minutos, segundos);
};

int main(){

  struct Playlist minhaPlaylist;

  montarPlaylist(&minhaPlaylist);

  exibirPlaylist(&minhaPlaylist);

  free(minhaPlaylist.lista_musicas);

  minhaPlaylist.lista_musicas = NULL;

  return 0;
}