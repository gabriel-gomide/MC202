/*
Primeiro a entrar é o primeiro a sair
*/

/*
Implementação com lista ligada
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista *p_no;

struct lista{
    int dado;
    p_no prox;
};

typedef struct fila *p_fila;

struct fila
{
   p_no ini, fim;
};

p_fila criar_fila(){
    p_fila f;
    f = malloc(sizeof(struct fila));
    (*f).ini = NULL;
    (*f).fim = NULL;
    return f;
}

void enfileira(p_fila f, int x){
    p_no novo;
    novo = malloc(sizeof(struct fila));
    (*novo).dado = x;
    (*novo).prox = NULL;
    if ((*f).ini == NULL){
        (*f).ini =  novo;
    }

    else{
        (*f).fim->prox = novo;
    }
    (*f).fim = novo;
}

int desenfileira(p_fila f){
    p_no primeiro = (*f).ini;
    int x = (*primeiro).dado;
    (*f).ini =f->ini->prox;
    if ((*f).ini == NULL){
        (*f).fim = NULL;
    }
    free(primeiro);
    return x;

}


void destruir_lista(p_no lista){
    if (lista != NULL){
        destruir_lista((*lista).prox);
        free(lista);
    }
}


void destruir_fila(p_fila f){
    destruir_lista((*f).ini);
    free(f);
}

