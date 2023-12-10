/*
Ponteiros: Parte 1

Ponteiro é uma variável que armazena um endereço

int *p; declara um ponteiro para int
double *q; ponteiro para double
char *c; ponteiro para char
struct data *d; 

Operações básicas:
& retorna o endereço de memória de uma váriavel, posição de vetor ou campo de uma struct
Podemos salva o endereço em um ponteiro ex: p=&x;
* Acessa o conteúdo no endereço indicado pelo ponteiro

sizeof, malloc e free:

sizeof: Devolve o tamanho em bytes em um tipo dado
sizeof(int)

malloc: aloca dinamicamente a quantidade de bytes informada
- Devolve o endereço inicial da região de memória
malloc(sizeof(struct data)) aloca a quantidade de bytes necessária para representar uma struct data

free: libera uma região de memória alocada dinamicamente
precisa ser um endereço que foi devolvido por malloc
evita vazamentos de memória

Aritmética de ponteiros
Soma ou subtração

Se tivermos um ponteiro p, podemos escrever p[i]
- Como se fosse um vetor 
- É o mesmo que escrever *(p+1)

*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *endereco;
    int var = 90;
    endereco = &var;
    printf("Variavel: %d\n", var);
    printf("Variavel: %d\n", *endereco);
    printf("Endereço: %p\n", endereco);
    printf("Endereço %p\n", &var);


    int vetor[5] = {1, 2, 3, 4, 5};
    int *ponteiro;
    ponteiro = vetor + 2;
    ponteiro++;
    printf("%d %d %d\n", *vetor, *(ponteiro - 1), *ponteiro);

    double media, *notas;
    int i, n;
    scanf("%d", &n);
    notas = malloc(n * sizeof(double));
    if (notas == NULL){
        printf ("Não há memória suficiente.\n");
        exit(1);
    }
    for (i= 0 ; i<n; i++){
        scanf("%lf", &notas[i]);
    }
    media = 0;
    for (i= 0 ; i<n ; i++){
        media += notas[i]/n;
    }
    printf("Média: %f\n", media);
    free(notas);


    return 0;
}