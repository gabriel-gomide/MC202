/*

  cliente.c - Aplicação principal para o gerenciamento de um sistema de atendimento de uma clinica,
              utilizando estruturas de dados 'fila de prioridade', como parte do Laboratório 7 de MC202.

  Autor: Gabriel Barbiero Fagundes Gomide 247734

  MC202G+H - 2º semestre de 2023.

  Última alteração: 1/12/2023.

*/

#include "fila.h"

int main()
{

    p_fp teste;
    Item p1, max;
    char comando[3];
    int tam;
    int v;
    int n = 0;
    int j = 0;
    strcpy(comando, "s");

    while (j == 0)
    {
        scanf("%s", comando);
        if ((strcmp(comando, "F") == 0))
        {
            j = 2;
            break;
        }
        if ((strcmp(comando, "C") == 0))
        {
            scanf("%d", &tam);
            teste = criar_filaprio(tam);
        }
        if ((strcmp(comando, "I") == 0))
        {
            scanf("%s %d %d:%02d", p1.nome, &p1.chave, &p1.chegada.hora, &p1.chegada.minuto);
            if (n < tam)
            {

                insere(teste, p1);
                n = n + 1;
            }
            else
            {
                printf("Fila cheia\n");
            }
        }
        if ((strcmp(comando, "R") == 0))
        {
            v = vazia(teste);
            if (v == 1)
            {
                printf("Fila vazia\n");
            }
            else
            {
                // heapsort(teste, teste->n);
                max = extrai_maximo(teste);
                n = n - 1;
                printf("Atendimento: %s\n", max.nome);
            }
        }
        if ((strcmp(comando, "A") == 0))
        {
            scanf("%s %d", p1.nome, &p1.chave);
            atualizar_gravidade(teste, p1.nome, p1.chave);
        }
        if ((strcmp(comando, "P") == 0))
        {
            v = vazia(teste);
            if (v == 1)
            {
                printf("Fila vazia\n");
            }
            else
            {
                imprime_fila(teste);
            }
        }
    }

    destroi_fila(teste);

    return 0;
}