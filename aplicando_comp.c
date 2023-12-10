#include <stdio.h>
#include "complexos.h"

int main (){
    complexo a, b, c, e;
    int d;
    a = complexo_le();
    b = complexo_le();
    c = complexo_soma(a, b);
    d = complexos_iguais(a, b);
    e = complexo_multiplicacao(a, b);
    complexo_imprime(c);
    complexo_imprime(e);
    printf("%lf\n %d", complexo_absoluto(c), d);
    return 0;
}

/* Compilando:
• gcc -std=c99 -Wall -Werror -c aplicando_comp.c
– vai gerar o arquivo compilado aplicando_comp.o

• gcc -std=c99 -Wall -Werror -c complexos.c
– vai gerar o arquivo compilado complexos.o

• gcc cliente.o complexos.o -lm -o aplicando_comp
- faz a linkagem, gerando o executável cliente
– adicionamos cliente.o e complexos.o
– e outras bibliotecas, por exemplo, -lm

mingw32-make 
.\aplicando_comp
*/