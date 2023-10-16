#include "fila.h"
#include <stdio.h>

void inicializarFila(struct FilaPedidos* fila) {
    fila->inicio = -1;
    fila->fim = -1;
}

int filaVazia(struct FilaPedidos* fila) {
    return fila->inicio == -1;
}

int filaCheia(struct FilaPedidos* fila) {
    return (fila->fim + 1) % MAX_PEDIDOS == fila->inicio;
}

void enfileirar(struct FilaPedidos* fila, struct Pedido pedido) {
    if (filaCheia(fila)) {
        printf("Erro: A fila de pedidos está cheia.\n");
        return;
    }
    if (filaVazia(fila)) {
        fila->inicio = 0;
    }
    fila->fim = (fila->fim + 1) % MAX_PEDIDOS;
    fila->pedidos[fila->fim] = pedido;
    printf("Pedido #%d de %s adicionado à fila.\n", pedido.numero_pedido, pedido.nome_cliente);
}

struct Pedido desenfileirar(struct FilaPedidos* fila) {
    struct Pedido pedidoVazio = {0, "", "", 0};
    if (filaVazia(fila)) {
        printf("Erro: A fila de pedidos está vazia.\n");
        return pedidoVazio;
    }
    struct Pedido pedidoAtendido = fila->pedidos[fila->inicio];
    if (fila->inicio == fila->fim) {
        fila->inicio = -1;
        fila->fim = -1;
    } else {
        fila->inicio = (fila->inicio + 1) % MAX_PEDIDOS;
    }
    printf("Pedido #%d de %s atendido.\n", pedidoAtendido.numero_pedido, pedidoAtendido.nome_cliente);
    return pedidoAtendido;
}

void listarPedidos(struct FilaPedidos* fila) {
    if (filaVazia(fila)) {
        printf("A fila de pedidos está vazia.\n");
        return;
    }
    printf("Lista de Pedidos:\n");
    int i = fila->inicio;
    int numeroPedido = 1;
    do {
        printf("Pedido #%d de %s para %s (Quantidade: %d)\n", fila->pedidos[i].numero_pedido, fila->pedidos[i].nome_cliente, fila->pedidos[i].nome_medicamento, fila->pedidos[i].quantidade);
        i = (i + 1) % MAX_PEDIDOS;
        numeroPedido++;
    } while (i != (fila->fim + 1) % MAX_PEDIDOS);
}

