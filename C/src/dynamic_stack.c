#include <stdio.h>
#include <stdlib.h>
#include "dynamic_stack.h"

void inicializarDynamicStack(DynamicStack *stack) {
    stack->topo = NULL;
    stack->size = 0;
}

int empilharDynamicStack(DynamicStack *stack, Registro valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) return 0;

    novo->valor = valor;
    novo->prox = stack->topo;
    stack->topo = novo;
    stack->size++;
    return 1;
}

int desempilharDynamicStack(DynamicStack *stack, Registro *valor) {
    if (pilhaVazia(stack)) return 0;

    No *remover = stack->topo;
    *valor = remover->valor;
    stack->topo = remover->prox;
    free(remover);
    stack->size--;
    return 1;
}

int pilhaVaziaDynamicStack(DynamicStack *stack) {
    return stack->size == 0;
}

void imprimirDynamicStack(DynamicStack *stack) {
    No *atual = stack->topo;
    while (atual != NULL) {
        printf("%d ", atual->valor.valor);
        atual = atual->prox;
    }
    printf("\n");
}

void salvarDynamicStackEmArquivo(DynamicStack *stack, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo para escrita");
        return;
    }

    No *atual = stack->topo;
    while (atual != NULL) {
        fprintf(arquivo, "%d\n", atual->valor.valor);
        atual = atual->prox;
    }

    fclose(arquivo);
}
