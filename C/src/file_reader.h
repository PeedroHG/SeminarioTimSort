#ifndef FILE_READER_H
#define FILE_READER_H

#include "static_list.h"
#include "static_queue.h"
#include "static_stack.h"

#include "dynamic_list.h"
#include "dynamic_queue.h"
#include "dynamic_stack.h"

int carregarCSVparaStaticList(const char *filename, StaticList *lista);
int carregarCSVparaStaticQueue(const char *filename, StaticQueue *fila);
int carregarCSVparaStaticStack(const char *filename, StaticStack *pilha);

int carregarCSVparaDynamicList(const char *filename, DynamicList *lista);
int carregarCSVparaDynamicQueue(const char *filename, DynamicQueue *fila);
int carregarCSVparaDynamicStack(const char *filename, DynamicStack *pilha);
#endif
