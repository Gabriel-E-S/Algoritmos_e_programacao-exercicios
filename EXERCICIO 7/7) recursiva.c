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
    int soma=0;

    if(n == 1){
        return 1;
    }
    else{
        soma = pow(n,3);
        return soma + somacubo(n-1);
    }
}
