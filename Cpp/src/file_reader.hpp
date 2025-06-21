#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace FileReader {

    // Retorna true se carregar com sucesso, false caso contrário
    inline bool carregarCSV(const std::string& filename, std::vector<int>& arr, size_t n) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        std::string linha;
        // Ignora cabeçalho
        std::getline(file, linha);

        arr.clear();
        arr.reserve(n);

        for (size_t i = 0; i < n; i++) {
            if (!std::getline(file, linha)) break;
            try {
                int valor = std::stoi(linha);
                arr.push_back(valor);
            } catch (...) {
                return false; // erro na conversão
            }
        }

        return true;
    }

}

#endif
