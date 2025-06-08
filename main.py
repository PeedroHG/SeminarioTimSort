import pandas as pd
import random

# Nome do arquivo de entrada
INPUT_CSV = "ratings.csv"

# Tamanhos das amostras desejadas
SAMPLE_SIZES = [100, 1000, 10000, 100000, 1000000]

# Nome base para os arquivos de saída
OUTPUT_PREFIX = "sample_"

def gerar_amostras(csv_path, tamanhos):
    # Lê o CSV inteiro (se for muito grande, isso pode ser adaptado para leitura por chunks)
    df = pd.read_csv(csv_path)

    # Garante que a coluna timestamp é do tipo int
    df['timestamp'] = df['timestamp'].astype(int)

    total_registros = len(df)
    print(f"Total de registros no CSV: {total_registros}")

    for tamanho in tamanhos:
        if tamanho > total_registros:
            print(f"[Aviso] Amostra de {tamanho} não pôde ser gerada. Total de registros: {total_registros}")
            continue
        
        amostra = df.sample(n=tamanho, random_state=42)[['timestamp']]

        nome_arquivo = f"{OUTPUT_PREFIX}{tamanho}.csv"
        amostra.to_csv(nome_arquivo, index=False)
        print(f"Amostra com {tamanho} registros salva em: {nome_arquivo}")

# Executa a função
if __name__ == "__main__":
    gerar_amostras(INPUT_CSV, SAMPLE_SIZES)
