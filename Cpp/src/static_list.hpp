#ifndef STATIC_LIST_HPP
#define STATIC_LIST_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "registro.hpp"

class StaticList {
public:
    static constexpr int MAXTAM = 1000000;
    Registro itens[MAXTAM];
    int tamanho;

public:
    StaticList() : tamanho(0) {}

    bool inserirFinal(const Registro& r) {
        if (tamanho >= MAXTAM) return false;
        itens[tamanho++] = r;
        return true;
    }

    bool removerValor(int valor) {
        for (int i = 0; i < tamanho; i++) {
            if (itens[i].valor == valor) {
                for (int j = i; j < tamanho - 1; j++) {
                    itens[j] = itens[j + 1];
                }
                tamanho--;
                return true;
            }
        }
        return false;
    }

    void imprimir() const {
        for (int i = 0; i < tamanho; i++) {
            std::cout << itens[i].valor << " ";
        }
        std::cout << "\n";
    }

    void salvarEmArquivo(const std::string& nomeArquivo) const {
        std::ofstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            throw std::runtime_error("Erro ao abrir arquivo para escrita: " + nomeArquivo);
        }
        for (int i = 0; i < tamanho; i++) {
            arquivo << itens[i].valor << "\n";
        }
    }

    int getTamanho() const { return tamanho; }

    // Opcional: acessar item por índice (leitura apenas)
    const Registro& operator[](int index) const {
        if (index < 0 || index >= tamanho) throw std::out_of_range("Índice fora do limite");
        return itens[index];
    }
};

#endif
