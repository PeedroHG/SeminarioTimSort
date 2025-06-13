#include <stdio.h>
#include <time.h>
#include "dynamic_list.h"
#include "file_reader.h"
#include "tim_sort.h"

#define INPUT_FILE "../Samples/sample_1000000.csv"
#define OUTPUT_FILE "./ordened/dynamic_queue/sample_1000000.csv"
#define TAMANHO 1000000

int main()
{
    DynamicQueue queue;
    inicializarDynamicQueue(&queue);

    int arr[TAMANHO];
    carregarCVS(INPUT_FILE, arr, TAMANHO);
    printf("Dados carregados\n");

    clock_t inicio, fim;
    inicio = clock();

    Registro r;
    for (int i = 0; i < TAMANHO; i++)
    {
        r.valor = arr[i];
        enfileirarDynamicQueue(&queue, r);
    }

    ordenarDynamicQueue(&queue);

    fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", tempo);

    salvarDynamicQueueEmArquivo(&queue, OUTPUT_FILE);
    return 0;
}
