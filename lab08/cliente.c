// Autor: Gabriel Barbiero Fagundes Gomide - 247734

#include "ED.h"

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

