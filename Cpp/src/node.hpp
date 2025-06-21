#ifndef NODE_H
#define NODE_H

#include "registro.hpp"

struct No {
    Registro valor;
    No* prox;
};

#endif
