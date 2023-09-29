#include <stdio.h>
#include <locale.h>
#include <math.h>

//aqui foi feito uma funcao para potencia considerando as 3 possibilidades

float potencia(float X1, int n1) {
    int i;
    float res = 1;
    if (n1 > 0) {
        for (i = 0; i < n1; i++) {
            res = res * X1;
        }
    } else if (n1 < 0) {
        for (i = 0; i < -n1; i++) {
            res = res / X1;
        }
    }
    return res;
}

int main() {
    int n;
    float X;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite o valor real para X:\n");
    scanf("%f", &X);

    printf("Digite o valor inteiro para N:\n");
    scanf("%d", &n);

    printf("O resultado e: %.2f", potencia(X, n));

    return 0;
}

