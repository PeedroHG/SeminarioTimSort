#include <stdio.h>
#include <time.h>
#include "static_list.h"
#include "file_reader.h"
#include "tim_sort.h"

#define INPUT_FILE "../SamplesR/amostra_100000.csv"
#define OUTPUT_FILE "./ordened/static_list_ratings/sample_1000000.csv"
#define TAMANHO 1000000

int main()
{
    StaticList lista;
    inicializarStaticList(&lista);

    int arr[TAMANHO];
    carregarCVS(INPUT_FILE, arr, TAMANHO);
    printf("Dados carregados\n");

    clock_t inicio, fim;
    inicio = clock();

    Registro r;
    for (int i = 0; i < TAMANHO; i++)
    {
        r.valor = arr[i];
        inserirFinalStatic(&lista, r);
    }

    ordenarStaticList(&lista);

    fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", tempo);

    salvarStaticListEmArquivo(&lista, OUTPUT_FILE);
    return 0;
}
