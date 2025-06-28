import random

# Tamanhos desejados
samples = [100, 1000, 10000, 100000, 1000000]

# Gera lista parcialmente ordenada com % de desordem
def gerar_lista_parcialmente_ordenada(n, desordem_percent=1):
    lista = list(range(n))
    qtd_trocas = max(1, int(n * desordem_percent / 100))
    
    for _ in range(qtd_trocas):
        i = random.randint(0, n - 2)
        # Troca elementos adjacentes para gerar pequenas quebras locais
        lista[i], lista[i + 1] = lista[i + 1], lista[i]
    
    return lista

# Gerar e salvar os samples
for n in samples:
    lista = gerar_lista_parcialmente_ordenada(n)

    # Salva como .txt (um número por linha)
    with open(f'sample_parcial_{n}.csv', 'w') as f:
        for valor in lista:
            f.write(f"{valor}\n")
    
    print(f'Sample parcialmente ordenado ({n} elementos) salvo em sample_parcial_{n}.csv')
