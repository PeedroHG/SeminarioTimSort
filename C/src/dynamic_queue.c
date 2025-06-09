#include "dynamic_queue.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarDynamicQueue(DynamicQueue* q) {
    q->tamanho = 0;
    q->capacidade = 10; // capacidade inicial
    q->itens = (Registro*) malloc(q->capacidade * sizeof(Registro));
    q->frente = 0;
    q->tras = 0;
}

int inserirDynamicQueue(DynamicQueue* q, Registro r) {
    if (q->tamanho >= q->capacidade) {
        // aumentar a capacidade da fila
        q->capacidade *= 2;
        q->itens = (Registro*) realloc(q->itens, q->capacidade * sizeof(Registro));
    }
    q->itens[q->tras] = r;
    q->tras = (q->tras + 1) % q->capacidade;
    q->tamanho++;
    return 1;
}

int removerDynamicQueue(DynamicQueue* q, Registro* r) {
    if (q->tamanho == 0) return 0;
    *r = q->itens[q->frente];
    q->frente = (q->frente + 1) % q->capacidade;
    q->tamanho--;
    return 1;
}

void imprimirDynamicQueue(DynamicQueue* q) {
    int i = q->frente;
    for (int j = 0; j < q->tamanho; j++) {
        printf("%d ", q->itens[i].valor);
        i = (i + 1) % q->capacidade;
    }
    printf("\n");
}

void salvarDynamicQueueEmArquivo(DynamicQueue* q, const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    int i = q->frente;
    for (int j = 0; j < q->tamanho; j++) {
        fprintf(fp, "%d\n", q->itens[i].valor);
        i = (i + 1) % q->capacidade;
    }
    fclose(fp);
}