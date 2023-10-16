#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* L, No* no){
    if(L != NULL){
        if(L->proximo_no == NULL){
            L->proximo_no = no;
        }
        else{
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L){
    if(L != NULL){
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L){
    if(L != NULL){
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L){
    if(L != NULL){
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc){
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L){
    if(L != NULL){
        lista_liberar(L->proximo_no);
        free(L);
    }
}

// Novas funções

int lista_verificar_existencia(No* L, char valor_busca){
    if (L != NULL){
        if (L->valor == valor_busca){
            return 1;
        } else {
            return lista_verificar_existencia(L->proximo_no, valor_busca);
        }
    } 
    
    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca){
    int ocorrencias = 0;

    if (L != NULL){
        if (L->valor == valor_busca){
            ocorrencias = 1;
        } 
        return ocorrencias + lista_verificar_ocorrencias(L->proximo_no, valor_busca);
    } 

    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L != NULL) {
        lista_imprimir_inversa(L->proximo_no);
        printf("%c", L->valor);
    }
}

void lista_inserir_no_i(No* L, int i, char valor) {
    if (i < 0 || i > lista_quantidade_nos(L) - 1) {
        exit(0);
    }

    if(i == 0) {
        No* novo = no(valor, L->proximo_no);
        L->proximo_no = novo;
    } else if (L != NULL) {
        lista_inserir_no_i(L->proximo_no, i - 1, valor);
    }
}

void lista_remover_no_i(No* L, int i) {
    if (i < 0 || i > lista_quantidade_nos(L) - 1) {
        exit(0);
    }

    if(i == 0) {
        No* remove = L->proximo_no;
        L->valor = remove->valor;
        L->proximo_no = remove->proximo_no;
        free(remove);
    } else if (L != NULL) {
        lista_remover_no_i(L->proximo_no, i - 1);
    } 
}


void lista_remover_no(No* L, char valor) {
    if (L == NULL) {
        return; 
    }

    if (L->proximo_no != NULL && L->proximo_no->valor == valor) {

        No* remove = L->proximo_no;
        L->proximo_no = remove->proximo_no;
        free(remove);
        lista_remover_no(L, valor); 
    } else {
        lista_remover_no(L->proximo_no, valor);
    }
}