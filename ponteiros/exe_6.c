/*Crie uma função processarVetor que recebe um vetor, seu tamanho e um ponteiro para uma função. A processarVetor deve aplicar a função recebida a cada elemento do vetor.*/

#include <stdio.h>

// --- Funções de operação ---
int dobrar(int x) {
    return x * 2;
}

int triplicar(int x) {
    return x * 3;
}

int zerar(int x) {
    return 0;
}
// ----------------------------

// 1. Defina um "apelido" (typedef) para um ponteiro de função
//    que recebe um 'int' e retorna um 'int'.
// Dica: typedef int (*nome_do_tipo)(int);

// Seu código aqui...
typedef int (*Operacao)(int);


/**
 * @brief Aplica uma função a cada elemento de um vetor.
 * @param v O vetor a ser modificado.
 * @param tam O tamanho do vetor.
 * @param func O ponteiro para a função a ser aplicada.
 */
void processarVetor(int v[], int tam, Operacao func) {
    // 2. Percorra o vetor
    for (int i = 0; i < tam; i++) {
        // 3. Chame a função 'func' passando o elemento do vetor,
        //    e armazene o resultado de volta no vetor.
        // Dica: v[i] = func(v[i]);
        
        // Seu código aqui...
    }
}

void imprimirVetor(int v[], int tam, char *titulo) {
    printf("%s: [ ", titulo);
    for(int i=0; i<tam; i++) printf("%d ", v[i]);
    printf("]\n");
}

int main() {
    int meuVetor[] = {1, 2, 3, 4, 5};
    int tamanho = 5;

    imprimirVetor(meuVetor, tamanho, "Original");

    // 4. Chame 'processarVetor' passando a função 'dobrar'
    //    (O nome da função é naturalmente um ponteiro para ela)
    
    // Seu código aqui...
    // processarVetor( ... , dobrar);
    imprimirVetor(meuVetor, tamanho, "Dobrado ");

    // 5. Chame 'processarVetor' de novo, agora passando 'triplicar'
    //    (Note que você está aplicando no vetor JÁ dobrado)
    
    // Seu código aqui...
    // processarVetor( ... , triplicar);
    imprimirVetor(meuVetor, tamanho, "Triplicado");
    
    return 0;
}