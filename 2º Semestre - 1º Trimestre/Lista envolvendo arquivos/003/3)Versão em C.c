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
            {3,"Suco de maracuja","Civic","Honda",1999,2012,150,115}
};

    reg_filial f2[tam] = {
        {1,"Motor","Kombi","Volks",1900,2005,100,10},
        {4,"Caixa de c�mbio","Lancer EVO","Mitsubishi",1980,2023,100,100},
        {5,"Espelho dianteiro","Uno","Fiat",1999,2020,100,10}
};

    FILE *filial1 = fopen("Dados filial 1.bin","wb");
    FILE *filial2 = fopen("Dados filial 2.bin","wb");

    if(filial1 != NULL && filial2 != NULL){
        fwrite(f1,sizeof(f1),tam,filial1);
        fwrite(f2,sizeof(f2),tam,filial2);

        fclose(filial1);
        fclose(filial2);
        printf("grava��o feita com sucesso!\n\n");
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

void verificar_existencia(){

    bool existe;
    reg_matriz copiam;
    reg_filial copia;

    FILE *filial2 = fopen("Dados filial 2.bin","rb");
    FILE *matriz = fopen("Dados da matriz.bin","ab");

    if(filial2 != NULL && matriz != NULL){

        while(!feof(filial2)){
            existe = false;

            fread(&copia,sizeof(reg_filial),1,filial2);
            rewind(matriz);

            while(fread(&copiam,sizeof(reg_matriz),1,matriz) == 1){
                    if(copia.codigo == copiam.codigo){
                        copiam.qtd_vendida = copiam.qtd_vendida + copia.qtd;
                        copiam.valor_total = copiam.valor_total + copia.qtd * copia.preco;
                        existe = true;
                        fwrite(&copiam,sizeof(reg_matriz),1,matriz);

                    }

            }

            if(!existe){
                fseek(matriz,qtdmatriz*sizeof(reg_matriz),SEEK_SET);
                copiam.codigo = copia.codigo;
                copiam.qtd_vendida = copia.qtd;
                copiam.valor_total = copia.preco * copia.qtd;
                fwrite(&copiam,sizeof(reg_matriz),1,matriz);
                qtdmatriz+=1;
            }
        }
        fclose(filial2);
        fclose(matriz);
}else{
    printf("Erro ao abrir novamente 2\n");
}
}

void imprimirfiliais(int opc){

    reg_filial p;


    if(opc == 1){

        FILE *filial1 = fopen("Dados filial 1.bin","rb");

        if(filial1 != NULL){
            printf("\n\n***REGISTROS FILIAL 1***\n\n");

            while(fread(&p,sizeof(reg_filial),1,filial1) == 1){
                    printf( "Descri��o: %s\n",p.descricao);
                    printf( "C�digo: %d\n",p.codigo);
                    printf( "Modelo: %s\n",p.modelo);
                    printf( "Marca: %s\n",p.marca);
                    printf( "Ano in�cio: %d\tAno final: %d\n",p.inicio,p.fim);
                    printf( "Pre�o: %.2f\n",p.preco);
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
                printf( "Descri��o: %s\n",p.descricao);
                printf( "C�digo: %d\n",p.codigo);
                printf( "Modelo: %s\n",p.modelo);
                printf( "Marca: %s\n",p.marca);
                printf( "Ano in�cio: %d\t",p.inicio,"Ano final: %d\n",p.fim);
                printf( "Pre�o: %.2f\n",p.preco);
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

    while(fread(&copia,sizeof(reg_matriz),1,matriz) == 1 ){

            printf("C�digo: %d\n",copia.codigo);
            printf("Quantidade vendida: %d",copia.qtd_vendida);
            printf("Valor total: %.2f",copia.valor_total);

    }

    fclose(matriz);

}else{
    printf("Erroo!\n");
}
}






int main(){

    setlocale(LC_ALL,"");
    criandofiliais();
    criandovetmatriz();
    verificar_existencia();
    imprimirfiliais(1);
    imprimirfiliais(2);

    imprimirmatriz();




return 0;
}



