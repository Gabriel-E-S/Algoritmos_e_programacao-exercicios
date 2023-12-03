#include <stdio.h> // Biblieoteca de funções básicas em C.
#include <stdlib.h> // Para utilizar a função malloc(alocação dinâmica de memória).
#include <string.h> // Para usar a função strcmp que compara 2 strings.
#include <stdbool.h> // Para usar os tipos booleanos.



struct reg_alunos   //registro de exemplo
{
    int idade;
    int ra;
    char nome[20];
};

typedef struct reg_alunos reg_alunos; // usamos o typedef para eliminar a necessidade de escrever
// struct reg_alunos <nome_variavel> , essa função dá um "apelido" para a struct.

void cria_arquivo()
{

    int n, i,opc;

    printf("Digite a quantidade de alunos:\n");
    scanf("%d", &n);

    reg_alunos *alunos = malloc(sizeof(reg_alunos) * n); // a função malloc precisa de número de bytes que você deseja reservar,
    // como não sabemos o tamanho de reg_alunos podemos usar a função sizeof()

    if (alunos)   // se a alocação for bem sucedida a variavel recebe um ponteiro para a região de memória que foi alocada, em caso de erro
    {
        // obtemos NULL.

        for (i = 0; i < n; i++)
        {

            printf("\nDigite o nome do aluno %d: \n", i + 1); //como estamos trabalhando com um vetor de struct temos que tomar cuidado com os índices
            scanf("%s", alunos[i].nome);                      // e acessarmos o campo desejado usando o '.' .

            printf("Digite a idade do aluno %d\n", i + 1);
            scanf("%d", &alunos[i].idade);

            printf("Digite o ra do aluno %d\n", i + 1);
            scanf("%d", &alunos[i].ra);
        }

        printf("****MEMORIA ALOCADA****\n\n");

        for (i = 0; i < n; i++)
        {
            printf("\nnome do aluno %d = %s\n", i + 1, alunos[i].nome);
            printf("idade do aluno %d = %d\n", i + 1, alunos[i].idade);
            printf("ra do aluno %d = %d\n", i + 1, alunos[i].ra);

        }

        printf("\n\nDeseja adicionar os registros no arquivo?(1- sim, 2- nao)\n");
        scanf("%d",&opc);

        if(opc == 1 )
        {

            FILE *file = fopen("arquivo registros.dat","ab");

            /* Para abrirmos um arquivo em C devemos usar a função fopen() que recebe dois parâmetros: o primeiro é o nome do
               arquivo junto ao formato dele, o segundo é o modo de abertura. Aqui estão alguns exemplos:

               wb = usado para escrever no formato binario, se o arquivo já existir ele é substituido por um novo
               rb = usado para ler no formato binario
               rb+ = usado para ler no formato binario, permitindo alterações no arquivo
               ab = usado para escrever no formato binario no FINAL do arquivo, se o arquivo já existir ele  recebe as informações no final dele

               A função retorna um ponteiro para o endereço de memória do arquivo, caso ela retorne NULL ocorreu algum erro no processo.
            */

            if(file)
            {

                for(i=0; i<n; i++)
                {
                    fwrite(&alunos[i],sizeof(reg_alunos),1,file);
                    // a função fwrite serve para conseguirmos escrever no arquivo.
                    // seus parâmetros são fwrite(endereço da variável, tamanho em bytes do tipo da variavel, num de bytes que serão gravados, ponteiro para o arquivo);
                }
                printf("Arquivos gravados com sucesso\n");
                fclose(file); // a função fclose(ponteirodoarquivo) fecha o arquivo evitando que o arquivo se corrompa.
                free(alunos); // a função free libera a memória que foi alocada dinamicamente.
            }

            else
            {
                printf("Erro ao criar arquivo\n");
            }
        }


    }
    else
    {
        printf("Erro ao alocar memoria\n");
    }
}

void lerarquivo()
{

    FILE *file = fopen("arquivo registros.dat","rb");
    reg_alunos copia;
    int i = 1;

    if(file)
    {

        printf("lendo do arquivo \n\n");

        // a função fread serve para conseguirmos ler do arquivo.
        // seus parâmetros são fwrite(endereço da variável, tamanho em bytes do tipo da variavel, num de bytes que serão lidos, ponteiro para o arquivo);

        while(fread(&copia,sizeof(reg_alunos),1,file))
        {

            printf("\nnome do aluno %d = %s\n", i, copia.nome);
            printf("idade do aluno %d = %d\n", i, copia.idade);
            printf("ra do aluno %d = %d\n", i, copia.ra);

            i+= 1;
        }

        fclose(file);
    }
    else
    {
        printf("Erro ao ler arquivo\n\n");
    }


}

bool acharpalavra(char palavra[])
{

    FILE *file = fopen("arquivo registros.dat","rb");
    reg_alunos copia;
    bool achou = false;

    if(file)
    {

        while(fread(&copia,sizeof(reg_alunos),1,file))
        {

            if(strcmp(copia.nome,palavra) == 0)  // a função strcmp serve para compararmos strings, podendo retornar 3 tipos de valores
            {
                // se as strings forem iguais ela retorna 0;
                // se a 1° string for maior ela retorna um valor > 0
                // se a 1° string for menor ela retorna um valor < 0
                achou = true;
            }
        }

        fclose(file);
    }
    else
    {
        printf("Erro ao abrir achar palavra!\n");
    }

    return achou;
}


