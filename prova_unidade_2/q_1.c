#include <stdio.h>
#include <ctype.h>

void contar(char texto[], int i, int *vogais, int *consoantes) {

    if (texto[i] == '\0') {
        return;
    }
    
    char c = texto[i];

    if (isalpha(c)) {
        c = tolower(c);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            (*vogais)++;
        } else {
            (*consoantes)++;
        }
    }

    contar(texto, i + 1, vogais, consoantes);
}


int main() {
    char texto[101];
    int total_vogais = 0;
    int total_consoantes = 0;

    printf("Digite uma palavra ou frase (até 100 caracteres):\n");
    scanf("%100[^\n]", texto);

    contar(texto, 0, &total_vogais, &total_consoantes);

    printf("\n--- Resultado ---\n");
    printf("Total de Vogais: %d\n", total_vogais);
    printf("Total de Consoantes: %d\n", total_consoantes);

    return 0;
}