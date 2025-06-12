#ifndef TIM_SORT_H
#define TIM_SORT_H

#include "node.h"
#include "static_list.h"
#include "static_stack.h"
#include "static_queue.h"

#include "dynamic_list.h"
#include "dynamic_stack.h"
#include "dynamic_queue.h"

void timsort(int *arr, int n);

void ordenarStaticList(StaticList *l);
void ordenarStaticStack(StaticStack *s);
void ordenarStaticQueue(StaticQueue *q);

void ordenarDynamicList(DynamicList *l);
void ordenarDynamicStack(DynamicStack *s);
void ordenarDynamicQueue(DynamicQueue *q);
#endif
