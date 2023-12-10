#include <stdio.h>
#include <stdlib.h>

int fat(int n) {
 int ret, ant;
 if (n == 0)
 ret = 1;
 else {
 ant = fat(n-1);
 ret = n * ant;
}
 return ret;
 }

int main(){
 int x;
 x = fat(4);
 printf("%d", x);
}