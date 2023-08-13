#include <stdio.h>

// Função para verificar se um número é primo
int ehPrimo(int num) {
    if (num <= 1) {
        return 0;  // Números menores ou iguais a 1 não são primos
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // Se o número for divisível por algum valor entre 2 e a raiz quadrada, não é primo
        }
    }

    return 1;  // Caso contrário, é primo
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]);  // Converte o argumento para um número inteiro

    if (ehPrimo(numero)) {
        printf("1 - O numero %d eh primo.\n", numero);
    } else {
        printf("0 - O numero %d nao eh primo.\n", numero);
    }

    return 0;
}
