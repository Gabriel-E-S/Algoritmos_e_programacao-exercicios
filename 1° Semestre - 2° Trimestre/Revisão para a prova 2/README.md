# Revisão prova 2 -- PSEUDOCÓDIGOS

Nessa revisão falarei um pouco sobre:

+ Funções
+ Vetores
+ Matrizes
+ Ponteiros

## Funções e procedimentos

Em pseudocódigo temos dois tipos de funções

1. Procedimentos - servem para realizar ações que não exigem nenhum retorno, exemplo: imprimir algo na tela, sortear algum numero, etc.

2. Funções - são trechos de código que retorna algum valor, sendo ele de qualquer tipo primitivo ou criado pelo programador.

Exemplos

1. Procedimento que imprime um número na tela se ele é par

    PROCEDIMENTO MOSTRAR(INTEIRO: n1)
    INICIO 
       VAR  INTEIRO: i;
        PARA i DE 1 ATÉ n1 FAÇA
            SE i%2 == 0 
                ENTÃO ESCREVA i;
        FIM_PARA;
    FIM.

Sintaxe de um procedimento:

    **PROCEDIMENTO** nome (**TIPO** variável,**TIPO** variável2...)
    ÍNICIO

    ...

    FIM

2. Função que soma os valores de 1 até um N informado pelo usuário

    FUNÇÃO INTEIRO somat(INTEIRO: N)
    INICIO
        VAR INTEIRO: i,soma=0;

        PARA i DE 1 ATÉ N FAÇA
            soma = soma + i;
        FIM_PARA;

        RETORNE soma;
    FIM.

Sintaxe de uma função:

    **FUNÇÃO TIPO_DE_RETORNO** nome (**TIPO** variável,**TIPO** variável2...)
    ÍNICIO

    ...

        RETORNE <EXPRESSÃO OU VARIÁVEL>
    FIM

**IMPORTANTE:** Funções tanto em pseudocódigo ou em linguagem C só podem retornar 1 valor por chamada, se quisermos retornar mais do que isso temos que usar ponteiros, assim como será explicado mais para frente.

## Passagem de parâmetros

+ Por valor --> Passamos uma cópia do valor da variável para a função ou procedimento, as operações são realizadas mas o valor inicial **NÃO** é alterado.

+ Por referência --> Passamos o endereço de memória de alguma variável para a função e as operações **podem mudar** o valor inicial, isso é util para podermos retornar mais de um valor quando necessário.

A diferença entre as duas está no cabeçalho da função:

    FUNÇÃO TIPO_DE_RETORNO nome (TIPO variável,TIPO variável2...) 

    Assim passamos um argumento por valor.

    FUNÇÃO TIPO_DE_RETORNO nome (VAR TIPO variável,VAR TIPO variável2...) 

    Assim passamos um argumento por referência, a diferença está no prefixo VAR.


## Vetores

A criação de vetores se dá da seguinte forma

    VAR <TIPO_DE_DADO> nomeDaVariavel [tamanho-do-vetor] ;

As operações com vetores são similares a linguagem C, no entanto temos 2 coisas importantes

1. vetores ou matrizes **SEMPRE** são passados por referência.

2. O índice do vetor começa em **1** e não em 0 como em C, muita atenção nisso.

Exemplo de código usando vetores que lê os valores 

    ...
    VAR INTEIRO: i, vet[5];

    PARA i de 1 ATÉ 5 FAÇA
        ESCREVA "V[",i,"] =";
        LEIA vet[i] ;
    FIM_PARA;
    ...

## Matrizes

A criação de matrizes se dá da seguinte forma

    VAR <TIPO_DE_DADO> nomeDaVariavel [tamanho-dim1][tamanho-dim2]...[tamanho-dimN];

Exemplo de código usando matrizes que lê os valores 

    ...
    VAR INTEIRO: i,j, vet[5][5];

    PARA i de 1 ATÉ 5 FAÇA
        PARA j de 1 ATÉ 5 FAÇA
            ESCREVA "V[",i,"] =";
            LEIA vet[i] ;
        FIM_PARA;
    FIM_PARA;
    ...

Diagonais Principais e segundárias em matrizes quadradas

