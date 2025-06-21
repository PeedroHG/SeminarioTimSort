#ifndef STATIC_STACK_HPP
#define STATIC_STACK_HPP

#include <cstdio>
#include "registro.hpp"

class StaticStack {
public:
    static constexpr int MAXTAM = 1000000;
    Registro dados[MAXTAM];
    int topo;

    StaticStack() : topo(-1) {}

    bool pilhaVazia() const {
        return topo == -1;
    }

    bool pilhaCheia() const {
        return topo == MAXTAM - 1;
    }

    bool empilhar(const Registro& r) {
        if (pilhaCheia()) return false;
        dados[++topo] = r;
        return true;
    }

    bool desempilhar(Registro& r) {
        if (pilhaVazia()) return false;
        r = dados[topo--];
        return true;
    }

    void imprimir() const {
        if (pilhaVazia()) {
            printf("Pilha vazia.\n");
            return;
        }
        for (int i = topo; i >= 0; i--) {
            printf("%d ", dados[i].valor);
        }
        printf("\n");
    }

    void salvarEmArquivo(const char* nomeArquivo) const {
        FILE* arquivo = std::fopen(nomeArquivo, "w");
        if (!arquivo) {
            perror("Erro ao abrir o arquivo para escrita");
            return;
        }
        for (int i = topo; i >= 0; i--) {
            fprintf(arquivo, "%d\n", dados[i].valor);
        }
        std::fclose(arquivo);
    }
};

#endif // STATIC_STACK_HPP
