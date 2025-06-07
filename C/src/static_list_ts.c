#include <stdio.h>
#include "static_list.h"
#include "file_reader.h"
#include "tim_sort.h"

int main() {
    StaticList lista;
    inicializarStaticList(&lista);

    if (carregarCSVparaStaticList("../Samples/sample_1000000.csv", &lista)) {
        printf("Dados carregados na StaticList:\n");
        imprimirStaticList(&lista);

        ordenarStaticList(&lista);

        printf("\nLista após ordenação:\n");
        imprimirStaticList(&lista);
    } else {
        printf("Falha ao carregar dados do arquivo.\n");
    }

    return 0;
}
