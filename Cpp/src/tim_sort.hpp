#pragma once
#include <iostream>
#include "node.hpp"
#include "static_list.hpp"
#include "static_stack.hpp"
#include "static_queue.hpp"
#include "dynamic_list.hpp"
#include "dynamic_stack.hpp"
#include "dynamic_queue.hpp"

static const int RUN = 32;

inline void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

inline void merge(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1, len2 = r - m;
    int *left = new int[len1];
    int *right = new int[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2)
    {
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    }
    while (i < len1)
        arr[k++] = left[i++];
    while (j < len2)
        arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

inline void timsort(int *arr, int n)
{
    for (int i = 0; i < n; i += RUN)
    {
        insertionSort(arr, i, std::min(i + RUN - 1, n - 1));
    }

    for (int size = RUN; size < n; size *= 2)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, n - 1);
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

// Ordenação das Estruturas Estáticas
inline void ordenarStaticList(StaticList *l)
{
    if (l->tamanho > 1)
    {
        int *arr = new int[l->tamanho];
        for (int i = 0; i < l->tamanho; i++)
            arr[i] = l->itens[i].valor;
        timsort(arr, l->tamanho);
        for (int i = 0; i < l->tamanho; i++)
            l->itens[i].valor = arr[i];
        delete[] arr;
    }
}

inline void ordenarStaticQueue(StaticQueue *q)
{
    if (q->tamanho > 1)
    {
        int *arr = new int[q->tamanho];
        int idx = q->frente;
        for (int i = 0; i < q->tamanho; i++, idx = (idx + 1) % StaticQueue::MAXTAM)
            arr[i] = q->dados[idx].valor;
        timsort(arr, q->tamanho);
        idx = q->frente;
        for (int i = 0; i < q->tamanho; i++, idx = (idx + 1) % StaticQueue::MAXTAM)
            q->dados[idx].valor = arr[i];
        delete[] arr;
    }
}

inline void ordenarStaticStack(StaticStack *s)
{
    if (s->topo > 0)
    {
        int *arr = new int[s->topo + 1];
        for (int i = 0; i <= s->topo; i++)
            arr[i] = s->dados[i].valor;
        timsort(arr, s->topo + 1);
        for (int i = 0; i <= s->topo; i++)
            s->dados[i].valor = arr[i];
        delete[] arr;
    }
}

// Ordenação das Estruturas Dinâmicas
inline void ordenarDynamicList(DynamicList *l)
{
    if (l->size > 1)
    {
        int *arr = new int[l->size];
        No *aux = l->head;
        for (int i = 0; i < l->size; i++, aux = aux->prox)
            arr[i] = aux->valor.valor;
        timsort(arr, l->size);
        aux = l->head;
        for (int i = 0; i < l->size; i++, aux = aux->prox)
            aux->valor.valor = arr[i];
        delete[] arr;
    }
}

inline void ordenarDynamicStack(DynamicStack *s)
{
    if (s->size > 1)
    {
        int *arr = new int[s->size];
        No *atual = s->topo;
        for (int i = 0; i < s->size; i++, atual = atual->prox)
            arr[i] = atual->valor.valor;
        timsort(arr, s->size);
        atual = s->topo;
        for (int i = 0; i < s->size; i++, atual = atual->prox)
            atual->valor.valor = arr[i];
        delete[] arr;
    }
}

inline void ordenarDynamicQueue(DynamicQueue *q)
{
    if (q->size > 1)
    {
        int *arr = new int[q->size];
        No *atual = q->head;
        for (int i = 0; i < q->size; i++, atual = atual->prox)
            arr[i] = atual->valor.valor;
        timsort(arr, q->size);
        atual = q->head;
        for (int i = 0; i < q->size; i++, atual = atual->prox)
            atual->valor.valor = arr[i];
        delete[] arr;
    }
}
