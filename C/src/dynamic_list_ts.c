#include <stdio.h>
#include "dynamic_list.h"
#include "file_reader.h"
#include "tim_sort.h"

#define INPUT_FILE "../Samples/sample_100.csv"
#define OUTPUT_FILE "./ordened/dynamic_list/sample_100.csv"

int main()
{
    DynamicList lista;
    inicializarDynamicList(&lista);

    if (carregarCSVparaDynamicList(INPUT_FILE, &lista))
    {
        printf("Dados carregados na DynamicList:\n");

        ordenarDynamicList(&lista);

        printf("Dados ordenados:\n");

        salvarDynamicListEmArquivo(&lista, OUTPUT_FILE);
    }
    else
    {
        printf("Falha ao carregar dados do arquivo.\n");
    }

    return 0;
}
