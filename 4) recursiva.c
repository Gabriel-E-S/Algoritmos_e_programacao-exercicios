#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int somat(int N){
    if(N==0){
    return 0;
    }
    else{
        return N + somat(N-1);

    }

}
main(){
    int n;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite o valor para N:\n");
    scanf("%d",&n);

    printf("A soma de 0 até %d é: %d",n,somat(n));
}



