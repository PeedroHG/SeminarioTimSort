#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include "registro.h"
#include <stdlib.h>

typedef struct {
    Registro* itens;
    int tamanho;
    int capacidade;
    int frente;
    int tras;
} DynamicQueue;

void inicializarDynamicQueue(DynamicQueue* q);
int inserirDynamicQueue(DynamicQueue* q, Registro r);
int removerDynamicQueue(DynamicQueue* q, Registro* r);
void imprimirDynamicQueue(DynamicQueue* q);
void salvarDynamicQueueEmArquivo(DynamicQueue* q, const char *nomeArquivo);

#endif