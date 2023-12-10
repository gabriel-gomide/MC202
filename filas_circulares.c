#include <stdio.h>
#include <stdlib.h>

typedef struct fila *p_fila;

struct fila {
    int *v;
    int ini, fim, N, tamanho;

};

p_fila criar_fila(int N) {
    p_fila f;
    f = malloc(sizeof(struct fila));
    f->v = malloc(N * sizeof(int));
    f->ini = 0;
    f->fim = 0;
    f->N = N;
    f->tamanho = 0;
    return f;
}
void enfileira(p_fila f, int x) {
 f->v[f->fim] = x;
 f->fim = (f->fim + 1) % f->N;
 f->tamanho++;
 }

 
int desenfileira(p_fila f){
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->N;
    f->tamanho --;
    return x;
}