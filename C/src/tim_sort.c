#include <stdio.h>
#include <stdlib.h>
#include "tim_sort.h"

// Parâmetro para tamanho mínimo de "runs"
#define RUN 32

static void insertionSort(int arr[], int left, int right)
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

static void merge(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1, len2 = r - m;
    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < len1)
        arr[k++] = left[i++];
    while (j < len2)
        arr[k++] = right[j++];

    free(left);
    free(right);
}

void timsort(int *arr, int n)
{
    // Ordena pequenos subarrays com insertion sort
    for (int i = 0; i < n; i += RUN)
    {
        int right = (i + RUN - 1) < (n - 1) ? (i + RUN - 1) : (n - 1);
        insertionSort(arr, i, right);
    }

    // Mescla os subarrays ordenados em blocos maiores
    for (int size = RUN; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = ((left + 2 * size - 1) < (n - 1)) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

void ordenarStaticList(StaticList *l)
{
    if (l->tamanho > 1)
    {
        // Ordena o vetor pelo campo valor
        // Assumindo que Registro tem campo int valor
        int *arr = (int *)malloc(l->tamanho * sizeof(int));
        for (int i = 0; i < l->tamanho; i++)
            arr[i] = l->itens[i].valor;

        timsort(arr, l->tamanho);

        for (int i = 0; i < l->tamanho; i++)
            l->itens[i].valor = arr[i];

        free(arr);
    }
}

void ordenarStaticQueue(StaticQueue *q)
{
    if (q->tamanho > 1)
    {
        int *arr = (int *)malloc(q->tamanho * sizeof(int));
        if (!arr)
            return;

        int idx = q->frente;
        for (int i = 0; i < q->tamanho; i++)
        {
            arr[i] = q->dados[idx].valor;
            idx = (idx + 1) % MAXTAM;
        }

        timsort(arr, q->tamanho);

        idx = q->frente;
        for (int i = 0; i < q->tamanho; i++)
        {
            q->dados[idx].valor = arr[i];
            idx = (idx + 1) % MAXTAM;
        }

        free(arr);
    }
}

void ordenarStaticStack(StaticStack *s)
{
    if (s->topo > 0)
    {
        int *arr = (int *)malloc((s->topo + 1) * sizeof(int));
        if (!arr)
            return;

        for (int i = 0; i <= s->topo; i++)
        {
            arr[i] = s->dados[i].valor;
        }

        timsort(arr, s->topo + 1);

        for (int i = 0; i <= s->topo; i++)
        {
            s->dados[i].valor = arr[i];
        }

        free(arr);
    }
}

void ordenarDynamicList(DynamicList *l)
{
    if (l->size > 1)
    {
        int *arr = (int *)malloc(l->size * sizeof(int));
        if (!arr)
            return;

        for (int i = 0; i < l->size; i++)
        {
            arr[i] = l->head->valor.valor;
            l->head = l->head->prox;
        }

        timsort(arr, l->size);

        No *atual = l->head;
        for (int i = 0; i < l->size && atual != NULL; i++)
        {
            atual->valor.valor = arr[i];
            atual = atual->prox;
        }

        free(arr);
    }
}

void ordenarDynamicStack(DynamicStack *s)
{
    if (s->size > 1)
    {
        int *arr = (int *)malloc(s->size * sizeof(int));
        if (!arr)
            return;

        No *atual = s->topo;
        for (int i = 0; i < s->size && atual != NULL; i++)
        {
            arr[i] = atual->valor.valor;
            atual = atual->prox;
        }

        timsort(arr, s->size);

        atual = s->topo;
        for (int i = 0; i < s->size && atual != NULL; i++)
        {
            atual->valor.valor = arr[i];
            atual = atual->prox;
        }

        free(arr);
    }
}

void ordenarDynamicQueue(DynamicQueue *q)
{
    if (q->size > 1)
    {
        int *arr = (int *)malloc(q->size * sizeof(int));
        if (!arr)
            return;

        No *atual = q->head;
        for (int i = 0; i < q->size && atual != NULL; i++)
        {
            arr[i] = atual->valor.valor;
            atual = atual->prox;
        }

        timsort(arr, q->size);

        atual = q->head;
        for (int i = 0; i < q->size && atual != NULL; i++)
        {
            atual->valor.valor = arr[i];
            atual = atual->prox;
        }

        free(arr);
    }
}