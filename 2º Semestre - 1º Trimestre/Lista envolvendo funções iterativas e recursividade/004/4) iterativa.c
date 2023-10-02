#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//faz a soma
int somat(int N){
    int i,soma=0;

    for(i=0;i<=N;i++){
        soma = soma+i;
    }
    return soma;


}
int main(){
    int n;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite o valor para N:\n");
    scanf("%d",&n);

    printf("A soma de 0 até %d é: %d",n,somat(n));
    return 0;
}



