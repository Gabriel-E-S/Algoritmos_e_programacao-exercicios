#include <stdio.h>
#include <locale.h>

void impBinario(int numero) {
    int binario[32]; // M�ximo de 32 d�gitos bin�rios para um n�mero inteiro
    int indice = 0, i;

    while (numero > 0) {
        binario[indice] = numero % 2;
        numero = numero/2;
        indice++;
    }

    if (indice == 0) {
        printf("0"); // Lidando com o caso do n�mero ser 0
    } else {
        for (i = indice - 1; i >= 0; i--) {
            printf("%d", binario[i]);
        }
    }
}

main() {
    int num;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite um n�mero decimal: ");
    scanf("%d", &num);

    printf("Representa��o bin�ria: \n");
    impBinario(num);
}
