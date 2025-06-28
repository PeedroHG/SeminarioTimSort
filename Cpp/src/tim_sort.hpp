#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "node.hpp"
#include "static_list.hpp"
#include "static_stack.hpp"
#include "static_queue.hpp"
#include "dynamic_list.hpp"
#include "dynamic_stack.hpp"
#include "dynamic_queue.hpp"

static const int MIN_MERGE = 32;

// Funções auxiliares
inline int calcMinRun(int n) {
    int r = 0;
    while (n >= MIN_MERGE) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

inline void insertionSort(int arr[], int left, int right) {
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

inline void reverse(int arr[], int left, int right) {
    while (left < right) {
        std::swap(arr[left++], arr[right--]);
    }
}

inline void merge(int arr[], int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int* L = new int[len1];
    int* R = new int[len2];

    for (int i = 0; i < len1; i++) L[i] = arr[left + i];
    for (int i = 0; i < len2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < len1) arr[k++] = L[i++];
    while (j < len2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

inline void mergeAt(int arr[], std::vector<std::pair<int, int>>& runs, int i) {
    auto [start1, len1] = runs[i];
    auto [start2, len2] = runs[i + 1];
    merge(arr, start1, start1 + len1 - 1, start2 + len2 - 1);
    runs[i] = {start1, len1 + len2};
    runs.erase(runs.begin() + i + 1);
}

inline void mergeCollapse(int arr[], std::vector<std::pair<int, int>>& runs) {
    while (runs.size() > 1) {
        int n = runs.size();
        auto& B = runs[n - 2];
        auto& C = runs[n - 1];
        auto& A = (n >= 3) ? runs[n - 3] : B;

        bool cond1 = (n >= 3 && A.second <= B.second + C.second);
        bool cond2 = (B.second <= C.second);

        if (cond1) {
            if (A.second < C.second)
                mergeAt(arr, runs, n - 3);
            else
                mergeAt(arr, runs, n - 2);
        } else if (cond2) {
            mergeAt(arr, runs, n - 2);
        } else {
            break;
        }
    }
}

inline void mergeForceCollapse(int arr[], std::vector<std::pair<int, int>>& runs) {
    while (runs.size() > 1) {
        mergeAt(arr, runs, runs.size() - 2);
    }
}

// Timsort completo
inline void timsort(int* arr, int n) {
    int minRun = calcMinRun(n);
    std::vector<std::pair<int, int>> runs;

    int i = 0;
    while (i < n) {
        int runStart = i;
        int runEnd = i + 1;

        if (runEnd == n) {
            runEnd = n;
        } else if (arr[runStart] <= arr[runEnd]) {
            while (runEnd < n - 1 && arr[runEnd] <= arr[runEnd + 1])
                runEnd++;
        } else {
            while (runEnd < n - 1 && arr[runEnd] > arr[runEnd + 1])
                runEnd++;
            reverse(arr, runStart, runEnd);
        }

        int runLen = runEnd - runStart + 1;
        if (runLen < minRun) {
            int forcedEnd = std::min(n - 1, runStart + minRun - 1);
            insertionSort(arr, runStart, forcedEnd);
            runEnd = forcedEnd;
            runLen = runEnd - runStart + 1;
        }

        runs.push_back({runStart, runLen});
        mergeCollapse(arr, runs);
        i = runEnd + 1;
    }

    mergeForceCollapse(arr, runs);
}

// ==============================
// ORDENAÇÃO DAS ESTRUTURAS
// ==============================

// Estruturas estáticas
inline void ordenarStaticList(StaticList* l) {
    if (l->tamanho > 1) {
        int* arr = new int[l->tamanho];
        for (int i = 0; i < l->tamanho; i++)
            arr[i] = l->itens[i].valor;
        timsort(arr, l->tamanho);
        for (int i = 0; i < l->tamanho; i++)
            l->itens[i].valor = arr[i];
        delete[] arr;
    }
}

inline void ordenarStaticQueue(StaticQueue* q) {
    if (q->tamanho > 1) {
        int* arr = new int[q->tamanho];
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

inline void ordenarStaticStack(StaticStack* s) {
    if (s->topo > 0) {
        int* arr = new int[s->topo + 1];
        for (int i = 0; i <= s->topo; i++)
            arr[i] = s->dados[i].valor;
        timsort(arr, s->topo + 1);
        for (int i = 0; i <= s->topo; i++)
            s->dados[i].valor = arr[i];
        delete[] arr;
    }
}

// Estruturas dinâmicas
inline void ordenarDynamicList(DynamicList* l) {
    if (l->size > 1) {
        int* arr = new int[l->size];
        No* aux = l->head;
        for (int i = 0; i < l->size; i++, aux = aux->prox)
            arr[i] = aux->valor.valor;
        timsort(arr, l->size);
        aux = l->head;
        for (int i = 0; i < l->size; i++, aux = aux->prox)
            aux->valor.valor = arr[i];
        delete[] arr;
    }
}

inline void ordenarDynamicStack(DynamicStack* s) {
    if (s->size > 1) {
        int* arr = new int[s->size];
        No* atual = s->topo;
        for (int i = 0; i < s->size; i++, atual = atual->prox)
            arr[i] = atual->valor.valor;
        timsort(arr, s->size);
        atual = s->topo;
        for (int i = 0; i < s->size; i++, atual = atual->prox)
            atual->valor.valor = arr[i];
        delete[] arr;
    }
}

inline void ordenarDynamicQueue(DynamicQueue* q) {
    if (q->size > 1) {
        int* arr = new int[q->size];
        No* atual = q->head;
        for (int i = 0; i < q->size; i++, atual = atual->prox)
            arr[i] = atual->valor.valor;
        timsort(arr, q->size);
        atual = q->head;
        for (int i = 0; i < q->size; i++, atual = atual->prox)
            atual->valor.valor = arr[i];
        delete[] arr;
    }
}
