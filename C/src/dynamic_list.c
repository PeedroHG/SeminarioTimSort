#include "dynamic_list.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarDynamicList(DynamicList* l) {
    l->tamanho = 0;
    l->capacidade = 10; // capacidade inicial
    l->itens = (Registro*) malloc(l->capacidade * sizeof(Registro));
}

int inserirFinalDynamic(DynamicList* l, Registro r) {
    if (l->tamanho >= l->capacidade) {
        // aumentar a capacidade da lista
        l->capacidade *= 2;
        l->itens = (Registro*) realloc(l->itens, l->capacidade * sizeof(Registro));
    }
    l->itens[l->tamanho++] = r;
    return 1;
}

int removerValorDynamic(DynamicList* l, int valor) {
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

void imprimirDynamicList(DynamicList* l) {
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->itens[i].valor);
    }
    printf("\n");
}

void salvarDynamicListEmArquivo(DynamicList* l, const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    for (int i = 0; i < l->tamanho; i++) {
        fprintf(fp, "%d\n", l->itens[i].valor);
    }
    fclose(fp);
}