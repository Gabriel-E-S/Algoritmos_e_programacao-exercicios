#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int binario(int num);

int main(){

    setlocale(LC_ALL,"Portuguese");
    int numero;

    printf("digite um n�mero:\n");
    scanf("%d",&numero);

    printf("N�mero em bin�rio:\n");
    binario(numero);
}

int binario(int num){
    if(num>1){
        binario(num/2);
    }
    printf("%d",num%2);
}
