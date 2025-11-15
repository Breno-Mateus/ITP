/*Escreva um programa que crie um vetor dinâmico de estruturas struct Aluno. O programa deve primeiro perguntar ao usuário quantos alunos ele deseja cadastrar. Em seguida, deve alocar a memória exata para esse número de alunos, preencher os dados de cada um e, no final, exibi-los e liberar a memória.*/

#include <stdio.h>
#include <stdlib.h> // Para malloc() e free()

struct Aluno {
    int matricula;
    float nota;
};

int main() {
    int n; // Número de alunos
    struct Aluno *vetor_dinamico;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    // 1. Alocação Dinâmica de Memória
    // Use malloc para alocar espaço para 'n' estruturas do tipo Aluno.
    // Lembre-se de usar sizeof()
    
    // Seu código aqui...
    // vetor_dinamico = (struct Aluno*) malloc( ... );

    // 2. Verifique se a alocação falhou (malloc retorna NULL)
    if (vetor_dinamico == NULL) {
        printf("Erro: Falha na alocacao de memoria!\n");
        return 1; // Termina o programa com erro
    }

    // 3. Preenchimento dos dados (usando um loop for)
    printf("--- Cadastro de Alunos ---\n");
    for (int i = 0; i < n; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("  Matricula: ");
        
        // Cuidado aqui!
        // Como 'vetor_dinamico' é um ponteiro, você NÃO pode usar '.'
        // Você tem duas opções (use a que preferir):
        // Opção A (Padrão): (vetor_dinamico[i]).matricula
        // Opção B (Aritmética): (vetor_dinamico + i)->matricula
        
        // Seu código aqui... (scanf para matricula e nota)
    }

    // 4. Exibição dos dados
    printf("\n--- Alunos Cadastrados ---\n");
    for (int i = 0; i < n; i++) {
        // Use a mesma lógica do passo 3 para exibir os dados
        printf("Aluno %d | Matricula: %d | Nota: %.1f\n",
            i + 1,
            (vetor_dinamico + i)->matricula,
            (vetor_dinamico + i)->nota
        );
    }

    // 5. Liberação da Memória (ESSENCIAL!)
    // Use free() para devolver a memória que você pegou com malloc()
    
    // Seu código aqui...

    return 0;
}