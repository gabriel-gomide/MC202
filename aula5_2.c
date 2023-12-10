/* 
Esse código é um exemplo de uso do struct. 
Ele recebe um conjunto de pontos no plano, e calcula o ponto que é a média/centroide
desses conjuntos de pontos
*/

#include <stdio.h>
#define MAX 100
/* Declara um struct, chamado ponto, que tem dois doubles, x e y */
typedef struct ponto {
    double x, y;
} ponto;

int main (){
    ponto v[MAX], centroide;
    int i, n;
    /* Recebe o número de pontos*/
    scanf("%d", &n);
    /* Recebe os pontos e salva dentro do novo tipo de variaveis criado no struct*/
    for (i=0; i<n; i++){
        scanf("%lf %lf", &v[i].x, &v[i].y);
    }
    centroide.x = 0;
    centroide.y = 0;
    for (i = 0; i < n; i++) {
        centroide.x += v[i].x/n;
        centroide.y += v[i].y/n;
    }
    printf("%lf %lf\n", centroide.x, centroide.y);
    return 0;
}