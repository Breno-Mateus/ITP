#include <stdio.h>
#include <stdlib.h>

enum Status { DISPONIVEL, EMPRESTADO };

struct Livro {
    int id;
    char titulo[50];
    enum Status status;    
};

struct Usuario {
    char nome[50];
    int qtd_emprestimos;
    int capacidade_maxima;
    struct Livro **emprestimos;
};

struct Livro* buscarLivro(struct Livro acervo[], int n_livros, int id_busca){
    for(int i = 0; i < n_livros; i++){
        if(acervo[i].id == id_busca){
            return &acervo[i];
        }
    }
    return NULL;        
}

int realizarEmprestimo(struct Usuario *u, struct Livro *l){
    if(l != NULL){
        if(l->status == DISPONIVEL){
            if(u->qtd_emprestimos < u->capacidade_maxima){
                l->status = EMPRESTADO;
                u->emprestimos[u->qtd_emprestimos] = l;
                u->qtd_emprestimos++;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}


int main(){

    int n_livros;

    printf("--- Cadastro de Livros ---\n");

    printf("Quantos livros no acervo? ");
    scanf("%d", &n_livros);

    struct Livro *acervo = (struct Livro*) malloc(n_livros * sizeof(struct Livro));

    for(int i = 0; i < n_livros; i++){
        acervo[i].id = i + 1;
        printf("Título do livro %d: ", acervo[i].id);
        scanf(" %[^\n]", acervo[i].titulo);
        acervo[i].status = DISPONIVEL;
    }

    printf("--- Cadastro de Usuário ---\n");

    struct Usuario usuario;

    printf("Nome do usuário: ");
    scanf(" %[^\n]", usuario.nome);
    usuario.qtd_emprestimos = 0;
    usuario.capacidade_maxima = 3;
    usuario.emprestimos = (struct Livro**) malloc(usuario.capacidade_maxima * sizeof(struct Livro*));

    printf("--- Empréstimo de Livros ---\n");
    
    int id_busca;
    
    for(int i = 0; i < 5; i++){
        printf("Digite o ID do livro para empréstimo (ou 0 para sair): ");
        scanf("%d", &id_busca);

        if(id_busca == 0){
            break;
        }

        struct Livro *livro_encontrado = buscarLivro(acervo, n_livros, id_busca);

        if(realizarEmprestimo(&usuario, livro_encontrado)){
            printf("Empréstimo realizado com sucesso!\n");
        } else {
            printf("Não foi possível realizar o empréstimo.\n");
        }
    }

    printf("--- Livros Emprestados por %s ---\n", usuario.nome);
    for(int i = 0; i < usuario.qtd_emprestimos; i++){
        printf("%d. %s\n", usuario.emprestimos[i]->id, usuario.emprestimos[i]->titulo);
    }

    printf("--- Status do Acervo ---\n");
    for(int i = 0; i < n_livros; i++){
        printf("ID: %d, Título: %s, Status: %s\n", acervo[i].id, acervo[i].titulo,
               acervo[i].status == DISPONIVEL ? "Disponível" : "Emprestado");
    }

    free(acervo);
    free(usuario.emprestimos);
    
    return 0;
}