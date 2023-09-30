#include <stdio.h>
#include <locale.h>


//funçao para mostrar somente os números pares
// aqui ele faz um laço de repeticao de 0 ate o número informado, vendo se ele e par e imprimindo- o na tela se isso for verdade

void mostrar(int n1){
   int i;
   for(i=0;i<=n1;i++){
        if(i%2==0){
            printf("%d\n",i);
        }
   }
}

main(){
    int n;

    printf("digite o valor de N:\n");
    scanf("%d",&n);


mostrar(n);





}
