#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#define MAXTAM 1000000
#include "registro.h"

typedef struct {
    Registro dados[MAXTAM];
    int frente;
    int tras;
    int tamanho;
} StaticQueue;

void inicializarStaticQueue(StaticQueue *q);
int enfileirar(StaticQueue *q, Registro r);
int desenfileirar(StaticQueue *q, Registro *r);
int filaVazia(StaticQueue *q);
int filaCheia(StaticQueue *q);
void imprimirStaticQueue(StaticQueue *q);
void salvarStaticQueueEmArquivo(StaticQueue *q, const char *nomeArquivo);

#endif
