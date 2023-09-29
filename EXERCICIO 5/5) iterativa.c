#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int qualemenor(int veto[],int tam){
    int menor = veto[0] ;
    int i;
    for(i=1;i<tam;i++){
    if(veto[i]<menor){
        menor = veto[i];
    }
}
    return menor;
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
    res = qualemenor(vet,tama);
    printf("O menor elemento é: %d\n",res);
}
