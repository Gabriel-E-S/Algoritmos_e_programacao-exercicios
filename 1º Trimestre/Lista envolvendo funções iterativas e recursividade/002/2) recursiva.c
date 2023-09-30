#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


//nessa funcao recursiva o resto vai sendo alterado ate ser 0, quando isso acontece a funcao retorna o mdc

int MDC(int n1,int n2){


    if(n2==0){
        return n1;
    }
    else{
        return MDC(n2,n1%n2);
    }

}


int main(){
    setlocale(LC_ALL,"Portuguese");

    int num1,num2;

    printf("Digite o primeiro número:\n");
    scanf("%d",&num1);

    printf("Digite o segundo número:\n");
    scanf("%d",&num2);

    printf("\nO mdc é %d\n",MDC(num1,num2));
    return 0;
}


