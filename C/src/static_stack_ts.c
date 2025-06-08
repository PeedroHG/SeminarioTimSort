#include <stdio.h>
#include "static_stack.h"
#include "file_reader.h"
#include "tim_sort.h"

#define INPUT_FILE "../Samples/sample_100.csv"
#define OUTPUT_FILE "./ordened/static_stack/sample_100.csv"

int main()
{
    StaticStack pilha;
    inicializarStaticStack(&pilha);

    if (carregarCSVparaStaticStack(INPUT_FILE, &pilha))
    {
        printf("Dados carregados na StaticStack:\n");

        ordenarStaticStack(&pilha);

        printf("\nDados ordenados:\n");

        salvarStaticListEmArquivo(&pilha, OUTPUT_FILE);
    }
    else
    {
        printf("Falha ao carregar dados do arquivo.\n");
    }

    return 0;
}