Exemplo de matriz quadrada 

            1 2 3

    1     | 1 2 3 |
    2     | 4 5 6 |
    3     | 7 8 9 |

        PSEUDOCÓDIGO

            0 1 2

    0     | 1 2 3 |
    1     | 4 5 6 |
    2     | 7 8 9 |

        LINGUAGEM C

A diagonal principal é aquela que possui seus indices com valores iguais, por exemplo m[1][1],m[2][2]...m[n][n].

Nesse exemplo seriam os valores **1**, **5** e **9**

A diagonal secundária é aquela que é como se fosse oposta a principal, por exemplo m[1][n],m[2][n-1]...m[i][n-i].

Nesse exemplo seriam os valores **3** **5** e **7**

Um algoritmo que acessa as posições da diagonal principal de uma matriz usando procedimentos e imprime na tela:

### Versão em Pseudocódigo

    PROCEDIMENTO IMPRIME_PRINCIPAL(VAR INTEIRO: mat[][],INTEIRO: dim)

    INÍCIO

        VAR INTEIRO: i ;

        PARA i de 1 ATÉ dim FAÇA
            ESCREVA mat[i][i] ;
        FIM_PARA ;

    FIM.

Agora os da diagonal secundária

    PROCEDIMENTO IMPRIME_SECUNDÁRIA(VAR INTEIRO: mat[][],INTEIRO: dim)

    INÍCIO
        VAR INTEIRO: i ;

        PARA i de 1 ATÉ dim FAÇA
            ESCREVA mat[i][dim+1-i] ;
        FIM_PARA ;

    FIM.

### Versão em C

Diagonal principal

```c
    void imprime_principal(int m[][3],int dim) 
    {
        int i;

        for(i = 0 ;i < dim; i++){
                printf("%d ",m[i][i])
            }
        
    }
```
Diagonal secundária

```c
    void imprime_secundaria(int m[][3],int dim)
    {
        int i;

        for(i = 0 ;i < dim; i++){
                printf("%d ",m[i][dim-1-i]);
            }
        
    }
```


## Ponteiros

O similar a ponteiro em Pseudocódigo é quando usamos o comando **VAR** na chamada de funções.

Quando fazemos isso podemos alterar o valor de uma variável de forma indireta usando outra variável.

não há correspondentes a ponteiro fora disso.

Exemplo de função que faz uma potência de um número X elevado a n.


    INICIO

        FUNÇÃO REAL: potencia(REAL: X1,INTEIRO: n1)
        INICIO
            VAR INTEIRO:i;
                REAL: res = 1;
            
            // aqui foi feito uma funcao para potencia considerando as 3 possibilidades
            
            SE n1>0
                ENTÃO PARA i DE 1 ATÉ n1 FAÇA
                            res = res * X1;
                    FIM_PARA;
                
                SENÃO SE n1 < 0 
                            ENTÃO PARA i DE 1 ATÉ -n1 FAÇA
                                        res = res/X1;
                                FIM_PARA;
            
            RETORNE res;
        FIM.

        ALGORITMO PRINCIPAL
        INICIO

            VAR INTEIRO: n;
                REAL: X;

            ESCREVA "Digite o valor real para X:";
            LEIA X;

            ESCREVA "Digite o valor inteiro para N:";
            LEIA n;

            ESCREVA "o resultado é:",potencia(X,n);
        FIM.
    FIM.

Esse mesmo exercício em linguagem C

```c

#include <stdio.h>
#include <locale.h>
#include <math.h>

//aqui foi feito uma funcao para potencia considerando as 3 possibilidades

float potencia(float X1, int n1) {
    int i;
    float res = 1;
    if (n1 > 0) {
        for (i = 0; i < n1; i++) {
            res = res * X1;
        }
    } else if (n1 < 0) {
        for (i = 0; i < -n1; i++) {
            res = res / X1;
        }
    }
    return res;
}

int main() {
    int n;
    float X;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite o valor real para X:\n");
    scanf("%f", &X);

    printf("Digite o valor inteiro para N:\n");
    scanf("%d", &n);

    printf("O resultado e: %.2f", potencia(X, n));

    return 0;
}

```



