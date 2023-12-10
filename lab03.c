#include "labirinto.h"

/*
   Função que cria e retorna um novo labirinto.
   Recebe: Número de linhas e colunas do labirinto.
   Faz: Aloca dinamicamente um labirinto com o número especificado de linhas e colunas.
   Retorna: Um ponteiro para o labirinto alocado.
*/
labirinto* criar_labirinto(int linhas, int colunas){
    labirinto *l = malloc(sizeof(labirinto));
    (*l).linhas = linhas;
    (*l).colunas = colunas;
    (*l).matriz = malloc(linhas * sizeof(char *));
    for (int i = 0; i < linhas; i++){
        (*l).matriz[i] = malloc(colunas * sizeof(char));
    }
    return l;
}

/*
    Função que lê o conteúdo do labirinto da entrada padrão.
    Recebe: Um ponteiro para o labirinto.
    Faz: Preenche a matriz do labirinto lendo os caracteres da entrada padrão.
    Retorna: Nada.
*/
void ler_labirinto(labirinto *l){
    int li = (*l).linhas;
    int co = (*l).colunas;
    char letra;
    for (int i = 0; i < li; i++) {
        for (int j = 0; j < co; j++) {
            scanf(" %c", &letra);
            if (letra == 'S'){
                (*l).saidaX = i;
                (*l).saidaY = j;                
            }
            (*l).matriz[i][j] = letra;
        }
    }

}

/*
   Função auxiliar recursiva que busca uma saída no labirinto.
   Recebe: Uma matriz de caracteres, as dimensões da matriz e as coordenadas atuais da busca.
   Faz: Verifica se a posição atual é válida e tenta encontrar uma saída movendo-se em diferentes direções.
   Retorna: 1 se uma saída foi encontrada, 0 caso contrário.
*/
int buscar_saida_recursivamente(char **matriz, int linhas, int colunas, int x_atual, int y_atual){
    int k, x_novo, y_novo;
    static int movimentos[4][2] = {{0, 1},{1,0},{0,-1},{-1,0}};
    
 
        for (k = 0; k<4 ; k++){
            y_novo = y_atual + movimentos[k][1];
            x_novo = x_atual + movimentos[k][0];
            //printf("x:%d y:%d\n", x_novo, y_novo);
            if ((y_novo>=0) && (y_novo<colunas) && (x_novo>=0) && (x_novo<linhas) && matriz[x_novo][y_novo] == 'S'){
                matriz[x_novo][y_novo] = 'X';
                return 1;
            }

            if ((y_novo>=0) && (y_novo<colunas) && (x_novo>=0) && (x_novo<linhas) && (matriz[x_novo][y_novo] == '0')){
                matriz[x_novo][y_novo] = 'X';
                if (buscar_saida_recursivamente(matriz, linhas, colunas, x_novo, y_novo))
                    return 1;
                
                matriz[x_novo][y_novo] = '0';
            }
        }
        return 0;

}


/*
    Função que busca a saída do labirinto a partir de um ponto inicial.
    Recebe: Um ponteiro para o labirinto e as coordenadas iniciais para começar a busca.
    Faz: Usa a função auxiliar "buscar_saida_recursivamente" para tentar encontrar um caminho da posição inicial até a saída. 
    Retorna: Um novo labirinto que representa o caminho encontrado.
*/
labirinto* buscar_saida(labirinto *l, int x, int y){
    int a = (*l).linhas;
    int b = (*l).colunas;
    int c;

    c = buscar_saida_recursivamente((*l).matriz, a, b, x, y);

    if (c == 1){
        return l;
    } else{
        printf("Deu ruim");
        return l;
    }
}

/*
   Função que imprime o conteúdo do labirinto no console.
   Recebe: Um ponteiro para o labirinto.
   Faz: Itera sobre a matriz e imprime cada caracter.
   Retorna: Nada.

*/

void imprimir_labirinto(labirinto *l){

    for (int i = 0; i < (*l).linhas; i++){
        printf("\n");
        for (int j = 0; j < (*l).colunas; j++){
            printf("%c" , (*l).matriz[i][j]);
            if (j< (*l).colunas-1){
                printf(" ");
            }
            if ((*l).matriz[i][j] == 'X'){
                (*l).matriz[i][j] = '0';
            }
        }
    }
    (*l).matriz[(*l).saidaX][(*l).saidaY] = 'S'; 
    printf("\n");
}

/*
   Função que libera a memória ocupada por um labirinto.
   Recebe: Um ponteiro para o labirinto.
   Faz: Libera a memória ocupada por todas as linhas da matriz e pela própria matriz.
   Retorna: Nada.
*/
void destruir_labirinto(labirinto *l){
    for (int i = 0; i < (*l).linhas; i++){
        free((*l).matriz[i]);
    }  
    free((*l).matriz);
    free(l);
}

int main (){
    int linhas;
    int colunas;
    labirinto *l;
    scanf("%dx%d" , &linhas, &colunas);
    l = criar_labirinto(linhas, colunas);
    ler_labirinto(l);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if ((*l).matriz[i][j] == 'P') {

                l= buscar_saida(l, i, j);
                imprimir_labirinto(l);

                (*l).matriz[i][j] = '0';
            }
                
        }
    }
    destruir_labirinto(l);
    return 0;
}