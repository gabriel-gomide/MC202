#include <stdio.h>
#include <stdlib.h>

// Definição de nó
/*
p_no é um apelido de ponteiro para struct no
usamos typedef com ponteiro antes da struct
assim, usamos p_no dentro do registro
*/

typedef struct no *p_no;

struct no{
    int dado;
    p_no prox;
};

//cria uma lista vazia
p_no criar_lista(){
    return NULL;
}

p_no copiar_lista(p_no lista){
    p_no novo;
    if (lista == NULL)
        return NULL;
    novo = malloc(sizeof(struct no));
    (*novo).dado = (*lista).dado;
    (*novo).prox = copiar_lista((*lista).prox);
    return novo;
}

//adicionando novo elemento
p_no adicionar_elemento(p_no lista, int x){
    p_no novo;
    novo = malloc(sizeof(struct no));
    (*novo).dado = x;
    (*novo).prox = lista;
    return novo;
}

p_no busca(p_no lista, int x){
    p_no atual;
    for (atual = lista; atual != NULL; atual = atual->prox){
        if ((*atual).dado == x){
            return atual;
        }
    }
    return NULL;
}
// terminar aqui
void remove1(p_no lista, int x){
    p_no atual;
    for (atual = lista; atual != NULL; atual = atual->prox){
        if ((*atual).dado == x){
            
        }
    }
    return NULL;
}

void imprime(p_no lista){
    p_no atual;
    for (atual = lista; atual != NULL; atual = atual->prox){
        printf("%d\n", atual->dado);
    }
}

//destruindo a lista recursivamente
void destruir_lista(p_no lista){
    if (lista != NULL){
        destruir_lista((*lista).prox);
        free(lista);
    }
}



//destruir lista iterativa
void destruir2(p_no lista){
    while (lista != NULL) {
        p_no temp = lista; 
        lista = lista->prox; 
        free(temp); 
    }
}
int main(){
    int num;
    p_no lista;
    p_no teste;
    lista = criar_lista();
    do {
        scanf("%d", &num);
        if (num > 0){
            lista = adicionar_elemento(lista, num);
        }
    } while (num>0);
    teste = busca(lista, 3);
    imprime(teste);
    destruir_lista(lista);
    return 0;
}
