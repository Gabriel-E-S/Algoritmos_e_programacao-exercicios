#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define tam 10

//função para mudar o cursor de lugar na tela e deixá-lo invisível

void gotoxy(int lin, int col) {
    COORD coord;
    coord.X = col - 1;
    coord.Y = lin - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    CONSOLE_CURSOR_INFO info;
    info.bVisible = false;
    info.dwSize = 100;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info);
}

//COR TEXTO
enum{
    BLACK,          //0
    BLUE,           //1
    GREEN,          //2
    CYAN,           //3
    RED,            //4
    MAGENTA,        //5
    BROWN,          //6
    LIGHTGRAY,      //7
    DARKGRAY,       //8
    LIGHTBLUE,      //9
    LIGHTGREEN,     //10
    LIGHTCYAN,      //11
    LIGHTRED,       //12
    LIGHTMAGENTA,   //13
    YELLOW,         //14
    WHITE           //15
};
//COR FUNDO
enum{
    _BLACK=0,          //0
    _BLUE=16,           //1
    _GREEN=32,          //2
    _CYAN=46,           //3
    _RED=64,            //4
    _MAGENTA=80,        //5
    _BROWN=96,          //6
    _LIGHTGRAY=112,      //7
    _DARKGRAY=128,       //8
    _LIGHTBLUE=144,      //9
    _LIGHTGREEN=160,     //10
    _LIGHTCYAN=176,      //11
    _LIGHTRED=192,       //12
    _LIGHTMAGENTA=208,   //13
    _YELLOW=224,         //14
    _WHITE=240           //15
};

//função para mudar a cor do texto

void cortexto(int letras, int fundo){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),letras+fundo);
}

//função para criar uma caixa ao redor do menu

void box(int lin1,int col1, int lin2,int col2){

    setlocale(LC_ALL,"C");
    int i,j;

    for(i=col1;i<=col2;i++){ //fazendo as linhas
        gotoxy(lin1,i);
        printf("%c",196);
        gotoxy(lin2,i);
        printf("%c",196);
        }

    for(i=lin1;i<=lin2;i++){ //fazendo as linhas
        gotoxy(i,col1);
        printf("%c",179);
        gotoxy(i,col2);
        printf("%c",179);
        }

    for(i=lin1+1;i<lin2;i++){ //preenchendo
        for(j=col1+1;j<col2;j++){
            gotoxy(i,j);printf(" ");
        }
    }
    //colocando os cantos;
    gotoxy(lin1,col1);
    printf("%c",218);
    gotoxy(lin1,col2);
    printf("%c",191);
    gotoxy(lin2,col1);
    printf("%c",192);
    gotoxy(lin2,col2);
    printf("%c",217);
    setlocale(LC_ALL,"");
}

//função para exibir o menu

int MENUPRINCIPAL(int lin1,int col1,int qtd,char lista[6][100]){
    int opc = 1, lin2,col2, linha,i, tamMAXitem,tecla;

    //nessa parte é verificado qual das frases é maior
    tamMAXitem = strlen(lista[0]);

    for(i=1;i<qtd;i++){
        if(strlen(lista[i]) > tamMAXitem){
            tamMAXitem = strlen(lista[i]);
        }
    }
    lin2 = lin1+(qtd*2+2);
    col2 = col1 + tamMAXitem+4;

    cortexto(WHITE,_BLUE);
    setlocale(  LC_ALL,"C");
    box(lin1,col1,lin2,col2);
    setlocale(LC_ALL,"");

    while(1){

        linha = lin1 + 2;

        for(i=0;i<qtd;i++){
            if(i+1 == opc){
                cortexto(BLACK,_LIGHTGREEN); //se a opção for igual ao i a cor do texto fica diferente
            }
            else{
                cortexto(WHITE,_BLUE);
            }
        gotoxy(linha,col1+2);
        printf("%s",lista[i]);
        linha +=2;
        }
        //vendo as teclas
        gotoxy(1,1);
        tecla = getch();
        gotoxy(30,1);
        //printf("Tecla: %d",tecla);

        //teclas


        if(tecla ==27){ //ESC
            opc=0;
            break;
        }
        if(tecla == 13){ //ENTER
            break;
        }

        if(tecla==72){ //setinha pra baixo
            if(opc>1)
                opc--;
        }
        if(tecla==80){ //setinha pra cima
            if(opc<qtd)
                opc++;
        }
    }
    return opc;
}

