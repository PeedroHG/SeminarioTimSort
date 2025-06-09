#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "registro.h"
#include <stdlib.h>

typedef struct {
    Registro* itens;
    int tamanho;
    int capacidade;
} DynamicList;

void inicializarDynamicList(DynamicList* l);
int inserirFinalDynamic(DynamicList* l, Registro r);
int removerValorDynamic(DynamicList* l, int valor);
void imprimirDynamicList(DynamicList* l);
void salvarDynamicListEmArquivo(DynamicList* l, const char *nomeArquivo);

#endif