/* Aula 17 - Árvores Primárias 
As arvores começam na raiz e terminam nas folhas/nós terminais, então na árvore eu vou
ter um ponteiro que aponta para a raiz.
Nós não-terminais: filho esquerdo e filho direito (binário vem dele ter dois filhos)
Nomes: subarvore esquerda, descedentes 

Uma arvore é: 
1) NULL
2) NÓ conectado a duas árvores binárias

A ordem dos filhos é relevante!

Queremos saber a altura da arvores e número de nós que ela pode ter
Altura h: 
Tem no minimo h nós
Tem no máximo 2^h - 1

Implementação: Struct que guarda informações com ponteiros para outros nós
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;

struct no {
    int dado;
    p_no esq, dir; /* pai */
};

typedef struct NoArvore
{
    int poder;                  // valor numérico que representa o poder de um monstro.
    struct NoArvore *esq, *dir; // ponteiros para subárvores esquerda e direita.
} NoArvore, *p_no_arvore;


p_no_arvore buscar(p_no_arvore raiz, int poder){
    if (raiz == NULL || poder == raiz -> poder)
        return raiz;
    if (poder < raiz -> poder)
        return buscar(raiz->esq, poder);
    else
        return buscar(raiz->dir, poder);
}

p_no_arvore inserir(p_no_arvore raiz, int poder){
    p_no_arvore novo;
    if (raiz == NULL){
        novo = malloc(sizeof(NoArvore));
        novo->esq = novo ->dir = NULL;
        novo -> poder = poder;
        return novo;
    }
    if (poder < raiz -> poder)
        raiz->esq = inserir (raiz->esq, poder);
    else
        raiz->dir = inserir(raiz->dir, poder);
    return raiz;
}

p_no_arvore minimo(p_no raiz){
    if (raiz == NULL || raiz ->esq ==NULL){
        return raiz;
    }
    return minimo(raiz->esq);
}


//Raro criar arvores dessa forma
//Arvores são estruturas definidas recursivamente e muitos algoritmos serão feitos dessa maneira
p_no criar_arvore(int x, p_no esq, p_no dir){
    p_no r = malloc(sizeof(struct no));
    r ->dado=x;
    r->esq = esq;
    r->dir = dir;
    return r;
}

p_no procurar_no(p_no raiz, int x){
    p_no esq;
    if (raiz == NULL || raiz->dado == x)
        return raiz;
    esq = procurar_no(raiz->esq, x);
    if (esq!=NULL)
        return esq;
    return procurar_no(raiz->dir, x);

}

int numero_no(p_no raiz){
    if (raiz == NULL)
        return 0;

    return numero_no(raiz->esq) + numero_no(raiz->dir) + 1;

}
int numero_folhas(p_no raiz){
    if (raiz == NULL) {
        return 0; // Árvore vazia, nenhum nó folha.
    }

    if (raiz->esq == NULL && raiz->dir == NULL) {
        // O nó atual é uma folha.
        return 1;
    }

    // Recursivamente chama a função para a subárvore esquerda e direita e soma os resultados.
    int folhas_esq = numero_folhas(raiz->esq);
    int folhas_dir = numero_folhas(raiz->dir);

    return folhas_esq + folhas_dir;
}


int altura(p_no raiz){
    int h_esq, h_dir;
    if (raiz == NULL)
        return 0;
    h_esq = altura(raiz->esq);
    h_dir = altura(raiz->dir);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);

}
//Exemplo: Criando um torneio, dado um vetor v com n números, queremos criar um torneio
// Ex; Para n=8 temos quartas de final, semifinal e final
// é uma arvore binária onde o valor do pai é o maior valor dos seus filhos

//Não entendi direito essa função
p_no torneio(int *v, int l, int r){
    p_no esq, dir;
    int valor, m = (l + r) / 2;
    if (l == r)
        return criar_arvore(v[l], NULL, NULL);
    esq = torneio(v, l, m);
    dir = torneio(v, m+1, r);
    valor = esq->dado > dir->dado ? esq->dado : dir->dado;
        return criar_arvore(valor, esq, dir);
}

void pre_ordem(p_no raiz) {
    if (raiz != NULL) {
        printf("%d\n", raiz->dado); /* visita raiz */
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
 }
 }
 void pos_ordem(p_no raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d\n", raiz->dado); /* visita raiz */
 }
 }
void inordem(p_no raiz) {
    if (raiz != NULL) {
        inordem(raiz->esq);
        printf("%d\n", raiz->dado); /* visita raiz */
        inordem(raiz->dir);
 }
 }

 void apaga_nos(p_no raiz, int x){
    if (raiz != NULL) {
    
        if (raiz->dado == x) {
            raiz->dado = -1;
        }
        apaga_nos(raiz->esq, x);
        apaga_nos(raiz->dir, x);
   }

 }



void apaga_folha(p_no pai, p_no raiz, int x) {
    if (raiz != NULL) {
        if (raiz->dado == x && raiz->esq == NULL && raiz->dir == NULL) {
            if (pai == NULL) {
                
                free(raiz); 
                raiz = NULL; 
            } else if (pai->esq == raiz) {
                
                free(raiz); 
                pai->esq = NULL; 
            } else if (pai->dir == raiz) {
                
                free(raiz); 
                pai->dir = NULL; 
            }
        } else {
            // Recursivamente chama a função para as subárvores esquerda e direita.
            apaga_folha(raiz, raiz->esq, x);
            apaga_folha(raiz, raiz->dir, x);
        }
    }
}

// Função de conveniência para chamar apaga_folha a partir da raiz.
void apaga_folha_raiz(p_no raiz, int x) {
    apaga_folha(NULL, raiz, x);
}

void destroi_arvore(p_no raiz){
    if (raiz != NULL) {
        // Primeiro, desaloca as subárvores (filhos esquerdo e direito).
        destroi_arvore(raiz->esq);
        destroi_arvore(raiz->dir);
        
        // Depois, desaloca o nó atual.
        free(raiz);
    }
}


int main (){
    int x, y, z;
    p_no no1 = criar_arvore(1, NULL, NULL);
    p_no no2 = criar_arvore(2, NULL, NULL);
    p_no no3 = criar_arvore(3, NULL, no1);
    p_no raiz = criar_arvore(4, no3, no2);
    
    pre_ordem(raiz);
    printf("\n");
   // pos_ordem(no3);
   // inordem(no3);
    // x = numero_no(raiz);
   //  printf("%d\n", x);
    // y = altura(raiz);
   //  printf("%d\n", y);
  //   z = numero_folhas(raiz);
   //  printf("%d\n", z);

    apaga_folha_raiz(raiz, 1);
    pre_ordem(raiz);
    x = numero_no(raiz);
    printf("\n%d\n", x);
    // Liberação da memória alocada
    destroi_arvore(raiz);
    return 0;

}