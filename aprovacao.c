#include <stdio.h>
/*
Média aritmética P de 3 tarefas práticas e uma média aritmética T de 2 tarefas teóricas.
A média final é dada por F = (T + P)/2. 
T'=10T/Tmax
P'=1.1P

A entrada tem:
um número n de estudante
uma sequência de n linhas, cada uma com as três notas das tarefas práticas, em ordem de RA
uma sequência de n linhas, cada uma com as duas notas das tarefas teóricas, em ordem de RA

A saída deve conter
n linhas, cada uma com a nota final de cada estudante
em seguida, duas linhas com as notas máximas de T e P entre todos estudantes
por último, duas linhas com as médias de T e P
*/
int main(){
int n, i, P[100], T[100], Pl[100], nf[100], nff[100];
int tm=0;
scanf("%d", &n);
for(i=0; i<n; i++){
    int p[3];
    scanf("%d%d%d", &p[0],&p[1],&p[2]);
    P[i] = (p[0]+p[1]+p[2])/3;
    Pl[i] = 1.1*P[i];
}
for(i=0; i<n; i++){ 
    int t[2];
    scanf("%d%d", &t[0],&t[1]);
    T[i] = (t[0]+t[1])/2;
    nf[i] = (T[i]+P[i])/2;
    if (T[i]>tm){
        tm=T[i];
    }
}
for(i=0; i<n; i++){
    nff[i] = (T[i]*10/tm + 1.1*P[i])/2;
    printf("Média P %d, %d\n Média T %d\n Máx T %d\n Média Final %d\n", P[i],Pl[i],T[i],tm,nff[i]);
}


}

