import pandas as pd

# Caminho para seu arquivo CSV
arquivo_csv = 'ratings.csv'

# Tamanhos dos samples que você quer extrair
samples = [100, 1000, 10000, 100000, 1000000]

# Ler o CSV completo (se muito grande, pode usar chunks)
df = pd.read_csv(arquivo_csv)

# Para cada tamanho de sample, pegar as primeiras linhas e só a coluna 'rating'
for n in samples:
    # Garantir que n não ultrapasse o número de linhas do df
    n = min(n, len(df))
    
    sample_ratings = df.loc[:n-1, 'rating']
    
    # Salvar cada amostra em um arquivo (opcional)
    nome_arquivo = f'sample_{n}.csv'
    sample_ratings.to_csv(nome_arquivo, index=False, header=True)
    print(f'Salvo {nome_arquivo} com {n} registros.')