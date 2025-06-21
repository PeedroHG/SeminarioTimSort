#ifndef DYNAMIC_QUEUE_HPP
#define DYNAMIC_QUEUE_HPP

#include <cstdio>
#include "node.hpp"

class DynamicQueue
{
public:
    No *head;
    No *tail;
    int size;

public:
    DynamicQueue() : head(nullptr), tail(nullptr), size(0) {}

    ~DynamicQueue()
    {
        clear();
    }

    void clear()
    {
        while (head != nullptr)
        {
            No *temp = head;
            head = head->prox;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    int getSize() const
    {
        return size;
    }

    bool enfileirar(const Registro &valor)
    {
        No *novo = new No();
        novo->valor = valor;
        
        if (!novo)
            return false;

        if (tail == nullptr)
        {
            head = tail = novo;
        }
        else
        {
            tail->prox = novo;
            tail = novo;
        }

        ++size;
        return true;
    }

    bool desenfileirar(Registro &valor)
    {
        if (isEmpty())
            return false;

        No *remover = head;
        valor = remover->valor;
        head = head->prox;

        if (head == nullptr)
        {
            tail = nullptr;
        }

        delete remover;
        --size;
        return true;
    }

    void imprimir() const
    {
        for (No *atual = head; atual != nullptr; atual = atual->prox)
        {
            printf("%d ", atual->valor.valor);
        }
        printf("\n");
    }

    void salvarEmArquivo(const char *nomeArquivo) const
    {
        FILE *arquivo = std::fopen(nomeArquivo, "w");
        if (!arquivo)
        {
            perror("Erro ao abrir arquivo para escrita");
            return;
        }

        for (No *atual = head; atual != nullptr; atual = atual->prox)
        {
            std::fprintf(arquivo, "%d\n", atual->valor.valor);
        }

        std::fclose(arquivo);
    }
};

#endif // DYNAMIC_QUEUE_HPP
