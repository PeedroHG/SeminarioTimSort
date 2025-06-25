import csv
import time
from array_based import *
from linked_based import *
from timsort import *

tam = 100

def ler_timestamps_csv(nome_arquivo):
    timestamps = []
    with open(nome_arquivo, 'r', newline='', encoding='utf-8') as f:
        leitor = csv.reader(f)
        next(leitor)  # Ignora o cabeçalho
        for linha in leitor:
            if linha:
                timestamps.append(int(linha[0]))  # Supondo que o timestamp está na primeira coluna
    return timestamps

# le o csv
timestamps = ler_timestamps_csv('../SamplesPartialOrdened/sample_'+ str(tam) + '.csv')

array_list = ArrayList()

# COMEÇA A CONTAR O TEMPO AQUI
start = time.perf_counter()

# passa pra estrutura
for t in timestamps:
    array_list.append(t)

# transforma em array normal
normal_list = array_list.to_list()

# ordena
timsort(normal_list)

# limpa a estrutura e copia ordenado
array_list.clear()
for t in normal_list:
    array_list.append(t)

# TERMINA DE CONTAR O TEMPO AQUI
end = time.perf_counter()

# calcula o tempo
tempo_execucao = end - start
print(f"Tempo de execução: {tempo_execucao:.6f} segundos")

# salva o resultado num CSV
array_list.save_to_csv('./ordened/dynamic_stack/sample_' + str(tam) + '.csv')