void deletaregistro()
{

    /*
        Como foi dito nas aulas a exclusão de um registro em arquivos pode ser feita de 2 maneiras:

        1- Pode existir um campo no registro que pode indicar a exclusão ou não dele, dessa forma as outras funções
           devem levar em consideração se o registro está "excluído" ou não.

        2- Podemos comparar o arquivo inteiro com a chave que queremos excluir e gravar os registros que devem permanecer em um arquivo auxiliar.
           em seguida excluímos o arquivo original e renomeamos o arquivo auxiliar.

           Essa função trabalha dessa forma...
    */

    char chave[20];
    reg_alunos copia;
    bool achou = false;

    FILE *file = fopen("arquivo registros.dat","rb"); //abrirmos o arquivo principal para leitura

    if(file)
    {

        printf("\n\ndigite o nome para excluir:\n");
        scanf("%s",chave);

        if(acharpalavra(chave))
        {
            printf("registro encontrado!\n");

            FILE *aux = fopen("Arq aux.dat","wb"); //abrirmos o arquivo auxiliar para escrita.

            if(aux)
            {

                while(fread(&copia,sizeof(reg_alunos),1,file))
                {
                    if(strcmp(copia.nome,chave) != 0)
                    {
                        fwrite(&copia,sizeof(reg_alunos),1,aux); // se o nome for diferente do que queremos excluir escrevemos o registro no auxiliar.

                    }
                }


                fclose(file);
                fclose(aux);
            }
            else
            {
                printf("Erro o abrir arq!\n");
            }

            remove("arquivo registros.dat"); // a função remove apaga o arquivo antigo.

            if(rename("Arq aux.dat","arquivo registros.dat") != 0)  // a função rename muda o nome de um arquivo, tendo como parâmetros o nome do arquivo atual e o nome que queremos  colocar.
            {
                printf("Erro ao renomear\n");
            }



        }
        else
        {
            printf("Erro o abrir arq!\n");
        }

    }
}

void alterar_registro()
{

    char nome[20];
    reg_alunos copia;

    FILE *file = fopen("arquivo registros.dat","rb+");

    if(file)
    {
        printf("\n\nDigite o nome do registro para alterar:\n");
        scanf("%s",nome);

        if(acharpalavra(nome))
        {
            printf("Registro encontrado!\n");
            while(fread(&copia,sizeof(reg_alunos),1,file))
            {

                if(strcmp(copia.nome,nome) == 0)  //se o nome for igual
                {

                    fseek(file,-1*sizeof(reg_alunos),SEEK_CUR);
                    // a função fseek move o ponteiro e  seus parâmetros são fseek(ponteiroproarquivo,num de bytes para mover, posição desejada)
                    // se o segundo parâmetro for positivo ele avança o ponteiro, senão ele retrocede.
                    //o terceiro parâmetro oferece três opções;
                    // 1 - SEEK_SET -> a contagem começa no início do arquivo.
                    // 2 - SEEK_END -> a contagem começa no final do arquivo.
                    // 1 - SEEK_CUR -> a contagem começa na posição atual do arquivo.

                    printf("Digite o novo nome do aluno :\n");
                    scanf("%s", copia.nome);

                    printf("Digite a nova idade do aluno\n");
                    scanf("%d", &copia.idade);

                    printf("Digite o novo ra do aluno \n");
                    scanf("%d", &copia.ra);



                    fwrite(&copia,sizeof(reg_alunos),1,file);

                    printf("Registro alterado com sucesso\n");
                    break;
                }

            }

        }
        else
        {
            printf("Reg n encontrado\n");
        }
        fclose(file);

    }
    else
    {
        printf("Erro o abrir arq!\n");
    }



}

int main()
{

    int opc = 1;

    while(opc!= 5)
    {

        system("cls");
        printf("******* PROGRAMA ESCOLAR V 1.0 *******\n\n");
        printf("BEM VINDO, ESCOLHA UMA DAS OPCoES DO MENU PARA CONTINUAR\n\n");
        printf("MENU\n\n1-ADICIONAR PALAVRAS AO ARQUIVO\n2-LER ARQUIVO\n3-DELETAR REGISTRO\n4-ALTERAR REGISTRO\n5-SAIR\n");
        printf("OPCAO ---->  ");
        scanf("%d",&opc);


        switch(opc)
        {

        case 1:
        {
            cria_arquivo();
            break;
        }
        case 2:
        {
            lerarquivo();
            break;
        }
        case 3:
        {
            deletaregistro();
            break;
        }
        case 4:
        {
            alterar_registro();
            break;
        }
        case 5:
        {
            printf("voce escolheu sair!!\n\n");
            break;
        }
        default:
        {
            printf("opc invalida!\n");
        }
        }
        system("pause");
    }

    return 0;
}
