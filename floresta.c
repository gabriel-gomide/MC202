/*

  floresta.c - Implementação do TAD para manipulação de uma árvore de busca binária (BST) 
               e pilha, utilizados no contexto de um jogo em uma floresta de monstros.

  Autor: Gabriel Barbiero Fagundes Gomide - 247734

  MC202G+H - 2 semestre de 2023.

  Última alteração: 2/11/2023.

*/

#include "floresta.h"

/* TODO: implemente aqui as funções da interface! */
/*
  Função auxiliar 1
 */
int maximos_vetor(int vetor[])
{
    int max = 1;
    int count = 0;
    for (int i = 0; i < 30; i++)
    {
        if (vetor[i] >= max)
        {
            max = vetor[i];
        }
    }
    for (int j = 0; j < 30; j++)
    {
        if (vetor[j] == max)
        {
            count = count + 1;
        }
    }
    return count;
}

/*
  Função auxiliar 2
 */
int conta_caminhos(p_no_arvore raiz, int vida_personagem, int monstros[1])
{
    if (raiz == NULL)
        return 0;

    int caminhos = 0;
    static int count = 0;
    static int jog = 0;
    static int vetor[30];

    if (vida_personagem > raiz->poder)
    {
        count = count + 1;

        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            caminhos = 1;

            if (count >= monstros[0])
            {
                vetor[jog] = count;
                jog = jog + 1;
                monstros[0] = count;
            }
        }

        caminhos += conta_caminhos(raiz->esq, vida_personagem - raiz->poder, monstros);
        caminhos += conta_caminhos(raiz->dir, vida_personagem - raiz->poder, monstros);
    }
    count = count - 1;
    caminhos = maximos_vetor(vetor);
    return caminhos;
}

p_no_pilha cria_pilha()
{
    return NULL;
}

/*
  Insere um novo elemento no topo da pilha, representando um passo no caminho do personagem.
  topo: ponteiro para o topo da pilha.
  poder: valor do poder do monstro no caminho.
  Retorna um ponteiro para o novo topo da pilha.
 */
p_no_pilha insere_na_pilha(p_no_pilha topo, int poder)
{
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
p_no_pilha remove_da_pilha(p_no_pilha topo, int *poder)
{
    p_no_pilha retirado = topo;
    *poder = topo->poder;
    topo = topo->prox;
    free(retirado);
    return topo;
}

/*
  Imprime o conteúdo atual da pilha, utilizado para depuração e visualização dos caminhos.
  topo: ponteiro para o topo da pilha.
 */
int tamanho_pilha(p_no_pilha topo)
{
    int n = 0;
    while (topo != NULL)
    {
        n = n + 1;
        topo = topo->prox;
    }
    return n;
}

void imprime_pilha_real(p_no_pilha topo, int monstros[1])
{
    int impresso;
    if (monstros[0] == tamanho_pilha(topo))
    {
        while (topo != NULL)
        {
            impresso = topo->poder;
            if (topo->prox != NULL)
                printf("%d, ", impresso);
            else
            {
                printf("%d", impresso);
            }
            topo = topo->prox;
        }
        printf("\n");
    }
    else
    {
        return;
    }
}
void imprime_pilha(p_no_pilha topo)
{
}

/*
  Libera toda a memória alocada pelos elementos da pilha.
  topo: ponteiro para o topo da pilha.
 */
void destroi_pilha(p_no_pilha topo)
{
    while (topo->prox != NULL)
    {
        p_no_pilha limpo = topo;
        topo = topo->prox;
        free(limpo);
    }
}

/*
   Cria uma nova árvore vazia.
   Retorna um ponteiro para a raiz da árvore.
 */
p_no_arvore cria_percursos()
{
    return NULL;
}

/*
  Insere um novo monstro na árvore de monstros. A inserção é feita de forma a manter a
  propriedade de busca binária, baseando-se no poder do monstro.
  raiz: ponteiro para a raiz da árvore.
  poder: valor do poder do monstro a ser inserido.
  Retorna um ponteiro para a raiz da árvore atualizada.
 */
p_no_arvore insere_monstro(p_no_arvore raiz, int poder)
{
    p_no_arvore novo;
    if (raiz == NULL)
    {
        novo = malloc(sizeof(NoArvore));
        novo->esq = novo->dir = NULL;
        novo->poder = poder;
        return novo;
    }
    if (poder < raiz->poder)
        raiz->esq = insere_monstro(raiz->esq, poder);
    else
        raiz->dir = insere_monstro(raiz->dir, poder);
    return raiz;
}

/*
  Realiza uma busca na árvore para determinar os caminhos possíveis que o personagem pode
  percorrer mantendo a vida acima de zero, levando em consideração o poder dos monstros.
  raiz: ponteiro para a raiz da árvore.
  vida_personagem: quantidade de vida restante do personagem.

  Minha ideia: Talvez não esteja funcionando, testar

 */
void busca_caminhos_real(p_no_arvore raiz, int vida_personagem, int vetor[1], p_no_pilha monstros)
{

    if (raiz == NULL)
        return;

    monstros = insere_na_pilha(monstros, raiz->poder);

    if (vida_personagem > raiz->poder)
    {
        vida_personagem = vida_personagem - raiz->poder;
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            imprime_pilha_real(monstros, vetor);
            vida_personagem = vida_personagem + raiz->poder;
            monstros = remove_da_pilha(monstros, &raiz->poder);

            return;
        }
        busca_caminhos_real(raiz->esq, vida_personagem, vetor, monstros);
        busca_caminhos_real(raiz->dir, vida_personagem, vetor, monstros);
    }

    monstros = remove_da_pilha(monstros, &raiz->poder);
    vida_personagem = vida_personagem + raiz->poder;
}

void busca_caminhos(p_no_arvore raiz, int vida_personagem)
{
    p_no_pilha monstros = cria_pilha();
    int matriz[1];
    matriz[0] = 1;
    
    int caminhos;

    caminhos = conta_caminhos(raiz, vida_personagem, matriz);
    printf("%d\n", caminhos);
    busca_caminhos_real(raiz, vida_personagem, matriz, monstros);
}

void destroi_percursos(p_no_arvore raiz)
{
    if (raiz != NULL)
    {

        destroi_percursos(raiz->esq);
        destroi_percursos(raiz->dir);

        free(raiz);
    }
}

/*
   Fim do arquivo de implementação.
*/
