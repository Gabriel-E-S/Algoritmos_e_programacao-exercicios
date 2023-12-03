#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define tam 10


struct registro_livro{

    int codigo;
    bool doado;
    char nomeobra[30];
    char nomeautor[30];
    char editora[30];
    int numpag;
};
typedef struct registro_livro registro_livro;

void criararquivos(){

    int i = 0;

    FILE *f1 = fopen("exatas.dat","wb");
    FILE *f2 = fopen("humanas.dat","wb");
    FILE *f3 = fopen("biomedicas.dat","wb");

    if( f1 && f2 && f3){

        registro_livro exatas[tam] = {
        {1, true, "Livro Um", "Autor Um", "Editora A", 200},
        {2, false, "Livro Dois", "Autor Dois", "Editora B", 300},
        {3, true, "Livro Três", "Autor Três", "Editora C", 250},
        {4, false, "Livro Quatro", "Autor Quatro", "Editora A", 180},
        {5, true, "Livro Cinco", "Autor Cinco", "Editora D", 150},
        {6, false, "Livro Seis", "Autor Seis", "Editora B", 220},
        {7, true, "Livro Sete", "Autor Sete", "Editora E", 280},
        {8, false, "Livro Oito", "Autor Oito", "Editora C", 320},
        {9, true, "Livro Nove", "Autor Nove", "Editora A", 260},
        {10, false, "Livro Dez", "Autor Dez", "Editora D", 190}
            };

        registro_livro humanas[tam] = {
                {11, true, "Livro Onze", "Autor Onze", "Editora B", 210},
                {12, false, "Livro Doze", "Autor Doze", "Editora C", 270},
                {13, true, "Livro Treze", "Autor Treze", "Editora A", 230},
                {14, false, "Livro Quatorze", "Autor Quatorze", "Editora D", 290},
                {15, true, "Livro Quinze", "Autor Quinze", "Editora E", 350},
                {16, false, "Livro Dezesseis", "Autor Dezesseis", "Editora A", 240},
                {17, true, "Livro Dezessete", "Autor Dezessete", "Editora B", 310},
                {18, false, "Livro Dezoito", "Autor Dezoito", "Editora C", 280},
                {19, true, "Livro Dezenove", "Autor Dezenove", "Editora D", 260},
                {20, false, "Livro Vinte", "Autor Vinte", "Editora E", 320}
            };

        registro_livro biomedicas[tam] = {
                {21, true, "Livro Vinte e Um", "Autor Vinte e Um", "Editora A", 180},
                {22, false, "Livro Vinte e Dois", "Autor Vinte e Dois", "Editora B", 220},
                {23, true, "Livro Vinte e Três", "Autor Vinte e Três", "Editora C", 280},
                {24, false, "Livro Vinte e Quatro", "Autor Vinte e Quatro", "Editora D", 320},
                {25, true, "Livro Vinte e Cinco", "Autor Vinte e Cinco", "Editora E", 260},
                {26, false, "Livro Vinte e Seis", "Autor Vinte e Seis", "Editora A", 190},
                {27, true, "Livro Vinte e Sete", "Autor Vinte e Sete", "Editora B", 210},
                {28, false, "Livro Vinte e Oito", "Autor Vinte e Oito", "Editora C", 270},
                {29, true, "Livro Vinte e Nove", "Autor Vinte e Nove", "Editora D", 230},
                {30, false, "Livro Trinta", "Autor Trinta", "Editora E", 290}
            };

            fwrite(exatas, sizeof(registro_livro), tam, f1);
            fwrite(humanas, sizeof(registro_livro), tam, f2);
            fwrite(biomedicas, sizeof(registro_livro), tam, f3);

            fclose(f1);fclose(f2);fclose(f3);
            printf("Arquivos criados com sucesso!\n");

    }
    else{
        printf("Erro ao abrir arquivos!\n\n");
    }
}


void imprimecopia(registro_livro copia){


    printf("\n\nCÓDIGO: %d\n",copia.codigo);
    if(copia.doado){
            printf("DOADO: SIM\n");
    }
    else{
            printf("DOADO: NÃO\n");
    }
    printf("NOME DA OBRA: %s\n",copia.nomeobra);
    printf("NOME DO AUTOR: %s\n",copia.nomeautor);
    printf("EDITORA: %s\n",copia.editora);
    printf("NUM DE PAGS: %d\n",copia.numpag);
    printf("-------------------------------------\n");

}

