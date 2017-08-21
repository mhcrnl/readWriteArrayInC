#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readArray.h"
/**
    Declararea variabilelor globale
*/
#define NR_MAX 100
const char* filename ="array.txt";
FILE *fp;
int n[NR_MAX];// Array cu 100 elemente
/**
    Declararea functiilor
*/
int readFromFile(const char* filename);
int writeToFile(const char* filename);
int runProgram(void);
int menu(void);

int writeToFile(const char* filename){
    const char* mode = "w";
    int i; // pt. for
    fp = fopen(filename, mode);
    if(fp == NULL){
        perror("Fila nu a fost deschisa.");
        return 1;
    }
    for(i=0; i<NR_MAX; i++){
        fprintf(fp, "%d\t", n[i]= i+100);
    }
    fclose(fp);
    return 0;
}
int size =100;
//int arr[size];

int runProgram(){
    while(1){
        int selectie = menu();
        switch(selectie){
            case 0:
                writeToFile(filename);
                break;
            case 1:
                readFromFile(filename);
                break;
            case 2:
                exit(0);
            case 3:
                readArrayFromFile(filename,n,size);
                break;
            case 4:
                system("./gitpush.sh");
                break;
            case 5:
                exit(0);
            default:
                printf("Alegerea dvs. nu corespunde meniului. Mai incercati!");
                menu();
        }
    }
}

int menu(void){
    int choice, i;
    const char *meniu[5] = {"Write to file", "Read from File", "Exit", "Read array",
            "Git Push"};
    for(i=0; i<5; i++){
        printf("\t%d\t%s\n", i, meniu[i]);
    }
    printf("Introduceti optiunea dvs: ");
    scanf("%d", &choice);
    return choice;
}

int readFromFile(const char* filename){
    const char* mode = "r";
    int arrayCitit[100];
    int i;

    fp = fopen(filename, mode);
    if(fp == NULL){
        perror("Fila nu a fost deschisa.");
        return 1;
    }
    for(i =0; i<100; i++){
        fscanf(fp,"%d",&arrayCitit[i]);
        printf("ArrayCitit[%d] = %d\n", i, arrayCitit[i]);
    }
    printf("\n");
    fclose(fp);
    return 0;
}

int main()
{
    printf("Hello world!\n");
    runProgram();
    return 0;
}
