// Autor: Gabriel Barbiero Fagundes Gomide - 247734
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50

typedef struct Node
{
    int pessoa;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} LinkedList;

typedef struct
{
    LinkedList listaAdj[MAX];
    char pessoas[MAX][MAX];
    int numPessoas;
} Grafo;


Grafo criarGrafo();
int indice(Grafo *grafo, char nome[MAX]);
void adicionarAresta(Grafo *grafo, char pessoa1[MAX], char pessoa2[MAX]);
int compare(const void *a, const void *b);
void bfs(Grafo *grafo, int start, int distancia);