void consultaporcodigo(int codigo, char nomearquivo[]){

    FILE *file = fopen(nomearquivo,"rb");
    registro_livro copia;
    bool achei = false;

    if(file){

            while(fread(&copia,sizeof(registro_livro),1,file) && !achei){

                if(copia.codigo == codigo){
                    achei = true;
                    imprimecopia(copia);
                }
            }

            if(!achei){
                printf("Livro não encontrado no sistema!\n");
            }

            fclose(file);

    }
    else{
        printf("Erro ao abrir arquivo pra consulta\n\n");
    }


}


void menuconsulta(){

    int codigo = 1,opc;

    while(codigo != -1){

        printf("Digite o código da obra(-1 para sair):\n");
        scanf("%d",&codigo);

        if(codigo == -1){
            break;
        }

        printf("Digite a área da obra ( 1- exatas, 2- humanas, 3- biomedicas):\n");
        scanf("%d",&opc);

        switch(opc){

            case 1:{
                consultaporcodigo(codigo,"exatas.dat");
                break;
            }
            case 2:{
                consultaporcodigo(codigo,"humanas.dat");
                break;
            }
            case 3:{
                consultaporcodigo(codigo,"biomedicas.dat");
                break;
            }

        }

    }
}

void consultapornome(char nome[], char nomearquivo[]){

    FILE *file = fopen(nomearquivo,"rb");
    registro_livro copia;
    bool achei = false;

    if(file){

            while(fread(&copia,sizeof(registro_livro),1,file) && !achei){

                if(strcmp(copia.nomeobra,nome) == 0){
                    achei = true;
                    imprimecopia(copia);
                }
            }

            if(!achei){
                printf("Livro não encontrado no sistema!\n");
            }

            fclose(file);

    }
    else{
        printf("Erro ao abrir arquivo pra consulta\n\n");
    }
}

void menuconsultanome(){

    int opc;
    char nomep[30];

    while(nomep != "-1"){

        printf("Digite o nome da obra(-1 para sair):\n");
        scanf("%[^\n]s",&nomep);
        fflush(stdin);

        printf("Digite a área da obra ( 1- exatas, 2- humanas, 3- biomedicas):\n");
        scanf("%d",&opc);

        switch(opc){

            case 1:{
                consultapornome(nomep,"exatas.dat");
                break;
            }
            case 2:{
                consultapornome(nomep,"humanas.dat");
                break;
            }
            case 3:{
                consultapornome(nomep,"biomedicas.dat");
                break;
            }

        }

    }
}


void listadoados(char nomearq[]){

    FILE *file = fopen(nomearq,"rb");
    registro_livro copia;

    if(file){

            while(fread(&copia,sizeof(registro_livro),1,file)){
                if(copia.doado == true){
                    imprimecopia(copia);

                }
            }
            fclose(file);

    }
    else{
        printf("Erro ao avrir arq\n");
    }

}

void menudoados(){

    printf("\n\n**********DOADOS ÁREA EXATAS**********\n\n");
    listadoados("exatas.dat");
    printf("\n\n**********DOADOS ÁREA HUMANAS**********\n\n");
    listadoados("humanas.dat");
    printf("\n\n**********DOADOS ÁREA BIOMÉDICAS**********\n\n");
    listadoados("biomedicas.dat");

}

void listandoadosfaixa(char nomearq[]){

    FILE *file = fopen(nomearq,"rb");
    registro_livro copia;

    if(file){

            while(fread(&copia,sizeof(registro_livro),1,file)){
                if(copia.doado == false && copia.numpag > 100 && copia.numpag < 300){
                    imprimecopia(copia);

                }
            }
            fclose(file);

    }
    else{
        printf("Erro ao avrir arq\n");
    }

}

void menundoadosfaixa(){

    printf("\n\n**********N DOADOS COM PG ENTRE 100 E 300 ÁREA EXATAS**********\n\n");
    listandoadosfaixa("exatas.dat");
    printf("\n\n**********N DOADOS COM PG ENTRE 100 E 300 ÁREA HUMANAS**********\n\n");
    listandoadosfaixa("humanas.dat");
    printf("\n\n**********N DOADOS COM PG ENTRE 100 E 300 ÁREA BIOMÉDICAS**********\n\n");
    listandoadosfaixa("biomedicas.dat");

}

