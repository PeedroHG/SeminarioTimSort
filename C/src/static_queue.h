#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdio.h>
#include "registro.h"

#define MAXTAM 1000000

typedef struct {
    Registro dados[MAXTAM];
    int frente;
    int tras;
    int tamanho;
} StaticQueue;

static inline void inicializarStaticQueue(StaticQueue *q) {
    q->frente = 0;
    q->tras = -1;
    q->tamanho = 0;
}

static inline int filaVazia(StaticQueue *q) {
    return q->tamanho == 0;
}

static inline int filaCheia(StaticQueue *q) {
    return q->tamanho == MAXTAM;
}

static inline int enfileirar(StaticQueue *q, Registro r) {
    if (filaCheia(q)) return 0;

    q->tras = (q->tras + 1) % MAXTAM;
    q->dados[q->tras] = r;
    q->tamanho++;
    return 1;
}

static inline int desenfileirar(StaticQueue *q, Registro *r) {
    if (filaVazia(q)) return 0;

    *r = q->dados[q->frente];
    q->frente = (q->frente + 1) % MAXTAM;
    q->tamanho--;
    return 1;
}

static inline void imprimirStaticQueue(StaticQueue *q) {
    if (filaVazia(q)) {
        printf("Fila vazia.\n");
        return;
    }

    int i = q->frente;
    for (int count = 0; count < q->tamanho; count++) {
        printf("%d ", q->dados[i].valor);
        i = (i + 1) % MAXTAM;
    }
    printf("\n");
}

static inline void salvarStaticQueueEmArquivo(StaticQueue *q, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    int i = q->frente;
    for (int count = 0; count < q->tamanho; count++) {
        fprintf(arquivo, "%d\n", q->dados[i].valor);
        i = (i + 1) % MAXTAM;
    }

    fclose(arquivo);
}

#endif
