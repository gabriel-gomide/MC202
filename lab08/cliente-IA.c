// Autor: Gabriel Barbiero Fagundes Gomide - 247734

#include "ED-IA.h"

int main()
{
    int numConexoes;
    int distanciaConsulta;
    char nomeConsulta[MAX];
    Grafo grafo = criarGrafo();

    scanf("%d", &numConexoes);

    if (numConexoes <= 0 || numConexoes > MAX)
    {
        printf("Número inválido de conexões.\n");
        return 1;
    }

    for (int i = 0; i < numConexoes; i++)
    {
        char pessoa1[MAX], pessoa2[MAX];
        scanf("%s %s", pessoa1, pessoa2);

        adicionarAresta(&grafo, pessoa1, pessoa2);
    }

    while (scanf("%s %d", nomeConsulta, &distanciaConsulta) == 2)
    {
        int indiceConsulta = indice(&grafo, nomeConsulta);
        if (indiceConsulta == -1)
        {
            printf("Pessoa não encontrada.\n");
            continue;
        }

        if (distanciaConsulta < 0)
        {
            printf("Distância social inválida.\n");
            continue;
        }

        bfs(&grafo, indiceConsulta, distanciaConsulta);
    }
    return 0;
}