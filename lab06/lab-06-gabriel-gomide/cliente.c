/*

  cliente.c - Aplicação principal para o gerenciamento de estoque de uma loja de elementos químicos,
              utilizando estruturas de dados 'árvore binária de busca', como parte do Laboratório de MC202.

  Autor: Gabriel Barbiero Fagundes Gomide - 247734

  MC202G+H - 2º semestre de 2023.

  Última alteração: 14/11/2023.

*/

#include "gerenciador.h"

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