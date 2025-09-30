//Escreva um programa que leia um vetor de 8 posições e, em seguida, o escreva na ordem inversa.

#include <stdio.h>

int main() {
    int vetor[8];

    for (int i = 0; i < 8; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Vetor na ordem inversa:\n");
    for (int i = 7; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}