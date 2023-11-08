#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#define tam 3

struct reg_filial{
    int codigo;
    char descricao[30];
    char modelo[20];
    char marca[20];
    int inicio,fim;
    float preco;
    int qtd;
};

typedef struct reg_filial reg_filial;

struct reg_matriz{
    int codigo;
    int qtd_vendida;
    float valor_total;
};

int qtdmatriz = 0;

typedef struct reg_matriz reg_matriz;

void criandofiliais(){


      reg_filial f1[tam] ={
            {1,"Motor","Kombi","Volks",1900,2005,100,10},
            {2,"suco de laranja","Celta","Chevrolet",2000,2010,100,10},
            {3,"Suco de maracuja","Civic","Honda",1999,2012,150,10}
};

    reg_filial f2[tam] = {
        {1,"Motor","Kombi","Volks",1900,2005,100,10},
        {4,"Caixa de câmbio","Lancer EVO","Mitsubishi",1980,2023,100,100},
        {5,"Espelho dianteiro","Uno","Fiat",1999,2020,100,10}
};

    FILE *filial1 = fopen("Dados filial 1.bin","wb");
    FILE *filial2 = fopen("Dados filial 2.bin","wb");

    if(filial1 != NULL && filial2 != NULL){
        fwrite(f1,sizeof(reg_filial),tam,filial1);
        fwrite(f2,sizeof(reg_filial),tam,filial2);

        fclose(filial1);
        fclose(filial2);
        printf("gravação feita com sucesso!\n\n");
    }else{
        printf("Erro ao criar\n\n");
    }

}


void criandovetmatriz(){

    reg_filial copia;
    reg_matriz copiam;


    FILE *filial1 = fopen("Dados filial 1.bin","rb");
    FILE *matriz = fopen("Dados da matriz.bin","wb");

    if(filial1 != NULL && matriz != NULL){

        while(fread(&copia,sizeof(reg_filial),1,filial1) == 1){

            copiam.codigo = copia.codigo;
            copiam.qtd_vendida = copia.qtd;
            copiam.valor_total = copia.preco * copia.qtd;
            qtdmatriz += 1;

            fwrite(&copiam,sizeof(reg_matriz),1,matriz);
        }
        fclose(filial1);
        fclose(matriz);
}
    else{
        printf("Erro ao criar arquivo!\n\n");
    }
}

   void verificar_existencia() {
    FILE *filial2 = fopen("Dados filial 2.bin", "rb");
    FILE *matriz = fopen("Dados da matriz.bin", "r+b");

    if (filial2 != NULL && matriz != NULL) {
        reg_filial copia;

        while (fread(&copia, sizeof(reg_filial), 1, filial2) == 1) {
            bool existe = false;
            reg_matriz copiam;

            // Procura e atualiza os registros no arquivo

            while (fread(&copiam, sizeof(reg_matriz), 1, matriz) == 1) {
                if (copia.codigo == copiam.codigo) {
                    copiam.qtd_vendida += copia.qtd;
                    copiam.valor_total += copia.qtd * copia.preco;
                    existe = true;
                    fseek(matriz, -sizeof(reg_matriz), SEEK_CUR);
                    fwrite(&copiam, sizeof(reg_matriz), 1, matriz);
                    break;
                }
            }

            // Se não encontrou o código, adiciona um novo registro no arquivo
            if (!existe) {
                fseek(matriz, 0, SEEK_END);
                copiam.codigo = copia.codigo;
                copiam.qtd_vendida = copia.qtd;
                copiam.valor_total = copia.qtd * copia.preco;
                fwrite(&copiam, sizeof(reg_matriz), 1, matriz);
            }

            rewind(matriz); // Retorna o arquivo pro início
        }

        fclose(filial2);
        fclose(matriz);
    }
}


