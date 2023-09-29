#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int somat(int vet[],int tam);

void main(){

    setlocale(LC_ALL,"Portuguese");

    int tama,vetor[50],i,res;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d",&tama);

    for(i=0;i<tama;i++){
        printf("V[%d] =\n ",i+1);
        scanf("%d",&vetor[i]);
    }
    res = somat(vetor,tama);

    printf("A soma é : %d",res);
}

int somat(int vet[],int tam){
    int i, soma =0;
    for(i=0;i<tam;i++){
        soma = soma + vet[i];
    }
    return  soma;


    }





