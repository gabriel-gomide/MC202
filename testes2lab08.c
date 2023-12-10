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

Grafo criarGrafo()
{
    Grafo grafo;
    grafo.numPessoas = 0;
    for (int i = 0; i < MAX; i++)
    {
        grafo.listaAdj[i].head = NULL;
    }
    return grafo;
}

int indice(Grafo *grafo, char nome[MAX])
{
    for (int i = 0; i < grafo->numPessoas; i++)
    {
        if (strcmp(grafo->pessoas[i], nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

void adicionarAresta(Grafo *grafo, char pessoa1[MAX], char pessoa2[MAX])
{
    int indicePessoa1 = indice(grafo, pessoa1);
    int indicePessoa2 = indice(grafo, pessoa2);

    if (indicePessoa1 == -1)
    {
        strcpy(grafo->pessoas[grafo->numPessoas], pessoa1);
        indicePessoa1 = grafo->numPessoas;
        grafo->numPessoas++;
    }
    if (indicePessoa2 == -1)
    {
        strcpy(grafo->pessoas[grafo->numPessoas], pessoa2);
        indicePessoa2 = grafo->numPessoas;
        grafo->numPessoas++;
    }

    Node *newNode1 = (Node *)malloc(sizeof(Node));
    newNode1->pessoa = indicePessoa2;
    newNode1->next = grafo->listaAdj[indicePessoa1].head;
    grafo->listaAdj[indicePessoa1].head = newNode1;

    Node *newNode2 = (Node *)malloc(sizeof(Node));
    newNode2->pessoa = indicePessoa1;
    newNode2->next = grafo->listaAdj[indicePessoa2].head;
    grafo->listaAdj[indicePessoa2].head = newNode2;
}

int compare(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

void bfs(Grafo *grafo, int start, int distancia)
{
    int fila[MAX];
    int frente = 0;
    int tras = 0;
    int numNomesEncontrados = 0;
    int distanciaPessoas[MAX];
    char *nomesEncontrados[MAX];
    bool visitados[MAX] = {false};
    
    fila[tras] = start;
    distanciaPessoas[tras++] = 0;
    visitados[start] = true;

    while (frente < tras)
    {
        int atual = fila[frente];
        int distanciaAtual = distanciaPessoas[frente++];

        if (distanciaAtual == distancia)
        {
            nomesEncontrados[numNomesEncontrados++] = grafo->pessoas[atual];
        }

        Node *temp = grafo->listaAdj[atual].head;
        while (temp != NULL)
        {
            int vizinho = temp->pessoa;
            if (!visitados[vizinho])
            {
                fila[tras] = vizinho;
                distanciaPessoas[tras++] = distanciaAtual + 1;
                visitados[vizinho] = true;
            }
            temp = temp->next;
        }
    }

    qsort(nomesEncontrados, numNomesEncontrados, sizeof(char *), compare);

    printf("%s %d:", grafo->pessoas[start], distancia);
    for (int i = 0; i < numNomesEncontrados; i++)
    {
        printf(" %s", nomesEncontrados[i]);
    }
    printf("\n");
}

int main()
{
    int numConexoes;
    int distanciaConsulta;
    char nomeConsulta[MAX];
    Grafo grafo = criarGrafo();

    scanf("%d", &numConexoes);

    for (int i = 0; i < numConexoes; i++)
    {
        char pessoa1[MAX], pessoa2[MAX];
        scanf("%s %s", pessoa1, pessoa2);

        adicionarAresta(&grafo, pessoa1, pessoa2);
    }

    while (scanf("%s %d", nomeConsulta, &distanciaConsulta) != EOF)
    {
        int indiceConsulta = indice(&grafo, nomeConsulta);
        bfs(&grafo, indiceConsulta, distanciaConsulta);
    }
    return 0;
}