void imprimirfiliais(int opc){

    reg_filial p;


    if(opc == 1){

        FILE *filial1 = fopen("Dados filial 1.bin","rb");

        if(filial1 != NULL){
            printf("\n\n***REGISTROS FILIAL 1***\n\n");

            while(fread(&p,sizeof(reg_filial),1,filial1) == 1){
                    printf( "Descrição: %s\n",p.descricao);
                    printf( "Código: %d\n",p.codigo);
                    printf( "Modelo: %s\n",p.modelo);
                    printf( "Marca: %s\n",p.marca);
                    printf( "Ano início: %d\tAno final: %d\n",p.inicio,p.fim);
                    printf( "Preço: %.2f\n",p.preco);
                    printf( "Quantidade: %d\n\n",p.qtd);
            }
            fclose(filial1);
    }else{
        printf("Erro!\n");
    }
    }

    if(opc == 2){
        FILE *filial2 = fopen("Dados filial 2.bin","rb");

        if(filial2 != NULL){
        printf("\n\n***REGISTROS FILIAL 2***\n\n");

        while(fread(&p,sizeof(reg_filial),1,filial2) == 1){
                printf( "Descrição: %s\n",p.descricao);
                printf( "Código: %d\n",p.codigo);
                printf( "Modelo: %s\n",p.modelo);
                printf( "Marca: %s\n",p.marca);
                printf( "Ano início: %d\t",p.inicio,"Ano final: %d\n",p.fim);
                printf( "Preço: %.2f\n",p.preco);
                printf( "Quantidade: %d\n\n",p.qtd);
        }
        fclose(filial2);
    }else{
        printf("Erro!\n");
        }
    }

}

void imprimirmatriz(){

    reg_matriz copia;

    FILE *matriz = fopen("Dados da matriz.bin","rb");

    if(matriz != NULL){

    printf("\n\n***DADOS DA MATRIZ\n\n");
    printf("CÓDIGO\tQUANTIDADE VENDIDA\tVALOR TOTAL\n\n");

    while(fread(&copia,sizeof(reg_matriz),1,matriz) == 1 ){

            printf("  %d\t\t%d\t\t  %.2f\n",copia.codigo,copia.qtd_vendida,copia.valor_total);

    }

    fclose(matriz);

}else{
    printf("Erroo!\n");
}
}

int maiorvenda(){

    int maior,ondemaior = 1;
    reg_matriz copia;

        FILE *matriz = fopen("Dados da matriz.bin","rb");

        if(matriz != NULL){

        fread(&copia,sizeof(reg_matriz),1,matriz);

        maior = copia.qtd_vendida;

        while(fread(&copia,sizeof(reg_matriz),1,matriz)==1){
            if(copia.qtd_vendida > maior){
                maior = copia.qtd_vendida;
                ondemaior = copia.codigo;
            }
        }

        printf("\n\nA maior venda foi da peça com código: %d\n\n",ondemaior);

        return ondemaior;
        }
        else{
            printf("Erro !");
        }

        fclose(matriz);
}

void acharpecamaisvendida(int codigo){

    bool achou = false;
    reg_filial copia;

    FILE *filial1 = fopen("Dados filial 1.bin","rb");
    FILE *filial2 = fopen("Dados filial 2.bin","rb");

    if(filial1 != NULL && filial2 != NULL){

        while(fread(&copia,sizeof(reg_filial),1,filial1) == 1){
                if(codigo == copia.codigo){
                    printf("peca mais vendida : %s\n",copia.descricao);
                    printf("modelo de carro: %s\n",copia.modelo);
                    achou = true;
                }
        }
        if(!achou){

             while(fread(&copia,sizeof(reg_filial),1,filial2) == 1){
                if(codigo == copia.codigo){
                    printf("peca mais vendida : %s\n",copia.descricao);
                    printf("modelo de carro: %s\n",copia.modelo);
                    achou = true;
                }
        }

        }
        fclose(filial1);
        fclose(filial2);


    }
    else{
        printf("Erro!\n");
    }



}





int main(){
    int y;
    setlocale(LC_ALL,"");
    criandofiliais();
    criandovetmatriz();
    verificar_existencia();
    imprimirfiliais(1);
    imprimirfiliais(2);

    imprimirmatriz();

    y = maiorvenda();
    acharpecamaisvendida(y);



return 0;
}



