#include <stdio.h>
#include <stdlib.h>
#include "dynamic_list.h"

void inicializarDynamicList(DynamicList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int inserirFimDynamicList(DynamicList* list, Registro valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return 0; // falha na alocação de memória

    novo->valor = valor;
    novo->prox = NULL;

    if (list->tail == NULL) {
        list->head = novo;
        list->tail = novo;
    } else {
        list->tail->prox = novo;
        list->tail = novo;
    }

    list->size++;
    return 1;
}

int removerInicioDynamicList(DynamicList* list, Registro* valor) {
    if (list->head == NULL) return 0; // lista vazia

    *valor = list->head->valor;
    No* temp = list->head;
    list->head = list->head->prox;

    if (list->head == NULL) {
        list->tail = NULL;
    }

    free(temp);
    list->size--;
    return 1;
}

void imprimirDynamicList(DynamicList* list) {
    No* current = list->head;
    while (current != NULL) {
        printf("%d ", current->valor.valor);
        current = current->prox;
    }
    printf("\n");
}

void salvarDynamicListEmArquivo(DynamicList* list, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (No* current = list->head; current != NULL; current = current->prox) {
        fprintf(arquivo, "%d \n", current->valor.valor);
    }

    fclose(arquivo);
}