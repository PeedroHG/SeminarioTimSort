#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "node.h"

typedef struct {
    No* head;
    No* tail;
    int size;
} DynamicList;

void inicializarDynamicList(DynamicList* list);
int inserirFimDynamicList(DynamicList* list, Registro valor);
int removerInicioDynamicList(DynamicList* list, Registro* valor);
void imprimirDynamicList(DynamicList* list);
void salvarDynamicListEmArquivo(DynamicList* list, const char *nomeArquivo);
#endif