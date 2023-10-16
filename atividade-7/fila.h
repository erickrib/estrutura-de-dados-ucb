#define MAX_PEDIDOS 100

struct Pedido {
    int numero_pedido;
    char nome_cliente[50];
    char nome_medicamento[50];
    int quantidade;
};

struct FilaPedidos {
    struct Pedido pedidos[MAX_PEDIDOS];
    int inicio;
    int fim;
};

void inicializarFila(struct FilaPedidos* fila);
int filaVazia(struct FilaPedidos* fila);
int filaCheia(struct FilaPedidos* fila);
void enfileirar(struct FilaPedidos* fila, struct Pedido pedido);
struct Pedido desenfileirar(struct FilaPedidos* fila);
void listarPedidos(struct FilaPedidos* fila);


