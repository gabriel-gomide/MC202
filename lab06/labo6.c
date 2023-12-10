#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó na árvore de busca binária, representando cada elemento químico.
typedef struct No
{
    int numero_atomico;
    char simbolo[3];      // Supondo um limite de 2 caracteres + terminador nulo para o símbolo.
    struct No *esq, *dir; // ponteiros para subárvores esquerda e direita.
} No, *p_no;

p_no criar_arvore()
{
    return NULL;
}

void destruir_arvore(p_no raiz)
{
    if (raiz != NULL)
    {

        destruir_arvore(raiz->esq);
        destruir_arvore(raiz->dir);

        free(raiz);
    }
}

p_no inserir(p_no raiz, int numero_atomico, char *simbolo)
{
    p_no novo;
    if (raiz == NULL)
    {
        novo = malloc(sizeof(No));
        novo->esq = novo->dir = NULL;
        novo->numero_atomico = numero_atomico;
        novo->simbolo[0] = simbolo[0];
        novo->simbolo[1] = simbolo[1];
        novo->simbolo[2] = '\0';
        return novo;
    }
    if (numero_atomico < raiz->numero_atomico)
        raiz->esq = inserir(raiz->esq, numero_atomico, simbolo);
    else
        raiz->dir = inserir(raiz->dir, numero_atomico, simbolo);
    return raiz;
}
p_no minimo(p_no raiz)
{
    if (raiz == NULL || raiz->esq == NULL)
    {
        return raiz;
    }
    return minimo(raiz->esq);
}

p_no remover_sucessor(p_no raiz, int chave)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (chave < raiz->numero_atomico)
    {
        raiz->esq = remover_sucessor(raiz->esq, chave);
    }
    else if (chave > raiz->numero_atomico)
    {
        raiz->dir = remover_sucessor(raiz->dir, chave);
    }
    else
    {
        if (raiz->esq == NULL)
        {
            p_no temp = raiz->dir;
            free(raiz);
            return temp;
        }
        else if (raiz->dir == NULL)
        {
            p_no temp = raiz->esq;
            free(raiz);
            return temp;
        }

        p_no temp = minimo(raiz->dir);
        raiz->numero_atomico = temp ->numero_atomico;
        strcpy(raiz->simbolo, temp->simbolo);
        raiz->dir = remover_sucessor(raiz->dir, temp->numero_atomico);
    }
    return raiz;
}

p_no remover(p_no raiz, char *simbolo)
{
    static int chave;

    if (raiz == NULL)
        return NULL;
    if (strcmp(simbolo, raiz->simbolo) == 0)
    {
        chave = raiz->numero_atomico;
        raiz = remover_sucessor(raiz, chave);
        return raiz;
    }

    raiz->esq = remover(raiz->esq, simbolo);
    raiz->dir = remover(raiz->dir, simbolo);
    return raiz;
}

p_no buscar(p_no raiz, int chave)
{
    if (raiz == NULL || chave == raiz->numero_atomico)
        return raiz;
    if (chave < raiz->numero_atomico)
        return buscar(raiz->esq, chave);
    else
        return buscar(raiz->dir, chave);
}

p_no maximo(p_no raiz)
{
    if (raiz == NULL || raiz->dir == NULL)
    {
        return raiz;
    }
    return maximo(raiz->dir);
}

void imprime(p_no raiz, int *primeiro)
{
    if (raiz != NULL)
    {
        imprime(raiz->esq, primeiro);
        if (raiz->numero_atomico != 0)
        {

            if (*primeiro == 0)
                printf("%s", raiz->simbolo);
            else
                printf(", %s", raiz->simbolo);

            *primeiro = 1;
        }
        imprime(raiz->dir, primeiro);
    }
}

int main()
{

    p_no teste = criar_arvore();
    p_no fan = criar_arvore();
    char simbolo[3];
    char comando[4];
    int natom;
    int primeiro = 0;

    while (scanf("%s", comando) != EOF)
    {

        if ((strcmp(comando, "C") == 0))
        {
            scanf("%d", &natom);
            scanf("%s", simbolo);
            teste = inserir(teste, natom, simbolo);
        }

        if ((strcmp(comando, "V") == 0))
        {
            scanf("%s", simbolo);
            teste = remover(teste, simbolo);
        }

        if ((strcmp(comando, "E") == 0))
        {
            primeiro = 0;
            imprime(teste, &primeiro);
            printf("\n");
        }

        if ((strcmp(comando, "I") == 0))
        {
            scanf("%d", &natom);
            scanf("%s", simbolo);
            fan = buscar(teste, natom);
            if (fan == NULL)
            {
                printf("Nao");
                printf("\n");
            }
            else
            {
                printf("Sim");
                printf("\n");
            }
        }

        if (strcmp(comando, "MAX") == 0)
        {
            fan = maximo(teste);
            printf("%s", fan->simbolo);
            printf("\n");
        }

        if (strcmp(comando, "MIN") == 0)
        {
            fan = minimo(teste);
            printf("%s", fan->simbolo);
            printf("\n");
        }
    }
    destruir_arvore(teste);
    return 0;
}