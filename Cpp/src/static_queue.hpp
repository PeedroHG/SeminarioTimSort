#ifndef STATIC_QUEUE_HPP
#define STATIC_QUEUE_HPP

#include <iostream>
#include <fstream>
#include "registro.hpp"  // Certifique-se que o "registro.hpp" define struct Registro { int valor; };
                         // Ou ajuste conforme necessário.

class StaticQueue {
public:
    static const int MAXTAM = 1000000;
    Registro dados[MAXTAM];
    int frente;
    int tras;
    int tamanho;

public:
    StaticQueue() {
        frente = 0;
        tras = -1;
        tamanho = 0;
    }

    bool filaVazia() const {
        return tamanho == 0;
    }

    bool filaCheia() const {
        return tamanho == MAXTAM;
    }

    bool enfileirar(const Registro &r) {
        if (filaCheia()) return false;
        tras = (tras + 1) % MAXTAM;
        dados[tras] = r;
        tamanho++;
        return true;
    }

    bool desenfileirar(Registro &r) {
        if (filaVazia()) return false;
        r = dados[frente];
        frente = (frente + 1) % MAXTAM;
        tamanho--;
        return true;
    }

    void imprimir() const {
        if (filaVazia()) {
            std::cout << "Fila vazia.\n";
            return;
        }
        int i = frente;
        for (int count = 0; count < tamanho; count++) {
            std::cout << dados[i].valor << " ";
            i = (i + 1) % MAXTAM;
        }
        std::cout << std::endl;
    }

    void salvarEmArquivo(const std::string &nomeArquivo) const {
        std::ofstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo para escrita\n";
            return;
        }
        int i = frente;
        for (int count = 0; count < tamanho; count++) {
            arquivo << dados[i].valor << '\n';
            i = (i + 1) % MAXTAM;
        }
    }
};

#endif // STATIC_QUEUE_HPP
