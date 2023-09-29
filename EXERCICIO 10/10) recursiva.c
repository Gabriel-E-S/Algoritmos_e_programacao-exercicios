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

    printf("Digite um n�mero e verifique se ele � pal�ndromo:\n");
    scanf("%s", &num);
    j = strlen(num)-1;

    if (epalindromo(num,i,j)) {
        printf("%s � um pal�ndromo.\n", num);
    } else {
        printf("%s n�o � um pal�ndromo.\n", num);
    }

    return 0;
}
