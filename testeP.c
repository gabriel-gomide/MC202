#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50
#define AUT 10

typedef struct
{
   char *doi, **autor;
   int ano, n_autores, volume;
} ficha;

ficha **cria_fichario(int n)
{

   // Criando o vetor de fichas
   ficha **v = malloc(n * sizeof(ficha *));

   for (int i = 0; i < n; i++)
   {

      // Criando a ficha dentro do vetor
      v[i] = malloc(sizeof(ficha));

      // Criando a string para armazenar o doi, com no max 100 caracteres
      (*v[i]).doi = malloc(MAX * sizeof(char));
      (*v[i]).doi[0] = '\0';
      // Criando o vetor de autores
      (*v[i]).autor = malloc(AUT * sizeof(char *));

      // Criando a string para cada autor
      for (int l = 0; l < AUT; l++)
      {
         (*v[i]).autor[l] = malloc(MAX * sizeof(char));
         (*v[i]).autor[l][0] = '\0';
      }
      (*v[i]).ano = 0;
      (*v[i]).n_autores = 0;
      (*v[i]).volume = 0;
   }
   return v;
}

ficha *le_ficha()
{
   // Criando a ficha que será lida
   ficha *b = malloc(sizeof(ficha));

   int n;
   // Criando a string do doi
   (*b).doi = malloc(MAX * sizeof(char));

   scanf("%s", (*b).doi);
   scanf("%d", &(*b).n_autores);
   n = (*b).n_autores;

   // Criando o vetor de autores
   (*b).autor = malloc(n * sizeof(char *));
   for (int i = 0; i < n; i++)
   {
      (*b).autor[i] = malloc(MAX * sizeof(char));
      scanf("%s", (*b).autor[i]);
   }
   scanf("%d %d", &(*b).ano, &(*b).volume);
   return b;
}
int insere_ficha(ficha **ptr_vetor, int n, ficha *ptr_artigo)
{

   for (int i = 0; i < n; i++)
   {
      if ((*ptr_vetor[i]).doi[0] == '\0')
      {
         strcpy((*ptr_vetor[i]).doi, (*ptr_artigo).doi);

         for (int u = 0; u < (*ptr_artigo).n_autores; u++)
         {
            strcpy((*ptr_vetor[i]).autor[u], (*ptr_artigo).autor[u]);
         }
         (*ptr_vetor[i]).ano = (*ptr_artigo).ano;
         (*ptr_vetor[i]).n_autores = (*ptr_artigo).n_autores;
         (*ptr_vetor[i]).volume = (*ptr_artigo).volume;
         return 0;
      }
   }
   return 1;
}

void imprime_ficha(ficha *ptr_artigo)
{
   if ((*ptr_artigo).n_autores != 0 && (*ptr_artigo).doi[0] != '\0')
   {

      printf("%s ", (*ptr_artigo).doi);

      for (int i = 0; i < 3 && i < (*ptr_artigo).n_autores; i++)
      {
         printf("%s", (*ptr_artigo).autor[i]);

         if (i < 2 && i < (*ptr_artigo).n_autores - 1)
         {
            printf(", ");
         }
      }

      if ((*ptr_artigo).n_autores > 3)
      {
         printf(", et al.");
      }
      printf(" (%d) ", (*ptr_artigo).ano);
      printf("%d", (*ptr_artigo).volume);
      printf("\n");
   }
}

void destroi_ficha(ficha *ptr_artigo)
{
   int y = 0;
   free((*ptr_artigo).doi);
   for (int i = 0; i < (*ptr_artigo).n_autores; i++)
   {
      free((*ptr_artigo).autor[i]);
   }
   free((*ptr_artigo).autor);
   free(ptr_artigo);
}

int busca_ficha(ficha **ptr_vetor, int n, char *doi)
{
   for (int i = 0; i < n; i++)
   {
      if (strcmp((*ptr_vetor[i]).doi, doi) == 0)
      {
         return i;
      }
   }
   return -1;
}

int remove_ficha(ficha **ptr_vetor, int n, char *doi)
{
   for (int i = 0; i < n; i++)
   {
      if (strcmp((*ptr_vetor[i]).doi, doi) == 0)
      {
         strcpy((*ptr_vetor[i]).doi, "\0");
         return 1;
      }
   }
   return 0;
}

int main()
{
   int a, k, g, y, j;
   int h = 0;
   char comando;
   char *doii;
   ficha *b;
   ficha **e;
   a = 0;
   doii = malloc(MAX * sizeof(char));
   while (a == 0)
   {
      comando = 'j';
      scanf(" %c", &comando);

      if (comando == 'N')
      {
         scanf("%d", &k);
         e = cria_fichario(k);
      }

      if (comando == 'I')
      {
         scanf("%d", &h);
         for (int i = 0; i < h; i++)
         {
            b = le_ficha();
            g = insere_ficha(e, k, b);
            if (g == 1)
            {
               printf("Erro ao inserir DOI ");
               printf("%s", (*b).doi);
            }
            destroi_ficha(b);
         }
      }

      if (comando == 'P')
      {
         for (int i = 0; i < k; i++)
         {
            imprime_ficha(e[i]);
         }
      }

      if (comando == 'F')
      {
         a = 1;
      }

      if (comando == 'B')
      {
         scanf("%s", doii);
         y = busca_ficha(e, k, doii);
         if (y == -1)
         {
            printf("DOI %s inexistente\n", doii);
         }
         else
         {
            for (int i = 0; i < 3 && i < (*e[y]).n_autores; i++)
            {
               printf("%s ", (*e[y]).autor[i]);
            }
            if ((*e[y]).n_autores > 3)
            {
               printf("et al. ");
            }

            printf("(%d) %d\n", (*e[y]).ano, (*e[y]).volume);
         }
      }

      if (comando == 'R')
      {
         scanf("%s", doii);
         y = busca_ficha(e, k, doii);
         if (y == -1)
         {
            printf("DOI %s inexistente\n", doii);
         }
         else
         {
            j = remove_ficha(e, k, doii);
            if (j == 1)
            {
               printf("DOI %s removido\n", doii);
            }
         }
      }
   }

   for (int h = 0; h < k; h++)
   {
      for (int q = 0; q < AUT; q++)
      {
         if ((*e[h]).autor[q][0] == '\0')
         {
            free((*e[h]).autor[q]);
         }
      }
   }

   for (int i = 0; i < k; i++)
   {
      destroi_ficha(e[i]);
   }

   free(doii);
   free(e);

   return 0;
}