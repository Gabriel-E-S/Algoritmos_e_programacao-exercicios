#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

bool epalindromo(char num[]);

int main() {
    setlocale(LC_ALL, "");

    char num[30];

    printf("Digite um n�mero e verifique se ele � pal�ndromo:\n");
    scanf("%s", &num);

    if (epalindromo(num)) {
        printf("%s � um pal�ndromo.\n", num);
    } else {
        printf("%s n�o � um pal�ndromo.\n", num);
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
