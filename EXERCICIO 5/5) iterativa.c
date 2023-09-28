#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int qualemaior(int veto[],int tam){
    int maior = veto[0] ;
    int i;
    for(i=1;i<tam;i++){
    if(veto[i]>maior){
        maior = veto[i];
    }
}
    return maior;
}

main(){

    setlocale(LC_ALL,"Portuguese");
    int tama,i,vet[10],res;
    printf("Digite o tamanho do vetor\n");
    scanf("%d",&tama);

    for(i=0;i<tama;i++){
        printf("V[%d] = \n",i+1);
        scanf("%d",&vet[i]);
    }
    res = qualemaior(vet,tama);
    printf("O maior elemento é: %d\n",res);


}
