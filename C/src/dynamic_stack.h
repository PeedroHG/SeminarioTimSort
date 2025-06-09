#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include "registro.h"
#include <stdlib.h>

typedef struct {
    Registro* itens;
    int tamanho;
    int capacidade;
} DynamicStack;

void inicializarDynamicStack(DynamicStack* s);
int pushDynamicStack(DynamicStack* s, Registro r);
int popDynamicStack(DynamicStack* s, Registro* r);
void imprimirDynamicStack(DynamicStack* s);
void salvarDynamicStackEmArquivo(DynamicStack* s, const char *nomeArquivo);

#endif