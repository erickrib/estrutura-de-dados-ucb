#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 100
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;

    for(int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_table() {
    printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i ++){
        if (hash_table[i] == NULL){
             printf("\t%i\t----\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p) {
    if (p == NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] != NULL){
        return false;
    }

    hash_table[index] = p;
    return true;
}

person * hash_table_lookup (char *name) {
    int index = hash(name);
    if (hash_table[index] != NULL &&
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0){
            return hash_table[index];
    } else {
        return NULL;
    }
}

person *hash_table_delete(char *name){
    int index = hash(name);
    if (hash_table[index] != NULL &&
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0){
            person *tmp = hash_table[index];
            hash_table[index] = NULL;
            return tmp;
    } else {
        return NULL;
    }
}

int main(){

    init_hash_table();
    print_table();

    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="Kate", .age=20};
    person mpho = {.name="Mpho", .age=50};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    print_table();

    person *tmp = hash_table_lookup("Mpho");

    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("George");

    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    hash_table_delete("Mpho");
    tmp = hash_table_lookup("Mpho");

    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    print_table();

    // https://youtu.be/2Ti5yvumFTU?si=9lU4L5Lf9Ovp_Fvd
    // PAREi na parte do updating insert

    // printf("Jacob => %u\n", hash("Jacob"));
    // printf("Natalie => %u\n", hash("Natalie"));
    // printf("Maria => %u\n", hash("Maria"));
    // printf("Jose => %u\n", hash("Jose"));
    // printf("Theo => %u\n", hash("Theo"));
    // printf("Leo => %u\n", hash("Leo"));
    // printf("Marcos => %u\n", hash("Marcos"));
}

