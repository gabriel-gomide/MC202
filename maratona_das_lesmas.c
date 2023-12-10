#include <stdio.h>
/*
se sua velocidade é menor ou igual a 10 cm/h, então ela consegue andar por 3 h até parar;
se sua velocidade é maior que 10 cm/h e menor ou igual a 20 cm/h, então ela consegue andar por 2 h até parar;
se sua velocidade é maior que 20 cm/h e menor ou igual a 100cm/h, então ela consegue andar por 1 h até parar.
*/
int main(){
    int n, i, dur, velm, aux, velf;
    int vel[100];

    //número de lesmas
    scanf("%d", &n);

    //Guardando as velocidades
    for(i=0;i<n;i++){
        scanf("%d", &vel[i]);
    }
    //duração corrida
    scanf("%d", &dur);

    if (dur==3){
        velm=10;
    }
    if (dur==2){
        velm=20;
    }
    if (dur==1){
        velm=100;
    }
    velf = 0;
    for(aux=0;aux<n;aux++){
        if (vel[aux]<=velm && vel[aux]>velf){
            velf=vel[aux];
        }
    }
    printf("%d", velf);
    return 0;
}