int liat; // essa variável vai guardar a linha atual do programa

//criação do novos tipo

struct registro_livro{

    int codigo;
    bool doado;
    char nomeobra[30];
    char nomeautor[30];
    char editora[30];
    int numpag;
};
typedef struct registro_livro registro_livro;

//declarando as variaveis globais

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
int i;

int tamexa = 10 ,tamhum = 10,tambio = 10;

//essa função varre o vetor inteiro e verifica se o livro existe, sendo possível pesquisar usando o código ou o nome

bool achou(registro_livro teste[],int tipo_comp,int codigo,char nome[30],int tama){
    switch(tipo_comp){
        // caso a comparação seja com o código:
        case 1:{
            for(i=0;i<tama;i++){
                if(codigo == teste[i].codigo){
                    gotoxy(liat,5);printf("ENCONTRADO!!");liat+=2;
                    return true;
                    break;
                }
}
       gotoxy(liat,5);printf("NÃO FOI ENCONTRADO CADASTRO!");
        return false;
        break;
}
        //caso a comparação seja com uma string
        case 2:{
            for(i=0;i<tama;i++){
                if(strcmp(nome,teste[i].nomeobra) == 0){
                    gotoxy(liat,5);printf("LIVRO ENCONTRADO!!");liat+=2;
                    return true;
                    break;
        }
}
        gotoxy(liat,5);printf("NÃO FOI ENCONTRADO CADASTRO!");liat+=2;
        return false;
        break;
        }
    }
}

//essa função vai ser usada em todas as impressões

void imprimirgeral(int i,registro_livro teste[]){


    gotoxy(liat,5);printf("CÓDIGO: %d",teste[i].codigo);liat +=1;
    gotoxy(liat,5);liat +=1;
    if(teste[i].doado){
            printf("DOADO: SIM");
    }
    else{
            printf("DOADO: NÃO");
    }

    gotoxy(liat,5);printf("NOME DA OBRA: %s",teste[i].nomeobra);liat +=1;
    gotoxy(liat,5);printf("NOME DO AUTOR: %s",teste[i].nomeautor);liat +=1;
    gotoxy(liat,5);printf("EDITORA: %s",teste[i].editora);liat +=1;
    gotoxy(liat,5);printf("NUM DE PAGS: %d",teste[i].numpag);liat +=1;
    gotoxy(liat,5);printf("-------------------------------------");liat +=1;
}

//função para limpar o buffer do teclado ao usar muitas entradas de dados

void limpaotecladosenaodaruim(){
    int c=0;
    while(c = getchar() != '\n' && c != EOF){}
}

//função para listar todos os doados, ela verifica se o campo doado é .V. e se for imprime o registro

void listadoados(registro_livro exemplar[],int tama){
    for(i=0;i<tama;i++){
        if(exemplar[i].doado == true){
            imprimirgeral(i,exemplar);
            }
    }
}

//função para imprimir os livros com uma condição em específico

void listanaodoadoseprecofaixa(registro_livro exemplar[],int tama){
    for(i=0;i<tama;i++){
        if(!exemplar[i].doado && exemplar[i].numpag >= 100 && exemplar[i].numpag <= 300){
            imprimirgeral(i,exemplar);
            }
    }
}



