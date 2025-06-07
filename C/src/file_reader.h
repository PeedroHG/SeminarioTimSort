#ifndef FILE_READER_H
#define FILE_READER_H

#include "static_list.h"
#include "static_queue.h"
#include "static_stack.h"

int carregarCSVparaStaticList(const char *filename, StaticList *lista);
int carregarCSVparaStaticQueue(const char *filename, StaticQueue *fila);
int carregarCSVparaStaticStack(const char *filename, StaticStack *pilha);

#endif
