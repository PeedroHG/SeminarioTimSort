#include <stdio.h>
#include "static_queue.h"
#include "file_reader.h"
#include "tim_sort.h"

int main() {
    StaticQueue fila;
    inicializarStaticQueue(&fila);

    if (carregarCSVparaStaticQueue("../Samples/sample_1000000.csv", &fila)) {
        printf("Dados carregados na StaticQueue:\n");
        imprimirStaticQueue(&fila);

        ordenarStaticQueue(&fila);

        printf("\nDados ordenados na StaticQueue:\n");
        imprimirStaticQueue(&fila);
    } else {
        printf("Falha ao carregar dados do arquivo.\n");
    }

    return 0;
}