void alterarcadastro(registro_livro exemplar[],int codigo,int tama){
    //verificar a existencia do exemplar
    int existe = 0,indice;
    int simounao;

    if(achou(exemplar,1,codigo,"0",tama)){
            existe = 1;
            indice = i;
        }


    if(existe){
            gotoxy(liat,5);printf("ANTES DAS ALTERAÇÕES:");liat+=2;

            imprimirgeral(indice,exemplar);
            limpaotecladosenaodaruim();

            gotoxy(liat,5);printf("Digite o novo nome da obra:");liat+=1;
            gotoxy(liat,5);scanf("%[^\n]s",&exemplar[indice].nomeobra);liat+=1;
            limpaotecladosenaodaruim();

            gotoxy(liat,5);printf("Digite o novo nome do autor:");liat+=1;
            gotoxy(liat,5);scanf("%[^\n]s",&exemplar[indice].nomeautor);liat+=1;
            limpaotecladosenaodaruim();

            gotoxy(liat,5);printf("Digite o novo nome da Editora:");liat+=1;
            gotoxy(liat,5);scanf("%[^\n]s",&exemplar[indice].editora);liat+=1;
            limpaotecladosenaodaruim();

            gotoxy(liat,5);printf("Esse livro foi: 1 - doado, 2 - comprado:");liat+=1;
            gotoxy(liat,5);scanf("%d",&simounao);liat+=1;
            limpaotecladosenaodaruim();

            if(simounao == 1){
                exemplar[indice].doado = true;
            }
            else{
                exemplar[indice].doado = false;
            }

            gotoxy(liat,5);printf("Digite o novo número de páginas:");liat+=1;
            gotoxy(liat,5);scanf("%d",&exemplar[indice].numpag);liat+=2;
            limpaotecladosenaodaruim();

            gotoxy(liat,5);printf("DEPOIS DAS ALTERAÇÕES:");liat+=2;
            imprimirgeral(indice,exemplar);
            liat+=2;
}
}

//função para excluir o livro, todos os elementos são realocados de lugar

void excluilivro(registro_livro exemplar[],int codigo,int tama){
    int existe = 0;
    int contadorvetornovo = 0;

    if(achou(exemplar,1,codigo,"0",tama)){
            existe = 1;

        }

    if(existe){
            for(i=0;i<tama;i++){
                if(codigo != exemplar[i].codigo){
                        exemplar[contadorvetornovo].codigo = exemplar[i].codigo;
                        exemplar[contadorvetornovo].doado = exemplar[i].doado;
                        strcpy(exemplar[contadorvetornovo].editora, exemplar[i].editora);
                        strcpy(exemplar[contadorvetornovo].nomeautor , exemplar[i].nomeautor);
                        strcpy(exemplar[contadorvetornovo].nomeobra , exemplar[i].nomeobra);
                        exemplar[contadorvetornovo].numpag = exemplar[i].numpag;
                        contadorvetornovo += 1;
                }
            }

        }
    else{
        gotoxy(liat,5);printf("LIVRO NÃO CONSTA NO SISTEMA!!");liat+2;
    }

}

//função para fazer a pesquisa

void pesquisausandocodigo(){
    int achei = 0;
    int codigo,area;

    do{
    gotoxy(liat,5);printf("Digite a código para a pesquisa:(-1 para sair)");liat+=1;
    gotoxy(liat,5);scanf("%d",&codigo);liat+=2;
    limpaotecladosenaodaruim();
    if(codigo == -1){
        break;
    }
    gotoxy(liat,5);printf("Digite a área desejada:MENU\n\t1-EXATAS\n\t2-HUMANAS\n\t3-BIOMÉDICAS");liat+=4;
    gotoxy(liat,5);scanf("%d",&area);liat+=2;
    limpaotecladosenaodaruim();

    switch(area){
        case 1:{
          if(achou(exatas,1,codigo,"0",tamexa)){
                imprimirgeral(i,exatas);
                achei = 1;
          }
                break;
        }
        case 2:{
            if(achou(humanas,1,codigo,"0",tamhum)){
                    imprimirgeral(i,humanas);
                    achei = 1;
                        }
                    break;
                }
        case 3:{
            if(achou(biomedicas,1,codigo,"0",tambio)){
                    imprimirgeral(i,biomedicas);
                    achei = 1;
            }
                    break;
                }
        default:{
            gotoxy(liat+2,5);printf("Código inválido!");
            break;
        }
    }
    liat+=4;

}while(codigo!=-1);
}

