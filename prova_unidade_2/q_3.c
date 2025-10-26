#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIAS 7
#define HORAS 24

void gerar_temperaturas(float T[DIAS][HORAS]) {
    for (int i = 0; i < DIAS; i++) {
        for (int j = 0; j < HORAS; j++) {
            T[i][j] = (rand() / (float)RAND_MAX) * 60.0;
        }
    }
}

void exibir_matriz(float T[DIAS][HORAS]) {
    for (int i = 0; i < DIAS; i++) {
        for (int j = 0; j < HORAS; j++) {
            printf("%4.1f ", T[i][j]); 
        }
        printf("\n");
    }
}

void calcular_medias(float T[DIAS][HORAS], float medias[DIAS]) {
    for (int i = 0; i < DIAS; i++) {
        float soma_dia = 0.0;
        for (int j = 0; j < HORAS; j++) {
            soma_dia += T[i][j];
        }
        medias[i] = soma_dia / HORAS;
    }
}

int dia_mais_quente(float medias[DIAS]) {
    int indice_maior = 0;
    float maior_media = medias[0];

    for (int i = 1; i < DIAS; i++) {
        if (medias[i] > maior_media) {
            maior_media = medias[i];
            indice_maior = i;
        }
    }
    return indice_maior;
}

int dia_mais_frio(float medias[DIAS]) {
    int indice_menor = 0;
    float menor_media = medias[0];

    for (int i = 1; i < DIAS; i++) {
        if (medias[i] < menor_media) {
            menor_media = medias[i];
            indice_menor = i;
        }
    }
    return indice_menor;
}

void menor_e_maior_temperatura(float T[DIAS][HORAS],
                               int *diaMin, int *horaMin, float *menor,
                               int *diaMax, int *horaMax, float *maior)
{
    *menor = T[0][0];
    *diaMin = 0;
    *horaMin = 0;

    *maior = T[0][0];
    *diaMax = 0;
    *horaMax = 0;

    for (int i = 0; i < DIAS; i++) {
        for (int j = 0; j < HORAS; j++) {            
            if (T[i][j] < *menor) {
                *menor = T[i][j];
                *diaMin = i;
                *horaMin = j;
            }

            if (T[i][j] > *maior) {
                *maior = T[i][j];
                *diaMax = i;
                *horaMax = j;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    float T[DIAS][HORAS];
    float medias_diarias[DIAS];

    gerar_temperaturas(T);

    printf("--- MATRIZ DE TEMPERATURAS (Dia x Hora) ---\n");
    exibir_matriz(T);

    calcular_medias(T, medias_diarias);
    printf("\n--- MÉDIAS DIÁRIAS ---\n");
    for (int i = 0; i < DIAS; i++) {
        printf("Media do Dia %d: %.2f °C\n", i + 1, medias_diarias[i]);
    }

    int diaQ = dia_mais_quente(medias_diarias);
    int diaF = dia_mais_frio(medias_diarias);
    
    printf("\n--- ANÁLISE DOS DIAS ---\n");
    printf("Dia mais quente (maior media): Dia %d (Media: %.2f °C)\n", diaQ + 1, medias_diarias[diaQ]);
    printf("Dia mais frio (menor media):   Dia %d (Media: %.2f °C)\n", diaF + 1, medias_diarias[diaF]);

    int diaMin, horaMin, diaMax, horaMax;
    float menorTemp, maiorTemp;

    menor_e_maior_temperatura(T, &diaMin, &horaMin, &menorTemp, &diaMax, &horaMax, &maiorTemp);

    printf("\n--- ANÁLISE GERAL DA SEMANA ---\n");
    printf("Menor temperatura registrada: %.2f °C (Ocorreu no Dia %d, as %dh)\n", menorTemp, diaMin + 1, horaMin);
    printf("Maior temperatura registrada: %.2f °C (Ocorreu no Dia %d, as %dh)\n", maiorTemp, diaMax + 1, horaMax);

    return 0;
}