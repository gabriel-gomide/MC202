#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Implementação usando matrizes
*/

typedef struct grafo
{
    int **adj;
    int n;
} grafo;

typedef grafo *p_grafo;

p_grafo criar_grafo(int n)
{
    int i, j;
    p_grafo g = malloc(sizeof(struct grafo));
    g->n = n;
    g->adj = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        g->adj[i] = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g->adj[i][j] = 0;
    return g;
}

void destroi_grafo(p_grafo g)
{
    int i;
    for (i = 0; i < g->n; i++)
        free(g->adj[i]);
    free(g->adj);
    free(g);
}

void insere_aresta(p_grafo g, int u, int v)
{
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}
void remove_aresta(p_grafo g, int u, int v)
{
    g->adj[u][v] = 0;
    g->adj[v][u] = 0;
}
int tem_aresta(p_grafo g, int u, int v)
{
    return g->adj[u][v];
}

p_grafo le_grafo()
{
    int n, m, i, u, v;
    p_grafo g;
    scanf("%d %d", &n, &m);
    g = criar_grafo(n);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        insere_aresta(g, u, v);
    }
    return g;
}

void imprime_arestas(p_grafo g)
{
    int u, v;
    for (u = 0; u < g->n; u++)
        for (v = u + 1; v < g->n; v++)
            if (g->adj[u][v])
                printf("{%d,%d}\n", u, v);
}

int grau(p_grafo g, int u)
{
    int v, grau = 0;
    for (v = 0; v < g->n; v++)
        if (g->adj[u][v])
            grau++;
    return grau;
}

int mais_popular(p_grafo g)
{
    int u, max, grau_max, grau_atual;
    max = 0;
    grau_max = grau(g, 0);
    for (u = 1; u < g->n; u++)
    {
        grau_atual = grau(g, u);
        if (grau_atual > grau_max)
        {
            grau_max = grau_atual;
            max = u;
        }
    }
    return max;
}

void imprime_recomendacoes(p_grafo g, int u)
{
    int v, w;
    for (v = 0; v < g->n; v++)
    {
        if (g->adj[u][v])
        {
            for (w = 0; w < g->n; w++)
            {
                if (g->adj[v][w] && w != u && !g->adj[u][w])
                    printf("%d\n", w);
            }
        }
    }
}

/*
Implementação usando Listas de adjacências
*/

typedef struct no *p_no;

struct no
{
    int v;
    p_no prox;
};

typedef struct grafo2 *p_grafo2;

struct grafo2
{
    p_no *adjacencia;
    int n;
};

p_grafo2 criar_grafo2(int n)
{
    int i;
    p_grafo2 g = malloc(sizeof(struct grafo2));
    g->n = n;
    g->adjacencia = malloc(n * sizeof(p_no));
    for (i = 0; i < n; i++)
        g->adjacencia[i] = NULL;
    return g;
}
void libera_lista(p_no lista)
{
    if (lista != NULL)
    {
        libera_lista(lista->prox);
        free(lista);
    }
}
void destroi_grafo2(p_grafo2 g)
{
    int i;
    for (i = 0; i < g->n; i++)
        libera_lista(g->adjacencia[i]);
    free(g->adjacencia);
    free(g);
}

p_no insere_na_lista(p_no lista, int v)
{
    p_no novo = malloc(sizeof(struct no));
    novo->v = v;
    novo->prox = lista;
    return novo;
}

void insere_aresta2(p_grafo2 g, int u, int v)
{
    g->adjacencia[v] = insere_na_lista2(g->adjacencia[v], u);
    g->adjacencia[u] = insere_na_lista2(g->adjacencia[u], v);
}

p_no remove_da_lista(p_no lista, int v)
{
    p_no proximo;
    if (lista == NULL)
        return NULL;
    else if (lista->v == v)
    {
        proximo = lista->prox;
        free(lista);
        return proximo;
    }
    else
    {
        lista->prox = remove_da_lista(lista->prox, v);
        return lista;
    }
}

void remove_aresta2(p_grafo2 g, int u, int v)
{
    g->adjacencia[u] = remove_da_lista2(g->adjacencia[u], v);
    g->adjacencia[v] = remove_da_lista2(g->adjacencia[v], u);
}

int tem_aresta2(p_grafo2 g, int u, int v)
{
    p_no t;
    for (t = g->adjacencia[u]; t != NULL; t = t->prox)
        if (t->v == v)
            return 1;
    return 0;
}
void imprime_arestas2(p_grafo2 g)
{
    int u;
    p_no t;
    for (u = 0; u < g->n; u++)
        for (t = g->adjacencia[u]; t != NULL; t = t->prox)
            printf("{%d,%d}\n", u, t->v);
}