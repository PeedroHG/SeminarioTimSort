#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include "node.h"

typedef struct {
    No *head;
    No *tail;
    int size;
} DynamicQueue;

void inicializarDynamicQueue(DynamicQueue *queue);
int enfileirarDynamicQueue(DynamicQueue *queue, Registro valor);
int desenfileirarDynamicQueue(DynamicQueue *queue, Registro *valor);
int filaVaziaDynamicQueue(DynamicQueue *queue);
void imprimirDynamicQueue(DynamicQueue *queue);
void salvarDynamicQueueEmArquivo(DynamicQueue *queue, const char *nomeArquivo);

#endif
