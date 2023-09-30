#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int somat(int vet[],int tam);

int main(){

    setlocale(LC_ALL,"Portuguese");

    int tama,vetor[50],i,res;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d",&tama);

    for(i=0;i<tama;i++){
        printf("V[%d] =\n ",i+1);
        scanf("%d",&vetor[i]);
    }
    res = somat(vetor,tama);

    printf("A soma � : %d",res);

    return 0;
}

int somat(int vet[],int tam){
    if(tam == 1){
        return vet[0];
    }
    else{
        return vet[tam-1]+ somat(vet,tam-1);

    }




}
