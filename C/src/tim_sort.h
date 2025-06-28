#ifndef TIM_SORT_H
#define TIM_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "static_list.h"
#include "static_stack.h"
#include "static_queue.h"
#include "dynamic_list.h"
#include "dynamic_stack.h"
#include "dynamic_queue.h"

#define MIN_MERGE 32

static inline int calcMinRun(int n) {
    int r = 0;
    while (n >= MIN_MERGE) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

static inline void insertionSort(int* arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

static inline void reverse(int* arr, int left, int right) {
    while (left < right) {
        int tmp = arr[left];
        arr[left++] = arr[right];
        arr[right--] = tmp;
    }
}

static inline void merge(int* arr, int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int* L = (int*)malloc(len1 * sizeof(int));
    int* R = (int*)malloc(len2 * sizeof(int));

    for (int i = 0; i < len1; i++) L[i] = arr[left + i];
    for (int i = 0; i < len2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < len1) arr[k++] = L[i++];
    while (j < len2) arr[k++] = R[j++];

    free(L);
    free(R);
}

typedef struct {
    int start;
    int length;
} Run;

static inline void mergeAt(int* arr, Run* runs, int* count, int i) {
    int start1 = runs[i].start;
    int len1 = runs[i].length;
    int start2 = runs[i + 1].start;
    int len2 = runs[i + 1].length;
    merge(arr, start1, start2 - 1, start2 + len2 - 1);
    runs[i].length += len2;
    for (int j = i + 1; j < (*count) - 1; j++) {
        runs[j] = runs[j + 1];
    }
    (*count)--;
}

static inline void mergeCollapse(int* arr, Run* runs, int* count) {
    while (*count > 1) {
        int n = *count;
        Run* A = (n >= 3) ? &runs[n - 3] : NULL;
        Run* B = &runs[n - 2];
        Run* C = &runs[n - 1];

        bool cond1 = (n >= 3 && A->length <= B->length + C->length);
        bool cond2 = (B->length <= C->length);

        if (cond1) {
            if (A->length < C->length)
                mergeAt(arr, runs, count, n - 3);
            else
                mergeAt(arr, runs, count, n - 2);
        } else if (cond2) {
            mergeAt(arr, runs, count, n - 2);
        } else {
            break;
        }
    }
}

static inline void mergeForceCollapse(int* arr, Run* runs, int* count) {
    while (*count > 1) {
        mergeAt(arr, runs, count, (*count) - 2);
    }
}

static inline void timsort(int* arr, int n) {
    int minRun = calcMinRun(n);
    Run* runs = (Run*)malloc(n * sizeof(Run));
    int count = 0;

    int i = 0;
    while (i < n) {
        int runStart = i;
        int runEnd = i + 1;

        if (runEnd == n) {
            runEnd = n;
        } else if (arr[runStart] <= arr[runEnd]) {
            while (runEnd < n - 1 && arr[runEnd] <= arr[runEnd + 1]) runEnd++;
        } else {
            while (runEnd < n - 1 && arr[runEnd] > arr[runEnd + 1]) runEnd++;
            reverse(arr, runStart, runEnd);
        }

        int runLen = runEnd - runStart + 1;
        if (runLen < minRun) {
            int forcedEnd = (runStart + minRun - 1 < n - 1) ? runStart + minRun - 1 : n - 1;
            insertionSort(arr, runStart, forcedEnd);
            runEnd = forcedEnd;
            runLen = runEnd - runStart + 1;
        }

        runs[count++] = (Run){runStart, runLen};
        mergeCollapse(arr, runs, &count);
        i = runEnd + 1;
    }

    mergeForceCollapse(arr, runs, &count);
    free(runs);
}

// Funções ordenarX com Timsort completo
static inline void ordenarStaticList(StaticList *l) {
    if (l->tamanho > 1) {
        int *arr = (int*)malloc(l->tamanho * sizeof(int));
        for (int i = 0; i < l->tamanho; i++)
            arr[i] = l->itens[i].valor;
        timsort(arr, l->tamanho);
        for (int i = 0; i < l->tamanho; i++)
            l->itens[i].valor = arr[i];
        free(arr);
    }
}

static inline void ordenarStaticQueue(StaticQueue *q) {
    if (q->tamanho > 1) {
        int *arr = (int*)malloc(q->tamanho * sizeof(int));
        int idx = q->frente;
        for (int i = 0; i < q->tamanho; i++, idx = (idx + 1) % MAXTAM)
            arr[i] = q->dados[idx].valor;
        timsort(arr, q->tamanho);
        idx = q->frente;
        for (int i = 0; i < q->tamanho; i++, idx = (idx + 1) % MAXTAM)
            q->dados[idx].valor = arr[i];
        free(arr);
    }
}

static inline void ordenarStaticStack(StaticStack *s) {
    if (s->topo > 0) {
        int *arr = (int*)malloc((s->topo + 1) * sizeof(int));
        for (int i = 0; i <= s->topo; i++)
            arr[i] = s->dados[i].valor;
        timsort(arr, s->topo + 1);
        for (int i = 0; i <= s->topo; i++)
            s->dados[i].valor = arr[i];
        free(arr);
    }
}

static inline void ordenarDynamicList(DynamicList *l) {
    if (l->size > 1) {
        int *arr = (int*)malloc(l->size * sizeof(int));
        No *aux = l->head;
        for (int i = 0; i < l->size && aux != NULL; i++, aux = aux->prox)
            arr[i] = aux->valor.valor;
        timsort(arr, l->size);
        aux = l->head;
        for (int i = 0; i < l->size && aux != NULL; i++, aux = aux->prox)
            aux->valor.valor = arr[i];
        free(arr);
    }
}

static inline void ordenarDynamicStack(DynamicStack *s) {
    if (s->size > 1) {
        int *arr = (int*)malloc(s->size * sizeof(int));
        No *atual = s->topo;
        for (int i = 0; i < s->size && atual != NULL; i++, atual = atual->prox)
            arr[i] = atual->valor.valor;
        timsort(arr, s->size);
        atual = s->topo;
        for (int i = 0; i < s->size && atual != NULL; i++, atual = atual->prox)
            atual->valor.valor = arr[i];
        free(arr);
    }
}

static inline void ordenarDynamicQueue(DynamicQueue *q) {
    if (q->size > 1) {
        int *arr = (int*)malloc(q->size * sizeof(int));
        No *atual = q->head;
        for (int i = 0; i < q->size && atual != NULL; i++, atual = atual->prox)
            arr[i] = atual->valor.valor;
        timsort(arr, q->size);
        atual = q->head;
        for (int i = 0; i < q->size && atual != NULL; i++, atual = atual->prox)
            atual->valor.valor = arr[i];
        free(arr);
    }
}

#endif