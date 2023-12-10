#include <stdio.h>

double soma(char op, double op1, double op2){
    if (op=='+'){
    return op1+op2;
    }
    return 0;
}
double sub(char op, double op1, double op2){
    if (op=='-'){
    return op1-op2;
    }
    return 0;
}
double multi(char op, double op1, double op2){
    if (op=='*'){
    return op1*op2;
    }
    return 0;
}
double div(char op, double op1, double op2){
    if (op=='/'){
    return op1/op2;
    }
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    int aux=1;
    while (aux<=n){
        double op1, op2;
        char op;
        scanf("%lf %c %lf", &op1, &op, &op2);
        aux=aux+1;
        double res = 0;
        switch (op) {
            case '+':
                res = soma(op, op1, op2);
                break;
            case '-':
                res = sub(op, op1, op2);
                break;
            case '*':
                res = multi(op, op1, op2);
                break;
            case '/':
                res = div(op, op1, op2);
                break;
            default:
                printf("Invalid operator\n");
                break;
        }
        printf("%lf\n", res);
    }
    return 0;
}