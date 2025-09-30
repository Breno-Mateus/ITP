//Crie um programa que preencha uma matriz 3x3 com valores inteiros e, em seguida, a imprima na tela no formato de matriz.

#include <stdio.h>

int main() {

    int matriz[3][3];
    
    printf("Digite os valores inteiros para a matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("\nMatriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
  
}