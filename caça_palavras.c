#include<stdio.h>
#include<string.h>
#define max_altura 20
#define max_largura 20
#define max_palavra 20

void ler_matriz(char matriz[max_altura][max_largura], int m, int n){
    int i, j;
    char letra;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf(" %c", &letra);
            matriz[i][j] = letra;
        }
    }
}

void matriz_ponto(char matriz[max_altura][max_largura], int m, int n){
    int i, j;
    char ponto='.';
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = ponto;
}}}

void imprimir_matriz(char matriz[max_altura][max_largura], int m, int n){
    int i, j;
    char letra;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

void copiar_inverso(char palavra[], char inverso[]) {
    int i, j;
    i = strlen(palavra)-1;
    j = 0;                          
    while (i >= 0) {
        inverso[j] = palavra[i];
        i = i - 1;
        j = j + 1;
    }
    inverso[j] = '\0';
}

void mc_h(char palavra[], char A[max_altura][max_largura], char B[max_altura][max_largura], int m, int n, int i, int j){
    int len=strlen(palavra);
    int h;
    char ponto ='.';
    if (A[i][j] == palavra[0]){
        B[i][j] = palavra[0];
        for (h=1;h<len;h++){
            if (A[i][j+h]==palavra[h]){
                B[i][j+h]=palavra[h];
            }
            else{
                while(h>=0){
                    B[i][j+h] = ponto;
                    h=h-1;
                }
                break;
            }}
    }
}

void mc_v(char palavra[], char A[max_altura][max_largura], char B[max_altura][max_largura], int m, int n, int i, int j){
    int len=strlen(palavra);
    int h;
    char ponto ='.';
    if (A[i][j] == palavra[0]){
        B[i][j] = palavra[0];
        for (h=1;h<len;h++){
            if (A[i+h][j]==palavra[h]){
                B[i+h][j]=palavra[h];
            }
            else{
                while(h>=0){
                    B[i+h][j] = ponto;
                    h=h-1;
                }
                break;
            }}
    }
}

void mc_d(char palavra[], char A[max_altura][max_largura], char B[max_altura][max_largura], int m, int n, int i, int j){
    int len=strlen(palavra);
    int h;
    char ponto ='.';
    if (A[i][j] == palavra[0]){
        B[i][j] = palavra[0];
        for (h=1;h<len;h++){
            if (A[i+h][j+h]==palavra[h]){
                B[i+h][j+h]=palavra[h];
            }
            else{
                while(h>=0){
                    B[i+h][j+h] = ponto;
                    h=h-1;
                }
                break;
            }}
    }
}

void marcar_ocorrencias(char palavra[], char A[max_altura][max_largura], char B[max_altura][max_largura], int m, int n){
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            mc_h(palavra, A, B, m, n, i, j);
            mc_v(palavra, A, B, m, n, i, j);
            mc_d(palavra, A, B, m, n, i, j);
        }}
}


int main(){
    /*Lendo as dimensões da matriz*/
    int m,n,i,p;
    char A[max_altura][max_largura];
    char B[max_altura][max_largura];
    char palavra[max_palavra];
    char inverso[max_palavra];

    printf("Dimensões: \n");
    scanf("%d%d", &m,&n);

    /*Lendo a matriz de caracteres*/
    printf("Digite os elementos da matriz: \n");
    ler_matriz(A, m, n);

    /*Criando a matriz de pontos*/
    matriz_ponto(B, m, n);

    /*Ler n de palavras*/
    printf("Número de palvras:\n");
    scanf("%d", &p);

    for(i=0; i<p; i=i+1){
        printf("Palavra a ser procurada:\n");
        scanf("%s", palavra);
        /*Procurar as ocorrências em A*/
        marcar_ocorrencias(palavra, A, B, m, n);
        /*Repetir processo com a inversa*/
        copiar_inverso(palavra, inverso);
        marcar_ocorrencias(inverso, A, B, m, n);

    }
    imprimir_matriz(B, m, n);

}