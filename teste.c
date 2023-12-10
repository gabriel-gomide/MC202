#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct
{
  char * doi, ** autor;
  int ano, n_autores, volume;
} ficha;

/*
   Função que recebe um ponteiro para um vetor de fichas, um inteiro n que
   diz o tamanho do vetor e uma string que representa o DOI do artigo.
   A função devolve o índice do artigo no vetor de fichas ou então
   -1 caso o mesmo não se encontre no vetor.
*/
int busca_ficha (ficha ** ptr_vetor, int n, char * doi){
    for (int i =0; i<n; i++){
      if (strcmp((*ptr_vetor[i]).doi, doi) == 0){
         return i;
      }

} return -1;

}

/*
   Função que recebe um inteiro positivo n, aloca na memória um vetor do tipo
   ficha com n registros vazios (i.e., registro com DOI setado com string
   vazio) e devolve um ponteiro para a primeira posição desse vetor.
*/

ficha **cria_fichario(int n) {
    ficha **v = malloc(n * sizeof(ficha *));

    for (int i = 0; i < n; i++) {
        v[i] = malloc(sizeof(ficha));
        (*v[i]).doi= ""; 
        (*v[i]).autor = NULL; 
        (*v[i]).ano = 0;
        (*v[i]).n_autores = 0;
        (*v[i]).volume = 0;
    }

    return v;
}
/*
   Função que recebe um ponteiro de um registro contendo a ficha de um
   artigo e a imprime na saída padrão.
*/
void imprime_ficha(ficha * ptr_artigo){
   //Não sei como formatar isso
   printf("DOI: %s\n", (*ptr_artigo).doi);
   printf("Autor: %s\n", (*ptr_artigo).autor);
   printf("Ano: %d\n", (*ptr_artigo).ano);
   printf("Nº de autores: %d\n", (*ptr_artigo).n_autores);
   printf("Volume: %d\n", (*ptr_artigo).volume);
   printf("\n");
}

/*
   Função que recebe um ponteiro para o endereço do ponteiro de um vetor de
   fichas, um ponteiro para um inteiro n que diz o tamanho do vetor e um
   ponteiro para uma ficha de artigo.
   A função insere então os dados do artigo no primeiro índice disponível
   (i.e., com DOI vazio) e devolve 1; caso não exista índice disponível a função
   devolve zero.
*/
int insere_ficha (ficha ** ptr_vetor, int n, ficha * ptr_artigo){
      for (int i =0; i<n; i++){
         if ((*ptr_vetor[i]).doi == ""){
            (*ptr_vetor[i]).doi= (*ptr_artigo).doi; 
            (*ptr_vetor[i]).autor = (*ptr_artigo).autor; 
            (*ptr_vetor[i]).ano = (*ptr_artigo).ano;
            (*ptr_vetor[i]).n_autores = (*ptr_artigo).n_autores;
            (*ptr_vetor[i]).volume = (*ptr_artigo).volume;
            return 0;
      }
   } return 1;
}
