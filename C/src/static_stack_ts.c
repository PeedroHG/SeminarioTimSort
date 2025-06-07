#include <stdio.h>
#include "static_stack.h"
#include "file_reader.h"
#include "tim_sort.h"

int main() {
    StaticStack pilha;
    inicializarStaticStack(&pilha);

    if (carregarCSVparaStaticStack("../Samples/sample_1000000.csv", &pilha)) {
        printf("Dados carregados na StaticStack:\n");
        imprimirStaticStack(&pilha);

        ordenarStaticStack(&pilha);

        printf("\nDados ordenados na StaticStack:\n");
        imprimirStaticStack(&pilha);
    } else {
        printf("Falha ao carregar dados do arquivo.\n");
    }

    return 0;
}
