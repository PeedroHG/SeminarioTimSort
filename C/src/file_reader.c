#include <stdio.h>
#include <stdlib.h>
#include "file_reader.h"

int carregarCVS(const char *filename, int *arr, int n)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return 0;

    char linha[100];
    fgets(linha, sizeof(linha), fp); // Ignora cabeçalho

    for (int i = 0; i < n; i++)
    {
        fgets(linha, sizeof(linha), fp);
        arr[i] = atoi(linha);
    }

    fclose(fp);
    return 1;
}