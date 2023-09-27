#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int qualemenor(int veto[],int tam){
    int mv;
    if(tam ==1){
        return veto[0];
    }
    else{
        mv = qualemenor(veto,tam-1);
        if(veto[tam-1]<mv){
            return veto[tam-1];
        }
        else{
            return mv;
        }
    }
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
