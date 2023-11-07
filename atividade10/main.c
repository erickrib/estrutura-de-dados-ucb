#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabela_hash.h"

#define SIZE 10

struct DataItem* hashArray[SIZE];
struct DataItem* itemVazio;
char* item;

void display() {
    int i = 0;

    for (i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL) {
            printf(" (%s, %s)", hashArray[i]->chave, hashArray[i]->dado);
            printf("\n");
        }
        else {
            printf(" ~~ ");
            printf("\n");
        }
    }
}

void printChaveValor(char* chave) {
    item = hash_table_get(chave);
    if (item != NULL) {
        printf("(%s : %s)\n", chave, item);
    }
    else {
        printf("Chave nao encontrada\n");
    }
}

int main() {
    itemVazio = (struct DataItem*)malloc(sizeof(struct DataItem));
    itemVazio->dado = NULL;
    itemVazio->chave = NULL;

    hash_table_put("djoko", "Servia");
    hash_table_put("messi", "Argentina");
    hash_table_put("cr7", "Portugal");
    hash_table_put("key4", "value4");

    hash_table_put("key5", "value5");
    hash_table_put("key6", "value6");
    hash_table_put("key7", "");
    hash_table_put("key8", "value8");

    printChaveValor("djoko");
    printChaveValor("cr7");
    printChaveValor("key7");

    hash_table_remove("messi");
    printChaveValor("messi");

    printf("%d", hash_table_contains("messi"));

    exit(0);
}