/*Escreva uma função void inverter(char *str) que inverte uma string in-place (sem criar um segundo vetor). A função deve usar apenas aritmética de ponteiros, sem usar o operador de colchetes [] para acessar os caracteres.*/

#include <stdio.h>

void inverter(char *str) {
  
    if (!str || !*str) {
        return;
    }

    char *inicio = str;
    char *fim = str;
    char temp;

    while (*fim) {
        fim++;
    }
    
    fim--;

    while (inicio < fim) {
        
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }

}

int main() {
  
  char palavra[] = "breno";

  printf("Palavra antes: %s\n", palavra);

  inverter(palavra);

  printf("Palavra depois: %s\n", palavra);

  return 0;
}