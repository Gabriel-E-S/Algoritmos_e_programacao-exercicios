#include <stdio.h>
#include <windows.h>

#define SIZE 3

// Create new types

typedef struct {
    int cod;
    char description[20];
    char model[20];
    char brand[20];
    int start, end;
    int amount;
    float price;
} Branch;

typedef struct {
    int cod;
    int sold_amount;
    float amount;
} Matrix;

// Create global variables

int sizeMatrix = 0;
int sizeB1 = SIZE;
int sizeB2 = SIZE;
int i,j;

// Function

void printBranch(Branch b[], int num, int size) {
    printf("\n\tResults: Branch %d\n\n", num);

    for(i=0; i<size; i++) {
        printf("\tCODE: %d\n", b[i].cod);
        printf("\tDESCRIPTION: %s\n", b[i].description);
        printf("\tMODEL: %s\n", b[i].model);
        printf("\tBRAND: %s\n", b[i].brand);
        printf("\tSTART YEAR: %d\tEND YEAR: %d\n", b[i].start, b[i].end);
        printf("\tPRICE: %.2f\n", b[i].price);
        printf("\tAMOUNT: %d\n", b[i].amount);
        printf("\t----------------------------------\n");
    }

}

void printMatrix(Matrix m[]) {
    printf("\n\n\t\tMATRIX VECTOR\n\n");
    printf("CODE\tSOLD AMOUNT\tAMOUNT\n\n");

    for (int i = 0; i < sizeMatrix; i++) {
        printf("%d\t\t%d\t\t%.2f\n", 
        m[i].cod, m[i].sold_amount, m[i].amount);
    }

}

void createMatrixVector(Matrix m[], Branch b1[]) {
    for(int i = 0; i < sizeB1; i++) {
        m[sizeMatrix].cod = b1[i].cod;
        m[sizeMatrix].sold_amount = b1[i].amount;
        m[sizeMatrix].amount = b1[i].price * b1[i].amount;
        sizeMatrix += 1;
    }

}

void checkExist(Matrix m[], Branch b2[]) {
    for(i=0; i < sizeB2; i++) {
        int pieceExist = 0;

        for(j=0; j < sizeMatrix; j++) {
            if(m[j].cod == b2[i].cod) {
                m[j].sold_amount += b2[i].amount;
                m[j].amount += b2[i].price * b2[i].amount;
                pieceExist = 1;
                break;
            }
        }

        if(!pieceExist) {
            m[sizeMatrix].cod = b2[i].cod;
            m[sizeMatrix].sold_amount = b2[i].amount;
            m[sizeMatrix].amount = b2[i].price * b2[i].amount;
            sizeMatrix += 1;
        }

    }

}

int biggestSale(Matrix m[]){
    int big = m[0].sold_amount;
    int is_big = 0;

    for(i = 1; i < sizeMatrix; i++) {
        if(m[i].sold_amount > big) {
            big = m[i].sold_amount;
            is_big = i;
        }

    }
    printf("\nTHE BIGGEST SALE WAS FOR THE PIECE WITH CODE: %d", 
    m[is_big].cod);

    return m[is_big].cod;

}

void findBestSellingPiece(int cod, Branch b1[], Branch b2[]) {
    int found = 0;

    for(i = 0; i < sizeB1; i++) {
        if(cod == b1[i].cod) {
            printf("\nBEST SELLING PIECE: %s\n", b1[i].description);
            printf("CAR MODEL: %s\n", b1[i].model);
            found = 1;
        }

    }

    if(!found) {
        for(i = 0; i < sizeB2; i++) {
            if(cod == b2[i].cod) {
                printf("\nBEST SELLING PIECE: %s\n", b2[i].description);
                printf("CAR MODEL: %s\n", b2[i].model);
                found = 1;
            }

        }

    }

}

int main(int argc, char **argv) {
    int y;
    Branch b1[SIZE] = {
        {1,"Motor", "Kombi", "Volks", 1900, 2005, 10, 200},
        {2,"Car door", "Celta", "Chevrolet", 2000, 2010, 4, 400},
        {3,"Wheels", "Civic", "Honda", 1999, 2012, 2, 700}
    };
    Branch b2[SIZE] = {
        {1,"Motor", "Model X", "Tesla", 2022, 2023, 2, 900},
        {2,"Rear view", "HB20", "Hyundai", 2020, 2023, 6, 100},
        {3,"Exchange", "Porsche 911", "Porsche", 1964, 2023, 8, 1000}
    };
    Matrix m[2*SIZE];

    // Print Branch
    printBranch(b1, 1, sizeB1);
    printBranch(b2, 2, sizeB2);

    // Create Matrix Vector
    createMatrixVector(m, b1);

    // Check Exist 
    checkExist(m, b2);

    // Print Matrix
    printMatrix(m);
    
    // Biggest Sale
    y = biggestSale(m);

    // Find Best Selling Piece
    findBestSellingPiece(y, b1, b2);

    return 0;
}