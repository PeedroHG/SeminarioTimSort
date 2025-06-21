#ifndef DYNAMIC_STACK_HPP
#define DYNAMIC_STACK_HPP

#include <cstdio>
#include "node.hpp"

class DynamicStack
{
public:
    No *topo;
    int size;

public:
    DynamicStack() : topo(nullptr), size(0) {}

    ~DynamicStack()
    {
        clear();
    }

    void clear()
    {
        while (topo)
        {
            No *temp = topo;
            topo = topo->prox;
            delete temp;
        }
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

    bool empilhar(const Registro &valor)
    {
        No *novo = new No();
        novo->valor = valor;
        if (!novo)
            return false;
        novo->prox = topo;
        topo = novo;
        ++size;
        return true;
    }

    bool desempilhar(Registro &valor)
    {
        if (isEmpty())
            return false;

        No *remover = topo;
        valor = remover->valor;
        topo = remover->prox;
        delete remover;
        --size;
        return true;
    }

    void imprimir() const
    {
        No *atual = topo;
        while (atual)
        {
            printf("%d ", atual->valor.valor);
            atual = atual->prox;
        }
        printf("\n");
    }

    void salvarEmArquivo(const char *nomeArquivo) const
    {
        FILE *arquivo = std::fopen(nomeArquivo, "w");
        if (!arquivo)
        {
            perror("Erro ao abrir o arquivo para escrita");
            return;
        }

        No *atual = topo;
        while (atual)
        {
            std::fprintf(arquivo, "%d\n", atual->valor.valor);
            atual = atual->prox;
        }

        std::fclose(arquivo);
    }
};

#endif // DYNAMIC_STACK_HPP
