#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"Portuguese");

    int num, c, resultado;

    printf("****MOSTRA A TABUADA DE QUALQUER NÚMERO****\n\n");

    printf("Insira um número para ver sua tabuada:\n");
    scanf("%d",&num);

    for(c=0; c<=10;c++){
            resultado = num * c;

        printf("\n%d x %d = %d",num, c, resultado);
    }
    getch();
    return 0;
}
