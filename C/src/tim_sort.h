#ifndef TIM_SORT_H
#define TIM_SORT_H

#include "static_list.h"
#include "static_stack.h"
#include "static_queue.h"

void timsort(int *arr, int n);

void ordenarStaticList(StaticList *l);
void ordenarStaticStack(StaticStack *s);
void ordenarStaticQueue(StaticQueue *q);

#endif
