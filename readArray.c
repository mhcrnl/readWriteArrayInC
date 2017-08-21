/**
	@Author:	Mihai Cornel	Romania			mhcrnl@gmail.com
	@System:	Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
                	Fedora 24	Code::Blocks 16.01	gcc 5.3.1
			Windows Vista 	Code::Blocks 16.01
	@Copyright:	2017
	@file:
*/

#include "readArray.h"

int* readArrayFromFile(const char* filename, int arr[], int dim){
    const char* mode = "r";
    int i;
    FILE *fp;
    fp = fopen(filename, mode);
    if(fp == NULL){
        perror("Fila nu a fost deschisa.");
        return 1;
    }
    for(i=0; i<dim; i++){
        fscanf(fp,"%d", &arr[i]);
        printf("ARR[%d] = %d\n", i, arr[i]);
    }

    fclose(fp);
    return arr;
}
