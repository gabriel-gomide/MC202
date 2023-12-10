#include <stdio.h>
#include <stdlib.h>
/*Implementação com filas ligadas*/
typedef struct no *p_no;

struct no
{
    int dado;
    p_no prox;
};

typedef struct pilha *p_pilha;

struct pilha
{
    p_no topo;
};

// Estrutura de um nó na pilha, utilizado para armazenar os caminhos percorridos na floresta.
typedef struct NoPilha {
    int poder; // valor numérico que representa o poder de um monstro.
    struct NoPilha *prox; // ponteiro para o próximo elemento na pilha.
} NoPilha, *p_no_pilha;

void empilhar(p_pilha pilha, int x)
{
    p_no novo = malloc(sizeof(struct no));
    novo->dado = x;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(p_pilha pilha)
{
    p_no topo = pilha->topo;
    int x = topo->dado;
    pilha->topo = pilha->topo->prox;
    free(topo);
    return x;
}

p_no_pilha insere_na_pilha(p_no_pilha topo, int poder){
    p_no_pilha novo = malloc(sizeof(struct NoPilha));
    novo->poder = poder;
    novo->prox = topo;
    topo = novo;
    return topo;
 
}

/*
  Remove o elemento do topo da pilha, utilizado quando o personagem retrocede um passo.
  topo: ponteiro para o topo da pilha.
  poder: endereço de uma variável onde o poder do monstro removido será armazenado.
  Retorna um ponteiro para o novo topo da pilha.
 */
p_no_pilha remove_da_pilha(p_no_pilha topo, int *poder){
    p_no_pilha retirado = topo;
    *poder = topo->poder;
    topo = topo -> prox;
    free(retirado);
    return topo;
}

/*
  Imprime o conteúdo atual da pilha, utilizado para depuração e visualização dos caminhos.
  topo: ponteiro para o topo da pilha.
 */
void imprime_pilha(p_no_pilha topo){
    int impresso;
    while (topo->prox != NULL){
        impresso = topo -> poder;
        printf("%d\n", impresso);
        topo = topo -> prox;
    }
}


int main(){
    int x;
    p_no_pilha pilha;
    p_no_pilha teste = NULL;

    pilha = insere_na_pilha(pilha, 3);
    pilha = insere_na_pilha(pilha, 5);
    imprime_pilha(pilha);
    teste = pilha;
    imprime_pilha(teste);
    pilha = remove_da_pilha(pilha, &x);
    printf("%d\n", x);
    
    return 0;
}