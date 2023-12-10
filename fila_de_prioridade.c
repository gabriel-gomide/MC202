#include <stdio.h>
#include <stdlib.h>

/*
Duas operações básicas:
Inserir um elemento
Remover o elemento com maior chave (prioridade)

Árvore binária completa: Todos os niveis exceto o último estão cheios
e o os nós do último nível estão o mais a esquerda possível

Representar usando vetores, não precisamos de ponteiros
Pensar um vetor como se fosse uma árvore

O filho esquerdo de v[i] é v[2*i+1] e o filho dierito é v[2*i + 2]
O pai é v[(i-1)/2]

Heap (de máximo): Uma arvoré binária completa, implementada com vetores,
em que os filhos são menores ou iguais ao pai, logo a raiz é sempre o
máximo.
Para inserir, basta colocar no final e trocando com o pai
se necessário

*/

typedef struct
{
    char nome[20];
    int chave;
} Item;

typedef struct
{
    Item *v;
    int n, tamanho;
} FP;

typedef FP *p_fp;

#define PAI(i) ((i - 1) / 2)
#define F_ESQ(i) (2 * i + 1)
#define F_DIR(i) (2 * i + 2)

// Função troca, SERÁ MUITO UTILIZADA
void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

p_fp criar_filaprio(int tam)
{
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam * sizeof(Item));
    fprio->n = 0;
    fprio->tamanho = tam;
    return fprio;
}

void sobe_no_heap(p_fp fprio, int k)
{
    if (k > 0 && fprio->v[PAI(k)].chave < fprio->v[k].chave)
    {
        troca(&fprio->v[k], &fprio->v[PAI(k)]);
        sobe_no_heap(fprio, PAI(k));
    }
}

void desce_no_heap(p_fp fprio, int k)
{
    int maior_filho;
    if (F_ESQ(k) < fprio->n)
    {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < fprio->n && fprio->v[F_ESQ(k)].chave < fprio->v[F_DIR(k)].chave)
        {
            maior_filho = F_DIR(k);
        }
        if (fprio->v[k].chave < fprio->v[maior_filho].chave)
        {
            troca(&fprio->v[k], &fprio->v[maior_filho]);
            desce_no_heap(fprio, maior_filho);
        }
    }
}

void insere(p_fp fprio, Item item)
{
    fprio->v[fprio->n] = item;
    fprio->n++;
    sobe_no_heap(fprio, fprio->n - 1);
}

Item extrai_maximo(p_fp fprio)
{
    Item item = fprio->v[0];
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
    return item;
}

void muda_prioridade(p_fp fprio, int k, int valor)
{
    if (fprio->v[k].chave < valor)
    {
        fprio->v[k].chave = valor;
        sobe_no_heap(fprio, k);
    }
    else
    {
        fprio->v[k].chave = valor;
        desce_no_heap(fprio, k);
    }
}
