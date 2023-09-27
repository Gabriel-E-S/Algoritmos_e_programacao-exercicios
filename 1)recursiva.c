#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

//usando a funaoo de maneira recursiva, e verificado se n1> x, e depois se n1 e par, chamando a funcao novamente ate a primeira condicao ser satisfeita

void mostrar(int n1,int x){
    if(n1>x){
        return;
    }

    if(n1%2 == 0){
        printf("%d\n",n1);

    }
    mostrar(n1+1,x);
}
int main(){

    int n;
    printf("Digite um valor para N\n");
    scanf("%d",&n);
    printf("\n");

    mostrar(0,n);

    return 0;
}


