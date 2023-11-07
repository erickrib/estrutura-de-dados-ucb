
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabela_hash.h"

#define SIZE 10

struct DataItem* hashArray[SIZE];

int hashCode(const char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % SIZE;
}

char* hash_table_get(char* chave) {
    int hashIndex = hashCode(chave);

    while (hashArray[hashIndex] != NULL) {
        if (strcmp(hashArray[hashIndex]->chave, chave) == 0)
            return hashArray[hashIndex]->dado;

        ++hashIndex;

        hashIndex %= SIZE;
    }

    return NULL;
}


void hash_table_put(char* chave, char* dado) {
    struct DataItem* item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->dado = strdup(dado);  
    item->chave = strdup(chave);    

    int index = hashCode(chave);

    while (hashArray[index] != NULL) {
        ++index;

        index %= SIZE;
    }

    hashArray[index] = item;
}


int hash_table_contains(char* chave){
     int index = hashCode(chave);

   
    while (hashArray[index] != NULL) {
        if (strcmp(hashArray[index]->chave, chave) == 0)
            return 1;

        ++index;

        index %= SIZE;
    }

    return 0;
}


void hash_table_remove(char* chave) {
    int index = hashCode(chave);

    while (hashArray[index] != NULL) {
        if (strcmp(hashArray[index]->chave, chave) == 0) {
            struct DataItem* temp = hashArray[index];

            free(hashArray[index]->dado);
            free(hashArray[index]->chave);

            hashArray[index] = NULL;
        }
        
        ++index;
        index %= SIZE;
    }

}