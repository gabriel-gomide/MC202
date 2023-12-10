#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100

void copia(char str1[], char str2[]){
int i;
for (i=0; str1[i]!='\0'; i++){
    str2[i]=str1[i];
}
    printf("%s\n", str2);
}
void reverte(char str[]){
    int i, j;
    char inverso[MAX];
    i = strlen(str)-1;
    j = 0;                          
    while (i >= 0) {
        inverso[j] = str[i];
        i = i - 1;
        j = j + 1;
    }
    inverso[j] = '\0';
    str = inverso;
    printf("%s", str);
}
int compara(char str1[], char str2[]){
    int i;
    if (strlen(str1) < strlen(str2)){
        return -1;
    }
    if (strlen(str1) > strlen(str2)){
        return 1;
    }
    if (strcmp(str1, str2) == 0){
        return 0;
    }
}

int main(){
char str1[MAX], str2[MAX];
int a;
scanf("%s", str1);
copia(str1, str2);
reverte(str1);
a = compara(str1, str2);
printf("\n%d", a);
}