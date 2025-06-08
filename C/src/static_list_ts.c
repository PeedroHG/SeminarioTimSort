#include <stdio.h>
#include "static_list.h"
#include "file_reader.h"
#include "tim_sort.h"

#define INPUT_FILE "../Samples/sample_100.csv"
#define OUTPUT_FILE "./ordened/static_list/sample_100.csv"

int main()
{
    StaticList lista;
    inicializarStaticList(&lista);

    if (carregarCSVparaStaticList(INPUT_FILE, &lista))
    {
        printf("Dados carregados na StaticList:\n");

        ordenarStaticList(&lista);

        printf("Dados ordenados:\n");

        salvarStaticListEmArquivo(&lista, OUTPUT_FILE);
    }
    else
    {
        printf("Falha ao carregar dados do arquivo.\n");
    }

    return 0;
}
