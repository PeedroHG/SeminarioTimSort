#ifndef STATIC_LIST_H
#define STATIC_LIST_H
#include "registro.h"

#define MAXTAM 1000000

typedef struct {
    Registro itens[MAXTAM];
    int tamanho;
} StaticList;

void inicializarStaticList(StaticList *l);
int inserirFinalStatic(StaticList *l, Registro r);
int removerValorStatic(StaticList *l, int valor);
void imprimirStaticList(StaticList *l);
void salvarStaticListEmArquivo(StaticList *l, const char *nomeArquivo);

#endif
