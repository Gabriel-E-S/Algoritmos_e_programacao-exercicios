#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

bool epalindromo(char num[]);

int main() {
    setlocale(LC_ALL, "");

    char num[30];

    printf("Digite um número e verifique se ele é palíndromo:\n");
    scanf("%s", &num);

    if (epalindromo(num)) {
        printf("%s é um palíndromo.\n", num);
    } else {
        printf("%s não é um palíndromo.\n", num);
    }

    return 0;
}

bool epalindromo(char num[]) {
    int i;
    int j = strlen(num)-1;

    for(i=0;i<strlen(num)/2;i++,j--){
        if(num[i]!=num[j]){
            return false;
        }
    }
    return true;
}
