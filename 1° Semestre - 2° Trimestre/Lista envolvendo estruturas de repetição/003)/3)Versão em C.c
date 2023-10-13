#include <stdio.h>
#include <locale.h>

int main() {
	
    setlocale(LC_ALL,"Portuguese");
    
    int denominador,n;
    float soma;
    
    soma = 0.0;
    
    printf("****Veja o valor de H=1 + 1/2 + 1/N sendo N um número de sua escolha******\n\n");
    
    printf("Escolha um valor inteiro para N:\n");
    scanf("%d",&n);
    
    for(denominador=1;denominador<=n;denominador++){
    	
		soma = soma+1.0/denominador;
	}
	
	printf("\nO valor de H quando N é %d vale: %f",n,soma);
	
	getch();
}
