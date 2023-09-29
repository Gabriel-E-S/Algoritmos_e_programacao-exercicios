#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

bool epalindromo(char num[30],int i,int j){

      if (i >= j) {
        return true;
    }

    if (num[i] != num[j]) {
        return false;
    }

    return epalindromo(num, i + 1, j - 1);

}

int main() {
    setlocale(LC_ALL, "");

    char num[30];
    int i=0,j;

    printf("Digite um número e verifique se ele é palíndromo:\n");
    scanf("%s", &num);
    j = strlen(num)-1;

    if (epalindromo(num,i,j)) {
        printf("%s é um palíndromo.\n", num);
    } else {
        printf("%s não é um palíndromo.\n", num);
    }

    return 0;
}
