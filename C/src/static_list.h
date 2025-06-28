#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <stdio.h>
#include "registro.h"

#define MAXTAM 100

typedef struct {
    Registro itens[MAXTAM];
    int tamanho;
} StaticList;

static inline void inicializarStaticList(StaticList *l) {
    l->tamanho = 0;
}

static inline int inserirFinalStatic(StaticList *l, Registro r) {
    if (l->tamanho >= MAXTAM) return 0;

    l->itens[l->tamanho++] = r;
    return 1;
}

static inline int removerValorStatic(StaticList *l, int valor) {
    for (int i = 0; i < l->tamanho; i++) {
        if (l->itens[i].valor == valor) {
            for (int j = i; j < l->tamanho - 1; j++) {
                l->itens[j] = l->itens[j + 1];
            }
            l->tamanho--;
            return 1;
        }
    }
    return 0;
}

static inline void imprimirStaticList(StaticList *l) {
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->itens[i].valor);
    }
    printf("\n");
}

static inline void salvarStaticListEmArquivo(StaticList *l, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (int i = 0; i < l->tamanho; i++) {
        fprintf(arquivo, "%d \n", l->itens[i].valor);
    }

    fclose(arquivo);
}

#endif
