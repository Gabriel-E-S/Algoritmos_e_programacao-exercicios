#include <stdio.h>
#include <locale.h>

//usando logica recursiva

float potencia(float base, int exp){
    if(exp ==0){
        return 1.0;
    }
    if(exp>0){
        return base*potencia(base,exp-1);
    }
    else{
        return 1.0/potencia(base,-exp);
    }


}
int main(){

    float X;
    int n;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite o valor real para X:\n");
    scanf("%f",&X);

    printf("Digite o valor inteiro para N:\n");
    scanf("%d",&n);

    printf("O resultado é: %.2f",potencia(X,n));
    return 0;
}
