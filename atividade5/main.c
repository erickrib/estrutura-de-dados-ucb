#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "bubble_sort.h"
#define TAM 100

int records = 0;

int main(int argc, char* argv[]){

    FILE *file;
    file = fopen(argv[1], "r");

    if (file == NULL){
        printf("Erro de leitura do arquivo");
        exit(1);
    }

    char strings[TAM][100] = {};

    int read = 0;

    do{
        read = fscanf(file, "%s", strings[records]);

        if (read == 1)
            records++;

        if (read != 1 && !feof(file))
        {
            printf("File format incorrect.\n");
            return 1;
        }

        if (ferror(file))
        {
            printf("Error reading file.\n");
            return 1;
        }
    } while (!feof(file));

    // printf("%s", strings[1]);

    ordernarArrayPalavras(strings, TAM);

    int t =  strcmp("Tcarrao", "b");

    fclose(file);

    exit(0);
}
