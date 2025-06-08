#include <stdio.h>
#include "static_stack.h"

void inicializarStaticStack(StaticStack *s) {
    s->topo = -1;
}

int pilhaVazia(StaticStack *s) {
    return s->topo == -1;
}

int pilhaCheia(StaticStack *s) {
    return s->topo == MAXTAM - 1;
}

int empilhar(StaticStack *s, Registro r) {
    if (pilhaCheia(s)) return 0;

    s->dados[++s->topo] = r;
    return 1;
}

int desempilhar(StaticStack *s, Registro *r) {
    if (pilhaVazia(s)) return 0;

    *r = s->dados[s->topo--];
    return 1;
}

void imprimirStaticStack(StaticStack *s) {
    if (pilhaVazia(s)) {
        printf("Pilha vazia.\n");
        return;
    }

    for (int i = s->topo; i >= 0; i--) {
        printf("%d ", s->dados[i].valor);
    }
    printf("\n");
}

void salvarStaticStackEmArquivo(StaticStack *s, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (int i = s->topo; i >= 0; i--) {
        fprintf(arquivo, "%d\n", s->dados[i].valor);
    }

    fclose(arquivo);
}