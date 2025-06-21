import csv

def gerar_amostras_timestamp(arquivo_entrada):
    tamanhos = [100, 1000, 10000, 100000, 1000000]
    arquivos_saida = {}
    escritores = {}
    contador = 0

    # Abrir todos os arquivos de saída
    for tamanho in tamanhos:
        f = open(f"sample_{tamanho}.csv", 'w', newline='', encoding='utf-8')
        arquivos_saida[tamanho] = f
        escritores[tamanho] = csv.writer(f)

    with open(arquivo_entrada, 'r', newline='', encoding='utf-8') as f_in:
        leitor = csv.reader(f_in)
        cabecalho = next(leitor)

        # Descobrir o índice da coluna timestamp
        try:
            idx_timestamp = cabecalho.index("timestamp")
        except ValueError:
            print("[!] Coluna 'timestamp' não encontrada.")
            return

        # Escrever o cabeçalho da coluna timestamp
        for writer in escritores.values():
            writer.writerow(["timestamp"])

        for linha in leitor:
            contador += 1
            timestamp = linha[idx_timestamp]
            for tamanho in tamanhos:
                if contador <= tamanho:
                    escritores[tamanho].writerow([timestamp])
            if contador >= max(tamanhos):
                break

    for f in arquivos_saida.values():
        f.close()

    print(f"[✓] Amostras de timestamp geradas até {contador} registros.")

# Exemplo de uso
gerar_amostras_timestamp("ratings.csv")
