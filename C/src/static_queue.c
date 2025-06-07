#include <stdio.h>
#include "static_queue.h"

void inicializarStaticQueue(StaticQueue *q) {
    q->frente = 0;
    q->tras = -1;
    q->tamanho = 0;
}

int filaVazia(StaticQueue *q) {
    return q->tamanho == 0;
}

int filaCheia(StaticQueue *q) {
    return q->tamanho == MAXTAM;
}

int enfileirar(StaticQueue *q, Registro r) {
    if (filaCheia(q)) return 0;

    q->tras = (q->tras + 1) % MAXTAM;
    q->dados[q->tras] = r;
    q->tamanho++;
    return 1;
}

int desenfileirar(StaticQueue *q, Registro *r) {
    if (filaVazia(q)) return 0;

    *r = q->dados[q->frente];
    q->frente = (q->frente + 1) % MAXTAM;
    q->tamanho--;
    return 1;
}

void imprimirStaticQueue(StaticQueue *q) {
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
