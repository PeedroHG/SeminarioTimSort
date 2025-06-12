#include <stdio.h>
#include <stdlib.h>
#include "file_reader.h"

int carregarCSVparaStaticList(const char *filename, StaticList *lista)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return 0;

    char linha[100];
    fgets(linha, sizeof(linha), fp); // Ignora cabeçalho

    while (fgets(linha, sizeof(linha), fp))
    {
        Registro reg;
        reg.valor = atoi(linha);
        if (!inserirFinalStatic(lista, reg))
        {
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int carregarCSVparaStaticQueue(const char *filename, StaticQueue *fila)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return 0;

    char linha[100];
    fgets(linha, sizeof(linha), fp); // Ignora cabeçalho

    while (fgets(linha, sizeof(linha), fp))
    {
        Registro reg;
        reg.valor = atoi(linha);
        if (!enfileirar(fila, reg))
        {
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int carregarCSVparaStaticStack(const char *filename, StaticStack *pilha)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return 0;

    char linha[100];
    fgets(linha, sizeof(linha), fp); // Ignora cabeçalho

    while (fgets(linha, sizeof(linha), fp))
    {
        Registro reg;
        reg.valor = atoi(linha);
        if (!empilhar(pilha, reg))
        {
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int carregarCSVparaDynamicList(const char *filename, DynamicList *lista)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return 0;

    char linha[100];
    fgets(linha, sizeof(linha), fp); // Ignora cabeçalho

    while (fgets(linha, sizeof(linha), fp))
    {
        Registro reg;
        reg.valor = atoi(linha);
        if (!inserirFimDynamicList(lista, reg))
        {
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int carregarCSVparaDynamicQueue(const char *filename, DynamicQueue *fila)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return 0;

    char linha[100];
    fgets(linha, sizeof(linha), fp); // Ignora cabeçalho

    while (fgets(linha, sizeof(linha), fp))
    {
        Registro reg;
        reg.valor = atoi(linha);
        if (!enfileirarDynamicQueue(fila, reg))
        {
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int carregarCSVparaDynamicStack(const char *filename, DynamicStack *pilha)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return 0;

    char linha[100];
    fgets(linha, sizeof(linha), fp); // Ignora cabeçalho

    while (fgets(linha, sizeof(linha), fp))
    {
        Registro reg;
        reg.valor = atoi(linha);
        if (!empilharDynamicStack(pilha, reg))
        {
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}