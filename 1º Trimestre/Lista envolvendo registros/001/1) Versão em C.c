#include <stdio.h>
#include <locale.h>
#define TAM 15

struct Reg_data{
    int dia;
    int mes;
    int ano;
};
typedef struct Reg_data data;

struct Cadastro{
    char nome[30];
    char telefone[20];
    data nascimento;
};
typedef struct Cadastro Cadastro;

Cadastro pessoas[TAM] = {
        {"Pessoa 1", "423923829", {15, 4, 2005}},
        {"Pessoa 2", "987654321", {20, 8, 1990}},
        {"Pessoa 3", "555555555", {5, 12, 1985}},
        {"Pessoa 4", "123456789", {10, 2, 2000}},
        {"Pessoa 5", "999999999", {25, 6, 1995}},
        {"Pessoa 6", "777777777", {14, 9, 1978}},
        {"Pessoa 7", "888888888", {30, 3, 1993}},
        {"Pessoa 8", "222222222", {8, 11, 1982}},
        {"Pessoa 9", "111111111", {12, 7, 2003}},
        {"Pessoa 10", "666666666", {18, 1, 1998}},
        {"Pessoa 11", "444444444", {3, 10, 1970}},
        {"Pessoa 12", "333333333", {22, 9, 2008}},
        {"Pessoa 13", "999888777", {16, 5, 1965}},
        {"Pessoa 14", "555222111", {7, 12, 1991}},
        {"Pessoa 15", "777888999", {9, 8, 1980}},
        };

void consulta(int mes){
    int i;

    for(i=0;i<TAM;i++){
            if(pessoas[i].nascimento.mes == mes){
                printf("\nNOME: %s\n",pessoas[i].nome);
                printf("TELEFONE: %s\n",pessoas[i].telefone);
                printf("DIA DE NASCIMENTO: %d\n",pessoas[i].nascimento.dia);
            }

    }


}

int main(){
    setlocale(LC_ALL,"");
    int mes = 1;

    while(mes!= 0){
        printf("Digite o mês:\n");
        scanf("%d",&mes);
        consulta(mes);
    }


return 0;
}
