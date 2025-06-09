#include "dynamic_stack.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarDynamicStack(DynamicStack* s) {
    s->tamanho = 0;
    s->capacidade = 10; // capacidade inicial
    s->itens = (Registro*) malloc(s->capacidade * sizeof(Registro));
}

int pushDynamicStack(DynamicStack* s, Registro r) {
    if (s->tamanho >= s->capacidade) {
        // aumentar a capacidade da pilha
        s->capacidade *= 2;
        s->itens = (Registro*) realloc(s->itens, s->capacidade * sizeof(Registro));
    }
    s->itens[s->tamanho++] = r;
    return 1;
}

int popDynamicStack(DynamicStack* s, Registro* r) {
    if (s->tamanho == 0) return 0;
    *r = s->itens[--s->tamanho];
    return 1;
}

void imprimirDynamicStack(DynamicStack* s) {
    for (int i = s->tamanho - 1; i >= 0; i--) {
        printf("%d ", s->itens[i].valor);
    }
    printf("\n");
}

void salvarDynamicStackEmArquivo(DynamicStack* s, const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    for (int i = s->tamanho - 1; i >= 0; i--) {
        fprintf(fp, "%d\n", s->itens[i].valor);
    }
    fclose(fp);
}