#include <iostream>
#include <vector>
#include <chrono>
#include "static_list.hpp"
#include "file_reader.hpp"
#include "tim_sort.hpp"
#include <iomanip>

#define INPUT_FILE "../Samples/sample_1000000.csv"
#define OUTPUT_FILE "./ordened/dynamic_stack/sample_1000000.csv"
#define TAMANHO 1000000

int main()
{
    DynamicStack pilha;

    std::vector<int> arr;
    if (!FileReader::carregarCSV(INPUT_FILE, arr, TAMANHO))
    {
        std::cerr << "Erro ao carregar o arquivo " << INPUT_FILE << std::endl;
        return 1;
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < TAMANHO; i++)
    {
        pilha.empilhar(Registro{arr[i]});
    }

    ordenarDynamicStack(&pilha);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
    std::cout << "Tempo de execução: " << std::fixed << std::setprecision(6) << duration.count() << " segundos" << std::endl;

    pilha.salvarEmArquivo(OUTPUT_FILE);
    return 0;
}
