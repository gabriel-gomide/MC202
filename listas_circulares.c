#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;

struct no{
    int dado;
    p_no prox;
};

p_no inserir_circular(p_no lista, int x) {
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo->dado = x;
    if (lista == NULL) {
        novo->prox = novo;
        lista = novo;
    } 
    else {
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return lista;
}

p_no remover_circular(p_no lista, p_no no) {
    p_no ant;
    if (no->prox == no) {
        free(no);
        return NULL;
    }
    for(ant = no->prox; ant->prox != no; ant = ant->prox);
    ant->prox = no->prox;
    if (lista == no)
        lista = ant;
    free(no);
    return lista;
}

void imprimir_lista_circular(p_no lista){
    p_no p;
    p = lista->prox;
    do {
        printf("%d\n", p->dado);
        p = p->prox;
        } while (p != lista->prox);
}


p_no inserir_circular2(p_no lista, int x) {
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo->dado = x;
    novo->prox = lista->prox;
    return lista;
}

p_no remover_circular2(p_no lista, p_no no){
    p_no ant;
    for(ant = no->prox; ant->prox != no; ant = ant->prox);
    ant->prox = no->prox;
    free(no);
    return lista;
}