void alterarregistro(int codigo, char nomearq[]){

    FILE *file = fopen(nomearq,"rb+");
    registro_livro copia;
    int simounao;
    bool existe = false;

    if(file){

            while(fread(&copia,sizeof(registro_livro),1,file) && !existe){
                if(copia.codigo == codigo){
                    existe = true;

                    fseek(file,-sizeof(registro_livro),SEEK_CUR);

                    fflush(stdin);
                    printf("Digite o novo nome da obra:\n");
                    scanf("%[^\n]s",copia.nomeobra);
                    fflush(stdin);
                    printf("Digite o novo nome do autor:\n");
                    scanf("%[^\n]s",copia.nomeautor);
                    fflush(stdin);
                    printf("Digite o novo nome da editora:\n");
                    scanf("%[^\n]s",copia.editora);
                    fflush(stdin);
                    printf("Esse livro foi: 1 - doado, 2 - comprado:");
                    scanf("%d",&simounao);
                    fflush(stdin);
                    if(simounao == 1){
                        copia.doado = true;
                    }
                    else{
                    copia.doado = false;
                    }
                    printf("Digite o novo num de pags:\n");
                    scanf("%d",&copia.numpag);
                    fflush(stdin);
                    printf("Digite o nov código:\n");
                    scanf("%d",&copia.codigo);
                    fflush(stdin);
                    fwrite(&copia,sizeof(registro_livro),1,file);
                    printf("registros alterados com sucesso!\n");

                }
            }


        fclose(file);
    }
    else{
        printf("erro ao arir arquivo\n");
    }

    if(!existe){
        printf("O livro não foi encontrado!");
    }


}

void menualterarregistro(){

    int codigo,opc;

    printf("Digite o código da obra para alterar:\n");
    scanf("%d",&codigo);

    printf("Digite a área da obra ( 1- exatas, 2- humanas, 3- biomedicas):\n");
    scanf("%d",&opc);



    switch(opc){

            case 1:{
               alterarregistro(codigo,"exatas.dat");
                break;
            }
            case 2:{
                alterarregistro(codigo,"humanas.dat");
                break;
            }
            case 3:{
                alterarregistro(codigo,"biomedicas.dat");
                break;
            }

        }

    }

void excluiregistro(int codigo,char nomearq[]){

    FILE *file = fopen(nomearq,"rb");
    registro_livro copia;

    if(file){

            FILE *aux = fopen("arqaux.dat","wb");

            if(aux){
                while(fread(&copia,sizeof(registro_livro),1,file)){
                    if(copia.codigo != codigo){
                        fwrite(&copia,sizeof(registro_livro),1,aux);
                    }
                }

            }
            else{
                printf("erro ao abrir pra excluir\n");
            }
            fclose(file);
            fclose(aux);
    }
    else{
        printf("erro ao abrir pra excluir\n");
    }

    remove(nomearq);

    if(rename("arqaux.dat",nomearq) != 0){
        printf("Erro ao renomear!\n");
    }
    else{
        printf("registro excluido com sucesso!\n");
    }
}

void menuexcluirregistro(){

    int codigo,opc;

    printf("Digite o código da obra para excluir:\n");
    scanf("%d",&codigo);

    printf("Digite a área da obra ( 1- exatas, 2- humanas, 3- biomedicas):\n");
    scanf("%d",&opc);

    switch(opc){

            case 1:{
               excluiregistro(codigo,"exatas.dat");
                break;
            }
            case 2:{
               excluiregistro(codigo,"humanas.dat");
                break;
            }
            case 3:{
               excluiregistro(codigo,"biomedicas.dat");
                break;
            }

        }




}




int main(){

    setlocale(LC_ALL,"");
    int opcao = 1;

    criararquivos();

    while(opcao != 7){

        system("cls");
        printf("\n\nMENU\n\n");
        printf("1- PESQUISA USANDO O CÓDIGO\n");
        printf("2- PESQUISA USANDO O NOME\n");
        printf("3- LISTAR TODOS OS LIVROS DOADOS\n");
        printf("4- LiSTAR TODOS OS LIVROS COMPRADOS COM PGS. ENTRE 100 E 300\n");
        printf("5- ALTERAR CADASTRO\n");
        printf("6- EXCLUIR LIVRO\n");
        printf("ESCOLHA A OPÇÃO --->  ");
        scanf("%d",&opcao);

        switch(opcao){

                case 1:{
                    menuconsulta();
                    break;
            }
                case 2:{
                    menuconsultanome();
                    break;
            }
                case 3:{
                    menudoados();
                    break;
            }
                case 4:{
                    menundoadosfaixa();
                    break;
            }
                case 5:{
                   menualterarregistro();
                    break;
            }
                case 6:{
                   menuexcluirregistro();
                    break;
            }
                case 7:{
                    printf("Você escolheu sair!\n");
                }
                default:{
                    printf("OPÇÃO INVÁLIDA!!\n\n");
            }


        }
        system("pause");
    }
    return 0;
}
