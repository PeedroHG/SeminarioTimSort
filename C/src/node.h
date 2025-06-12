#ifndef NODE_H
#define NODE_H
#include "registro.h"

typedef struct No {
    Registro valor;
    struct No* prox;
} No;

#endif
