/* Exercicio: Dado um tempo t em segundos, converta para representação horas minutos segundos:
Etapas:
1)Ler o tempo
2)Coverter para o formato desejado
3)Imprimir o tempo
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int ler_tempo(int t){
char s;
scanf("%d%c", &t, &s);
return t;
}

void converte(int t){
int h, m, s;
h = abs(t/3600);
m = ((t%3600)/(60));
s = ((t%3600)%(60));
printf("%dh%dm%ds", h, m, s);
}

int main(){

int t;
t = ler_tempo(t);
printf("%d\n", t);
converte(t);
}