// Prova 4 Algoritmos e programação , ano 2023.
// Alunos: Gabriel E.S e Victor Cerqueira.
// A prova consiste em receber um arquivo binário do professor e executar as
// operações solicitadas.

#include <locale.h> // Acentuação.
#include <stdio.h>  // Bibliotecas de entrada e saída.
#include <string.h> // Comparação de Strings.

// Estrutura dada pelo professor para ler o arquivo que ele passou.

typedef struct {
  int cod;
  char nome[40];
  char excluido; // O problema é que precisamos comparar um caracter como
                 // inteiro para o arquivo ler corretamente.
} arq;

// Procedimento que lista os registros que não estão excluidos.

void listaativos() {

  FILE *file =
      fopen("prova1.bin", "rb"); // Abrindo o arquivo "prova1.bin" para leitura.

  arq copia; // Variável do tipo arq que será usada para colocar os registros
             // lidos do arquivo.

  if (file) { // Se o arquivo abriu corretamente.

    while (fread(&copia, sizeof(arq), 1,
                 file)) { // Enquanto houverem registros no arquivo.

      if (copia.excluido ==
          0) { // Se o registro atual não está excluido então imprime na tela.
        printf("\ncodigo: %d\n", copia.cod);
        printf("nome: %s\n", copia.nome);
        printf("ativo: %d\n\n", copia.excluido);
      }
    }
    fclose(file); // Fechando o arquivo, lembre SEMPRE de fechar.
  } else {
    printf("Erro ao abrir arquivo!"); // Caso der erro na hora de abrir.
  }
}

// Essa função não pedia no enunciado da prova, mas como o arquivo estava com
// problemas foi preciso utilizá-la.

void listainativos() {

  FILE *file = fopen("prova1.bin", "rb");

  arq copia;

  if (file) {

    while (fread(&copia, sizeof(arq), 1, file)) {

      if (copia.excluido == 1) { // Mesma coisa da outra da função anterior.
        printf("\ncodigo: %d\n", copia.cod);
        printf("nome: %s\n", copia.nome);
        printf("ativo: %d\n\n", copia.excluido);
      }
    }
    fclose(file);
  } else {
    printf("Erro ao abrir arquivo!");
  }
}

// Insere um registro no arquivo.

void incluirregistro() {

  arq copia;

  FILE *file = fopen("prova1.bin", "ab");

  if (file) {
    copia.cod = 7;

    strcpy(copia.nome,
           "Pedro Salazar"); // Nessa parte só é preenchido o registro de cópia.

    copia.excluido = 0;

    fwrite(&copia, sizeof(arq), 1,
           file); // O que escreve de fato no arquivo é a função fwrite.
    printf("arquivo atualizado com sucesso!\n");

    fclose(file);
  }
}

// Procedimento para excluir do arquivo um registro, o que pode mais causar
// dúvida na hora de fazer na minha opinião.

void excluirregistro() {

  arq copia;      // Cópia para ler do arquivo.
  int codigo = 3; // Queríamos apagar o registro com código 3.

  FILE *file = fopen("prova1.bin",
                     "rb+"); // Abrindo o arquivo no modo de leitura e escrita.

  if (file) { // Se abrir corretamente o arquivo.

    while (fread(&copia, sizeof(arq), 1, file)) {

      if (copia.cod == codigo) { // Se o código for encontrado
        fseek(file, -1 * sizeof(arq),
              SEEK_CUR); // Temos que retroceder uma vez o ponteiro do arquivo,
                         // pois ao usar o fread ele é avançatualizado
                         // automaticamente.
        copia.excluido = 1; // Trocamos o registro para excluido na memória.
        fwrite(&copia, sizeof(arq), 1,
               file); // E escrevemos no arquivo novamente.
        printf("registro excluido com sucesso!\n");
        break;
      }
    }

    fclose(file); // Fechando o arquivo.

  } else {
    printf("Erro ao abrir arquivo!\n");
  }
}

// Fazendo o uso das funções de acordo com o enunciado da prova.

int main() {
  setlocale(LC_ALL, "");

  printf("listando ativos:\n");
  listaativos();

  printf("\n**Incluir Registro**\n\n");
  incluirregistro();

  printf("\n**Excluir Registro**\n\n");
  excluirregistro();

  printf("\n\nlistando ativos:\n");
  listaativos();
  /*
      Essa parte foi usada até acharmos o problema na hora de escrever na tela,
     que consistia em ter que ler do arquivo o exluido como char e compará-lo
     como inteiro. printf("listando excluidos:\n\n"); listainativos(); */
  return 0;

  // Em caso de qualquer dúvida ou sugestão estou a disposição :)
}
