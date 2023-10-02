#include <stdio.h>
#include <string.h>

#define TAM 24

typedef struct {
    int cod;
    char name[50], disc[50];
    float average;
    int freq;

}Academic;

float percentage(Academic f[], char dis[], int ch){
    int i, ap = 0, tm = 0;
    if(ch == 1){
        for(i=0; i<TAM; i++){
            if(strcmp(f[i].disc, dis) == 0){
                tm += 1;
                if(f[i].freq >= 75 && f[i].average >= 7){
                    ap += 1;
                }
            }
        }
    }
    if(ch == 2){
        for(i=0; i<TAM; i++){
            if(strcmp(f[i].disc, dis) == 0){
                tm += 1;
                if(f[i].freq < 75){
                    ap += 1;
                }
                else if(f[i].average < 7){
                    ap += 1;
                }
            }
        }
    }
    return (ap*100)/tm;
}

void listAp(Academic f[], char dis[], int ch){
    int i;
    if(ch == 1){
        printf("\nDiscipline de %s", dis);
        printf("\nRegistration\tName\tAverage\tApproval");
        for(i=0; i<TAM;i++){
            if(strcmp(f[i].disc, dis) == 0){
                if(f[i].average >= 7 && f[i].freq >= 75){
                    printf("\n%d\t\t%s\t%.1f\tScore e Frequency", f[i].cod, f[i].name, f[i].average);
                }
            }
        }
    }
    if(ch == 2){
        printf("\nDiscipline de %s", dis);
        printf("\nRegistration\tName\taverage\tDisapproval");
        for(i=0; i<TAM;i++){
            if(strcmp(f[i].disc, dis) == 0){
                if(f[i].average < 7 && f[i].freq < 75){
                    printf("\n%d\t\t%s\t%.1f\tScore e Miss", f[i].cod, f[i].name, f[i].average);
                }
                else if(f[i].average < 7){
                    printf("\n%d\t\t%s\t%.1f\tScore", f[i].cod, f[i].name, f[i].average);
                }

                else if(f[i].freq < 75){
                    printf("\n%d\t\t%s\t%.1f\tMiss", f[i].cod, f[i].name, f[i].average);
                }
            }
        }
    }
}

int main(){
    float per;
    int ch, es;
    char disc[50];
    Academic university[TAM] = {
        {10,"ABEL"  ,"CDI",7.5,80},
        {10,"ABEL"  ,"LOGIC",8.4,76},
        {10,"ABEL"  ,"ALGORITHMS",7.8,78},
        {10,"ABEL"  ,"IOC",3.5,20},
        {5 ,"ALBINO","CDI",8.3,87},
        {5 ,"ALBINO","LOGIC",2.5,75},
        {5 ,"ALBINO","ALGORITHMS",9.0,95},
        {5 ,"ALBINO","IOC",7.5,74},
        {9 ,"BRUNO" ,"CDI",6.1,80},
        {9 ,"BRUNO" ,"LOGIC",7.5,98},
        {9 ,"BRUNO" ,"ALGORITHMS",5.2,77},
        {9 ,"BRUNO" ,"IOC",6.2,79},
        {3 ,"CARLOS","CDI",7.5,83},
        {3 ,"CARLOS","LOGIC",7.8,95},
        {3 ,"CARLOS","ALGORITHMS",8.5,90},
        {3 ,"CARLOS","IOC",9.3,96},
        {12,"VICTOR" ,"CDI",7.5,82},
        {12,"VICTOR" ,"LOGIC",6.8,84},
        {12,"VICTOR" ,"ALGORITHMS",7.5,96},
        {12,"VICTOR" ,"IOC",7.8,88},
        {2 ,"ZELDA" ,"CDI",3.3,76},
        {2 ,"ZELDA" ,"LOGIC",1.4,79},
        {2 ,"ZELDA" ,"ALGORITHMS",7.6,80},
        {2 ,"ZELDA" ,"IOC",6.1,97}
    };

    printf(">> 1 - View percentage\n>> 2 - List\n");
    scanf("%d", &es);
    
    switch (es){
        case 1:
            printf(">> 1 - Approved\n>> 2 - Disapproved\n");
            scanf("%d", &ch);
            printf("Enter the name of the discipline:");
            scanf("%s", disc);
            per = percentage(university, disc, ch);
            printf("From the discipline informed %.1f%% disapproved in the subject\n", per);
            break;
        case 2:
            printf(">> 1 - Approved\n>> 2 - Disapproved\n");
            scanf("%d", &ch);
            printf("Enter the name of the discipline:");
            scanf("%s", disc);
            listAp(university, disc, ch);
            break;
        default:
            printf("Erro");
            break;
    }

    return 0;
}