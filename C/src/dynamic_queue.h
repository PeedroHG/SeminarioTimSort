#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct {
    No *head;
    No *tail;
    int size;
} DynamicQueue;

static inline void inicializarDynamicQueue(DynamicQueue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

static inline int enfileirarDynamicQueue(DynamicQueue *queue, Registro valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) return 0;

    novo->valor = valor;
    novo->prox = NULL;

    if (queue->tail == NULL) {
        queue->head = novo;
        queue->tail = novo;
    } else {
        queue->tail->prox = novo;
        queue->tail = novo;
    }

    queue->size++;
    return 1;
}

static inline int filaVaziaDynamicQueue(DynamicQueue *queue) {
    return queue->size == 0;
}

static inline int desenfileirarDynamicQueue(DynamicQueue *queue, Registro *valor) {
    if (filaVaziaDynamicQueue(queue)) return 0;

    No *remover = queue->head;
    *valor = remover->valor;
    queue->head = remover->prox;
    if (queue->head == NULL)
        queue->tail = NULL;

    free(remover);
    queue->size--;
    return 1;
}

static inline void imprimirDynamicQueue(DynamicQueue *queue) {
    No *atual = queue->head;
    while (atual != NULL) {
        printf("%d ", atual->valor.valor);
        atual = atual->prox;
    }
    printf("\n");
}

static inline void salvarDynamicQueueEmArquivo(DynamicQueue *queue, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo para escrita");
        return;
    }

    No *atual = queue->head;
    while (atual != NULL) {
        fprintf(arquivo, "%d\n", atual->valor.valor);
        atual = atual->prox;
    }

    fclose(arquivo);
}

#endif
