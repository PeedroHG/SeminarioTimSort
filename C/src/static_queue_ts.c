#include <stdio.h>
#include "static_queue.h"
#include "file_reader.h"
#include "tim_sort.h"

#define INPUT_FILE "../Samples/sample_1000000.csv"
#define OUTPUT_FILE "./ordened/static_queue/sample_1000000.csv"

int main() {
    StaticQueue fila;
    inicializarStaticQueue(&fila);

    if (carregarCSVparaStaticQueue(INPUT_FILE, &fila)) {
        printf("Dados carregados na StaticQueue:\n");

        ordenarStaticQueue(&fila);

        printf("\nDados ordenados:\n");
        salvarStaticQueueEmArquivo(&fila, OUTPUT_FILE);
    } else {
        printf("Falha ao carregar dados do arquivo.\n");
    }

    return 0;
}
