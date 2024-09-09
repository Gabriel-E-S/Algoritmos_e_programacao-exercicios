//////////////////////////////////////////////////////////////////////
//  VERSÃO FEITA POR: Gabriel E.Santo                               //
//  Lembrando que essa é apenas uma das inúmeras soluções possíveis //
//                                                                  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

// bibliotecas que vão ser usadas

#include <stdio.h>      // biblioteca padrão de C
#include <locale.h>     // acentuação
#include <string.h>     // operações com strings


#define N 5                 // tamanho do vetor
#define TamanhoNomes 30     // tamanho máximo das strings

typedef struct Reg_pessoa {  // estrutura usada para o problema
    char nome[TamanhoNomes];
    int idade;
    int excluido;
}Reg_pessoa;

int busca(Reg_pessoa vetor[], char nome[],int n){ // função que faz a busca

    int i;

    for(i=0;i<n;i++){                             // percorre-se o vetor do índice 0 até o tamanho atual procurando por um nome igual
        if(strcmp(vetor[i].nome,nome) == 0){      // se strcmp retornar 0 os nomes são iguais
            return i;                             // com isso retornamos o índice do nome encontrado
        }
    }
    return -1;                                    // se não encontramos o nome a função retorna -1
}


void leitura(Reg_pessoa vetor[], int *tamanhoAtual){

    int i, escolha;
    char nome[TamanhoNomes];

    i = *tamanhoAtual;

    while(i<N){

        printf("\nDIGITE O %d NOME: ",i+1);
        scanf("%[^\n]s",nome);
        while(getchar()!= '\n'); // Limpa o buffer do teclado

        if(busca(vetor,nome,*tamanhoAtual) != -1){
            printf("ESSE NOME JÁ EXISTE NO VETOR!\n");
        }
        else{
            strcpy(vetor[i].nome,nome);         // atualiza o nome do vetor

            printf("DIGITE A %d IDADE ",i+1);
            scanf("%d",&vetor[i].idade);        // atualiza a idade
            while(getchar()!= '\n');            // Limpa o buffer do teclado

            vetor[i].excluido = 0;              // inicializa o campo excluido com falso

            *tamanhoAtual+=1;                   // aumentamos o tamanho atual do vetor

            i++;                                // mudamos o critério de parada do while
        }
        printf("\nDESEJA CONTINUAR CADASTRANDO?\nPRESSIONE QUALQUER TECLA PARA CONTINUAR, -1 PARA SAIR --> ");
        scanf("%d",&escolha);
        while(getchar()!= '\n'); // Limpa o buffer do teclado

        if(escolha == -1){                      // se a escolha for -1 então voltamos para o menu
            break;                              // o break interrompe a iteração atual de um laço
        }
    }
    if(i == N){
        printf("\nVETOR CHEIO!\n");
    }
}

// procedimento que imprime a tabela
// algumas considerações:
// os números depois do % representam o máximo de caracteres imprimidos,
// o * foi usado para garantir o alinhamento e o -TamanhoNomes alinha eles pela esquerda.

void relatorio(Reg_pessoa vetor[], int *tamanhoAtual) {
    int i;
    printf("\n\n\t*********RELATÓRIO*********\n\n");
    printf("   REGISTRO     NOME                        IDADE\n");
    printf("--------------------------------------------------\n");

    for (i = 0; i < *tamanhoAtual; i++) {
        if (vetor[i].excluido == 0) {
            printf("%8d       %*s %-3d\n", i + 1,-TamanhoNomes, vetor[i].nome, vetor[i].idade);
        }
    }
    printf("\n\n");
}

// procedimento de exclusão lógica

void excluir(Reg_pessoa vetor[], int n,char nome[]){

    int i,escolha;

    i = busca(vetor,nome,n); // se a busca for bem sucedida então confirmamos e realizamos a exclusão

    if( i != -1){

        printf("NOME = %s\nIDADE = %d\n",vetor[i].nome,vetor[i].idade);
        printf("REALIZAR A EXCLUSÃO?(1-SIM,2-NÃO)\n");
        scanf("%d",&escolha);

        if(escolha == 1){
            printf("EXCLUÍDO COM SUCESSO\n");
            vetor[i].excluido = 1;
        }
        else{
            printf("OPERAÇÃO CANCELADA!\n");
        }
        return ;

    }
    printf("\nNÃO FOI ENCONTRADO O NOME NO VETOR!\n");
}


int main(){

    setlocale(LC_ALL,"Portuguese");

    Reg_pessoa dados[N];
    int tamanho = 0,opc  =1 ;
    char n[TamanhoNomes];

    // menu

    while(opc != 4){

        system("cls");

        printf("1- CADASTRAR\n");
        printf("2- EXCLUIR\n");
        printf("3- RELATÓRIO\n");
        printf("4- SAIR\n");
        printf("ESCOLHA -> ");
        scanf("%d",&opc);

        while(getchar()!= '\n'); // Limpa o buffer do teclado

        switch(opc){

            case 1:{
                leitura(dados,&tamanho);
                break;
            }
            case 2:{
                printf("\nDIGITE O NOME PARA EXCLUIR: ");
                scanf("%[^\n]s",&n);
                excluir(dados,tamanho,n);
                break;
            }
            case 3:{
                relatorio(dados,&tamanho);
                break;
            }
            case 4:{
                break;
            }
            default:{
                printf("\nESCOLHA INVÁLIDA!\n");
            }
        }
        printf("\n\n");system("pause");


    }

    return 0;
}