//função para fazer a pesquisa

void pesquisausandonome(){

    char nomepesquisa[30];
    int areadesejada;
    int encontrei = 0;

    do{

    gotoxy(liat,5);printf("Digite o nome do livro para a pesquisa:(-1 para sair)");liat+=1;
    gotoxy(liat,5);scanf("%[^\n]s",&nomepesquisa);liat+=1;
    limpaotecladosenaodaruim();

    if(strcmp(nomepesquisa,"-1") == 0){
        break;
    }
    gotoxy(liat,5);printf("Digite a área desejada:MENU\n\t1-EXATAS\n\t2-HUMANAS\n\t3-BIOMÉDICAS");liat+=4;
    gotoxy(liat,5);scanf("%d",&areadesejada);liat+=2;
    limpaotecladosenaodaruim();



    switch(areadesejada){
        case 1:{
            if(achou(exatas,2,0,nomepesquisa,tamexa)){
                imprimirgeral(i,exatas);
                encontrei = 1;
            }
                break;

        }
        case 2:{
            if(achou(humanas,2,0,nomepesquisa,tamhum)){
                    imprimirgeral(i,humanas);
                    encontrei = 1;
            }
            break;
        }
        case 3:{
            if(achou(biomedicas,2,0,nomepesquisa,tambio)){
                    imprimirgeral(i,biomedicas);
                    encontrei = 1;
            }
            break;

        }
        default:{
            gotoxy(liat+2,5);printf("Código inválido!\n\n");
            break;
        }
    liat+=4;
    }
    }while(nomepesquisa!="-1");
}

//função para listar os livros

void listatodosdoados(){
    liat+=1;
    cortexto(LIGHTGREEN,_BLACK);gotoxy(liat,5); printf("LISTA DOADOS EXATAS:");liat+=2;cortexto(WHITE,_BLACK);
    listadoados(exatas,tamexa);
    cortexto(LIGHTGREEN,_BLACK);gotoxy(liat,5); printf("LISTA DOADOS HUMANAS:");liat+=2;cortexto(WHITE,_BLACK);
    listadoados(humanas,tamhum);
    liat+=1;
    cortexto(LIGHTGREEN,_BLACK);gotoxy(liat,5); printf("LISTA DOADOS BIOMÉDICAS:");liat+=2;cortexto(WHITE,_BLACK);
    listadoados(biomedicas,tambio);liat+=2;
    liat+=1;

}

//função para listar os livros

void listatodosfaixa(){
    liat+=1;
    cortexto(LIGHTCYAN,_BLACK);gotoxy(liat,5); printf("LISTA NÃO DOADOS EXATAS COM PREÇO ENTRE 100 E 300:");cortexto(WHITE,_BLACK);liat+=2;
    listanaodoadoseprecofaixa(exatas,tamexa);
    liat+=1;
    cortexto(LIGHTCYAN,_BLACK);gotoxy(liat,5); printf("LISTA NÃO DOADOS HUMANAS COM PREÇO ENTRE 100 E 300:");cortexto(WHITE,_BLACK);liat+=2;
    listanaodoadoseprecofaixa(humanas,tamhum);
    liat+=1;
    cortexto(LIGHTCYAN,_BLACK);gotoxy(liat,5); printf("LISTA NÃO DOADOS BIOMÉDICAS COM PREÇO ENTRE 100 E 300:");cortexto(WHITE,_BLACK);liat+=2;
    listanaodoadoseprecofaixa(biomedicas,tambio);
    liat+=1;
}

//função para alterar os cadastros

