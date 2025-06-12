#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include "node.h"

typedef struct {
    No *topo;
    int size;
} DynamicStack;

void inicializarDynamicStack(DynamicStack *stack);
int empilharDynamicStack(DynamicStack *stack, Registro valor);
int desempilharDynamicStack(DynamicStack *stack, Registro *valor);
int pilhaVaziaDynamicStack(DynamicStack *stack);
void imprimirDynamicStack(DynamicStack *stack);
void salvarDynamicStackEmArquivo(DynamicStack *stack, const char *nomeArquivo);
#endif
