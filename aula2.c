#include<stdio.h>
#include<string.h>
/*
Em C, declaramos uma função da seguinte forma:
tipo nome(tipo parametro1, tipo parametro2,...){}
tipos: int, float, double, char...
Para compilar no terminal:
gcc -ansi -Wall -pedantic-errors -Werror -g -lm aula2.c -o aula2

Exercício: O Produto de Hadamart
Escrever um programa que lê dois vetores menor ou igual a 100 números inteiros
Realiza o Produto de Hadamart
Imprime o terceiro vetor
*/
void le_vetor(int vetor[], int tamanho){
    int i;
    for (i=0; i<tamanho; i++){
        scanf("%d", &vetor[i]);
    }
}
void imprime_vetor(int vetor[], int tamanho){
    int i;
    for (i=0; i<tamanho; i++){
        printf("%d ", vetor[i]);
    }
}
void hadamart(int vetor1[], int vetor2[], int vetor3[], int tamanho){
    int i;
    for (i=0; i<tamanho; i++){
        vetor3[i] = vetor2[i]*vetor1[i];
    }
}

int main(){
    int vetor1[101], vetor2[101], vetor3[101], tamanho;
    scanf("%d", &tamanho);
    le_vetor(vetor1, tamanho);
    le_vetor(vetor2, tamanho);
    hadamart(vetor1, vetor2, vetor3, tamanho);
    imprime_vetor(vetor3, tamanho);
    return 0;
}