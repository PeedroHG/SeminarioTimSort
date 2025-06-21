#ifndef DYNAMIC_LIST_HPP
#define DYNAMIC_LIST_HPP

#include <cstdio>
#include "node.hpp" // aqui já está a definição de struct No

class DynamicList {
public:
    No* head;
    No* tail;
    int size;

public:
    DynamicList() : head(nullptr), tail(nullptr), size(0) {}

    ~DynamicList() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            No* temp = head;
            head = head->prox;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    int getSize() const {
        return size;
    }

    bool inserirFim(const Registro& valor) {
        No* novo = new No();
        novo->valor = valor;
        
        if (!novo) return false;

        if (tail == nullptr) {
            head = novo;
            tail = novo;
        } else {
            tail->prox = novo;
            tail = novo;
        }
        ++size;
        return true;
    }

    bool removerInicio(Registro& valor) {
        if (head == nullptr) return false;

        valor = head->valor;
        No* temp = head;
        head = head->prox;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        --size;
        return true;
    }

    void imprimir() const {
        for (No* current = head; current != nullptr; current = current->prox) {
            printf("%d ", current->valor.valor);
        }
        printf("\n");
    }

    void salvarEmArquivo(const char* nomeArquivo) const {
        FILE* arquivo = std::fopen(nomeArquivo, "w");
        if (!arquivo) {
            perror("Erro ao abrir o arquivo para escrita");
            return;
        }
        for (No* current = head; current != nullptr; current = current->prox) {
            std::fprintf(arquivo, "%d\n", current->valor.valor);
        }
        std::fclose(arquivo);
    }
};

#endif // DYNAMIC_LIST_HPP
