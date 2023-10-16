#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    struct FilaPedidos filaFarmacia;
    inicializarFila(&filaFarmacia);

    int contadorPedidos = 1;

    while (1) {
        int escolha;
        printf("\nEscolha uma opção:\n");
        printf("1. Fazer um pedido\n");
        printf("2. Atender um pedido\n");
        printf("3. Ver Pedidos\n");
        printf("4. Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                struct Pedido novoPedido;
                novoPedido.numero_pedido = contadorPedidos++;
                printf("Nome do cliente: ");
                scanf("%s", novoPedido.nome_cliente);
                printf("Nome do medicamento: ");
                scanf("%s", novoPedido.nome_medicamento);
                printf("Quantidade: ");
                scanf("%d", &novoPedido.quantidade);
                enfileirar(&filaFarmacia, novoPedido);
                break;
            }
            case 2: {
                if (!filaVazia(&filaFarmacia)) {
                    desenfileirar(&filaFarmacia);
                } else {
                    printf("A fila de pedidos está vazia.\n");
                }
                break;
            }
            case 3:
                listarPedidos(&filaFarmacia);
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}
