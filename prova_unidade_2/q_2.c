#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIAS 30

void gerarDados(float chuva[], float pressao[], int tam) {
    for (int i = 0; i < tam; i++) {
        chuva[i] = (float)(rand() % 101);
        pressao[i] = (float)(rand() % 71 + 980);
    }
}

void exibirVetor(float vetor[], int tam, char* nome) {
    printf("%s:\n[ ", nome);
    for (int i = 0; i < tam; i++) {
        printf("%.0f ", vetor[i]);
    }
    printf("]\n");
}

float calcularMedia(float vetor[], int tam) {
    float soma = 0.0;
    for (int i = 0; i < tam; i++) {
        soma += vetor[i];
    }
    return soma / tam;
}

void encontrarMaior(float vetor[], int tam, char* nome) {
    float maiorValor = vetor[0];
    int diaMaior = 1;

    for (int i = 1; i < tam; i++) {
        if (vetor[i] > maiorValor) {
            maiorValor = vetor[i];
            diaMaior = i + 1;
        }
    }
    printf("Dia de maior %s: %d (Valor: %.0f)\n", nome, diaMaior, maiorValor);
}

void encontrarMenor(float vetor[], int tam, char* nome) {
    float menorValor = vetor[0];
    int diaMenor = 1;

    for (int i = 1; i < tam; i++) {
        if (vetor[i] < menorValor) {
            menorValor = vetor[i];
            diaMenor = i + 1;
        }
    }
    printf("Dia de menor %s: %d (Valor: %.0f)\n", nome, diaMenor, menorValor);
}

int contarDiasEspeciais(float chuva[], float pressao[], int tam, float mediaChuva, float mediaPressao) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (chuva[i] > mediaChuva && pressao[i] < mediaPressao) {
            contador++;
        }
    }
    return contador;
}


int main() {
    srand(time(NULL));

    float chuva[DIAS];
    float pressao[DIAS];
    
    gerarDados(chuva, pressao, DIAS);

    printf("--- DADOS GERADOS ---\n");
    exibirVetor(chuva, DIAS, "Chuva (mm)");
    exibirVetor(pressao, DIAS, "Pressao (hPa)");
    
    printf("\n--- ANALISES ---\n");

    float mediaChuva = calcularMedia(chuva, DIAS);
    float mediaPressao = calcularMedia(pressao, DIAS);
    printf("Media de Chuva: %.2f mm\n", mediaChuva);
    printf("Media de Pressao: %.2f hPa\n", mediaPressao);

    encontrarMaior(chuva, DIAS, "chuva");
    encontrarMenor(pressao, DIAS, "pressao");

    int diasEspeciais = contarDiasEspeciais(chuva, pressao, DIAS, mediaChuva, mediaPressao);
    printf("Dias com chuva acima da media E pressao abaixo da media: %d\n", diasEspeciais);

    return 0;
}