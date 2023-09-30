#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

//essa funcao usa o algoritmo de Euclides, qualquer duvida sugiro pesquisar sobre ele

int MDC(int n1,int n2){
    int resto=1,aux;
    if(n2>n1){
        aux = n1;
        n1 = n2;
        n2 = aux;
    }

    while(resto!=0){
        resto = n1%n2;
        n1 = n2;
        n2 = resto;
    }
    return n1;

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
