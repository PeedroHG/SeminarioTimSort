#include <stdio.h>
#include "dynamic_list.h"
#include "file_reader.h"
#include "tim_sort.h"

#define INPUT_FILE "../Samples/sample_1000000.csv"
#define OUTPUT_FILE "./ordened/dynamic_queue/sample_1000000.csv"

int main()
{
    DynamicQueue lista;
    inicializarDynamicQueue(&lista);

    if (carregarCSVparaDynamicQueue(INPUT_FILE, &lista))
    {
        printf("Dados carregados na DynamicQueue:\n");

        ordenarDynamicQueue(&lista);

        printf("Dados ordenados:\n");

        salvarDynamicQueueEmArquivo(&lista, OUTPUT_FILE);
    }
    else
    {
        printf("Falha ao carregar dados do arquivo.\n");
    }

    return 0;
}
