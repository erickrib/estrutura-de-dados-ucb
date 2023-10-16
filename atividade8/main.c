#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', no('A', NULL))))));
    No* n3 = no('U', NULL);



    printf("%d", lista_verificar_existencia(n2, 'Y')); 
    printf("%d", lista_verificar_ocorrencias(n2, 'A')); 
    printf("%d\n", lista_verificar_ocorrencias(n2, 'B')); 

    lista_inserir_no_i(n1, 0, 'P');
    lista_inserir_no_i(n1, 0, 'B');
    lista_inserir_no_i(n1, 0, 'V');

    lista_imprimir(n1);

    // printf("\nqtd nos: %d", lista_quantidade_nos(n0));

    // No* n_copia = lista_copiar(n0);

    // printf("\n");

    // lista_concatenar(n0, n_copia);

    // printf("\n");

    // lista_imprimir(n0);
    // lista_liberar(n0);
    // n0 = NULL;
    // lista_imprimir(n0);

    exit(0);
}