import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit

# Dados fornecidos
volumes = np.array([100, 1000, 10000, 100000, 1000000])
tempos = np.array([0.000007, 0.000059, 0.000654, 0.006817, 0.082311])

# Define a função do modelo: k * n * log2(n)
def modelo_nlogn(n, k):
    return k * n * np.log2(n)

# Ajuste dos parâmetros usando os dados
parametros, _ = curve_fit(modelo_nlogn, volumes, tempos)
k_estimada = parametros[0]
ajuste_nlogn = modelo_nlogn(volumes, k_estimada)

# Plot do gráfico
sns.set_style("whitegrid")
sns.set_context("paper", font_scale=1.5)

plt.figure(figsize=(8,5))
sns.lineplot(x=volumes, y=tempos, marker='o', errorbar=None, label='Tempo medido (dados reais)')
sns.lineplot(x=volumes, y=ajuste_nlogn, linestyle='--', color='r', label=f'Ajuste: k·n·log₂(n)\n(k ≈ {k_estimada:.2e})')
plt.xlabel('Volume de Dados (n)')
plt.ylabel('Tempo (segundos)')
plt.title('Volume de Dados vs Tempo de Execução TimSort')
plt.legend()
plt.grid(True)

# Escala logarítmica para melhor visualização
plt.xscale('log')
plt.yscale('log')

# Exibir e/ou salvar
plt.tight_layout()
plt.savefig('grafico_ajuste_nlogn.png')
print("Gráfico salvo como 'grafico_ajuste_nlogn.png'")

