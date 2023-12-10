#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    
    // Matriz de inteiros
    int **v = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        v[i] = malloc(sizeof(int));
        *v[i] = 1;
        printf("%d ", *v[i]);
        free(v[i]);  // Liberar memória para cada elemento
    }
    free(v);  // Liberar matriz principal

    // Matriz de ponto flutuante
    double **h = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        h[i] = malloc(sizeof(double));
        *h[i] = 1.0;
        printf("%lf ", *h[i]);
        free(h[i]);  // Liberar memória para cada elemento
    }
    free(h);  // Liberar matriz principal

    return 0;
}
