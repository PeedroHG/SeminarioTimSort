#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#define MAXTAM 1000000
#include "registro.h"

typedef struct {
    Registro dados[MAXTAM];
    int topo;
} StaticStack;

void inicializarStaticStack(StaticStack *s);
int empilhar(StaticStack *s, Registro r);
int desempilhar(StaticStack *s, Registro *r);
int pilhaVazia(StaticStack *s);
int pilhaCheia(StaticStack *s);
void imprimirStaticStack(StaticStack *s);
void salvarStaticStackEmArquivo(StaticStack *s, const char *nomeArquivo);

#endif
