#include <stdio.h>
#include <locale.h>

void impBinario(int numero) {
    int binario[32]; // Máximo de 32 dígitos binários para um número inteiro
    int indice = 0, i;

    while (numero > 0) {
        binario[indice] = numero % 2;
        numero = numero/2;
        indice++;
    }

    if (indice == 0) {
        printf("0"); // Lidando com o caso do número ser 0
    } else {
        for (i = indice - 1; i >= 0; i--) {
            printf("%d", binario[i]);
        }
    }
}

main() {
    int num;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite um número decimal: ");
    scanf("%d", &num);

    printf("Representação binária: \n");
    impBinario(num);
}
