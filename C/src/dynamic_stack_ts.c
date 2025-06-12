#include <stdio.h>
#include "dynamic_list.h"
#include "file_reader.h"
#include "tim_sort.h"

#define INPUT_FILE "../Samples/sample_1000000.csv"
#define OUTPUT_FILE "./ordened/dynamic_stack/sample_1000000.csv"

int main()
{
    DynamicStack lista;
    inicializarDynamicStack(&lista);

    if (carregarCSVparaDynamicStack(INPUT_FILE, &lista))
    {
        printf("Dados carregados na DynamicStack:\n");

        ordenarDynamicStack(&lista);

        printf("Dados ordenados:\n");

        salvarDynamicStackEmArquivo(&lista, OUTPUT_FILE);
    }
    else
    {
        printf("Falha ao carregar dados do arquivo.\n");
    }

    return 0;
}