void alterarcadastrototal(){

    int chave,areadesejada;

    gotoxy(liat,5);printf("Digite o código para alterar o registro:");liat+=1;
    gotoxy(liat,5);scanf("%d",&chave);liat+=1;
    gotoxy(liat,5);printf("Informe a área desse livro: 1- exatas, 2 - humanas, 3 - biomedicas");liat+=1;
    gotoxy(liat,5);scanf("%d",&areadesejada);liat+=2;

    switch(areadesejada){
        case 1:{
            alterarcadastro(exatas,chave,tamexa);
            break;
        }
        case 2:{
            alterarcadastro(humanas,chave,tamhum);
            break;
        }
        case 3:{
            alterarcadastro(biomedicas,chave,tambio);
            break;
        }
    }
}

//função para excluir os livros

void excluiregistro(){
    int chave,areadesejada;

    gotoxy(liat,5);printf("Digite o código para excluir o registro:");liat+=1;
    gotoxy(liat,5);scanf("%d",&chave);liat+=2;
    gotoxy(liat,5);printf("Informe a área desse livro: 1- exatas, 2 - humanas, 3 - biomedicas");liat+=1;
    gotoxy(liat,5);scanf("%d",&areadesejada);liat+=2;

    switch(areadesejada){
        case 1:{
            if(achou(exatas,1,chave,"0",tamexa)){
                excluilivro(exatas,chave,tamexa);
                tamexa -= 1;
                gotoxy(liat,5);printf("DEPOIS DAS ALTERAÇÕES:");liat+=2;
                for(i=0;i<tamexa;i++){
                    imprimirgeral(i,exatas);
                    }
                }
            break;
        }
        case 2:{
            if(achou(humanas,1,chave,"0",tamhum)){
                excluilivro(humanas,chave,tamhum);
                tamhum -=1;
                gotoxy(liat,5);printf("DEPOIS DAS ALTERAÇÕES:");liat+=2;
                for(i=0;i<tamhum;i++){

                    imprimirgeral(i,humanas);
                }
            }
            break;
        }
        case 3:{
            if(achou(biomedicas,1,chave,"0",tambio)){
                excluilivro(biomedicas,chave,tambio);
                tambio -=1;
                gotoxy(liat,5);printf("DEPOIS DAS ALTERAÇÕES:");liat+=2;
                for(i=0;i<tambio;i++){
                    imprimirgeral(i,biomedicas);
                }
                }
            else{
                gotoxy(liat,5);printf("Nao foi possivel realizar as alterações!");liat+=2;
            }
            break;
        }
    }



}

int main(){

    int opc;
    char lista[6][100] = {"PESQUISA USANDO O CÓDIGO","PESQUISA USANDO O NOME","LISTAR TODOS OS LIVROS DOADOS","LISTAR TODOS OS LIVROS COMPRADOS COM PGS. ENTRE 100 E 300","ALTERAR CADASTRO","EXCLUIR LIVRO"};
    setlocale(LC_ALL,"");

    while(1){
        system("cls");
        opc = MENUPRINCIPAL(2,5,6,lista);
        if(opc ==0){
            break;
        }

    cortexto(WHITE,_BLACK);
    gotoxy(24,1);
    printf(" ");

    int MENU,repeticao = 1;
    liat = 20;

        switch(opc){
            case 1:{
                pesquisausandocodigo();
                break;
        }
            case 2:{
                pesquisausandonome();
                break;
        }
            case 3:{
                listatodosdoados();
                break;
        }
            case 4:{
                listatodosfaixa();
                break;
        }
            case 5:{
                alterarcadastrototal();
                break;
        }
            case 6:{
                excluiregistro();
                break;
        }
            default:{
                printf("OPÇÃO INVÁLIDA!!\n\n");
        }


    }
    liat+=6;
    int x = liat-1;

    cortexto(LIGHTBLUE,_BLUE); // aqui é impresso a caixa azul do final
    box(x,5,x+2,60);
    cortexto(WHITE,_BLUE);gotoxy(liat,7);printf("DIGITE QUALQUER TECLA PRA CONTINUAR, ESC PARA SAIR");cortexto(WHITE,_BLACK);
    getch();

}
    return 0;
}

