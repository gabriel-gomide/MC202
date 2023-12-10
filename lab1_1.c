#include <stdio.h>
#define MAX 1000

// Converte todas as letras para minúsculo
void masc(char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + 32;
        }
    }
}

// Mede o comprimento de uma string
int comprimento(char palavra[]) {
    int comp = 0;
    while (palavra[comp] != '\0') {
        comp += 1;
    }
    return comp;
}

int comprimento2(char palavra[]){
    int comp = 0;
    int cont = 0;
    while (palavra[cont] != '\0') {
        if (palavra[cont] != '+'){
            comp += 1;
        }
        cont++;
        
    }
    return comp;
}

// Remove espaços
void esp(char str[]) {
    int len = 0;  
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            str[len] = str[i];
            len++;
        }
    }

    str[len] = '\0';  
}

// Remove um caractere do array
void tiraum(int a, char m[], int tamanho) {
    for (int j = a; m[j] != '\0'; j++) {
        m[j] = m[j + 1];
    }
    m[tamanho-1] = '\0';
}

unsigned int busca_motivo (char s[], char m[])
{
  int aux, k;
  unsigned int tamanho_m, n, b, a, c, tamanho_m2;

  // Definindo o comprimento de m e colocando tudo em minúsculo
  tamanho_m = comprimento(m);
  tamanho_m2 = comprimento2(m);
  masc(s);
  masc(m);
  esp(s);
  esp(m);
  // Verificando a existência de ? e lidando com isso
  for (int i = 0; i < tamanho_m; i++){
    if (m[i]=='?'){
      tiraum(i, m, tamanho_m);
      tamanho_m = tamanho_m -1;
      a = busca_motivo(s,m);
      tiraum(i-1, m, tamanho_m);
      tamanho_m = tamanho_m - 1;
      c = busca_motivo(s, m);
      return a+c;
      break;
        }
    }

    //Conta o número de sucessos
    n = 0;
    //Indice do primeiro caractere da string s
    b = 0;
    while (s[b+1] != '\0') {
        //Conta o número de letras semelhantest
        aux = 0;
        //Avança o indice em s
        int j = 0;
        tamanho_m2 = comprimento2(m);
        for (int i = 0; m[i] !='\0'; i++) {
            if (s[j+b] == '\0'){
                break;
            }
            if (m[i] == '+') {
                k = i;
                char letra_anterior = m[i - 1]; // Pega a letra anterior
                int ocorrencias = 0;
                while (s[j + b] == letra_anterior) {
                    
                    ocorrencias++;
                    j++;
                    if (m[i+1] == m[i-1] || s[j+b]=='\0'){
                        break;
                    }
        }
                if (ocorrencias >= 1) {
                    aux = aux + ocorrencias;
                    tamanho_m2 = tamanho_m2 + ocorrencias;
        }       
        i++;

        }
            if (s[j+b] == '\0'){
                break;
            }
            if (s[j + b] == m[i] || m[i] == '.') {
                aux = aux + 1;
            } else {
                break;
            }

            j++;
        }
        if (aux == tamanho_m2) {
            n = n + 1;
            b = b + j;
        }else{ 
        b = b + 1;}
    }
    if (n==0){
        tiraum(k, m, tamanho_m);
        n = busca_motivo(m, s);
    }
    return n;
}



int main ()
{
  char s[MAX], m[MAX];
  int i = 0;
  scanf("%s", m);
  // printf("foi\n");
  do
  {
    s[i] = getchar ();
    if (s[i] != EOF)
    {
      i++;
    }
  }
  while (s[i] != EOF);
  s[i] = '\0';
  printf("%u\n", busca_motivo(s, m));
  return 0;
}