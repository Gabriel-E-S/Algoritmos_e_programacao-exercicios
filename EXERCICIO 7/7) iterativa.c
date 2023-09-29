#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


int somacubo(int n);

void main(){
    setlocale(LC_ALL,"Portuguese");
    int N,res;

    printf("digite o valor pra N:\n");
    scanf("%d",&N);

    res = somacubo(N);

    printf("A soma é %d",res);
}

int somacubo(int n){

    int soma= 0 ,i;
    for(i=1;i<=n;i++){
    soma = soma+pow(i,3);
    }
    return soma;}
