import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Dados
n = np.array([100, 1_000, 10_000, 100_000, 1_000_000])
tempo = np.array([0.000004, 0.000055, 0.000654, 0.006817, 0.082311])

# Calculando n * log2(n)
nlogn = n * np.log2(n)

# Normalizando para a escala do tempo
nlogn_normalizado = nlogn / nlogn[-1] * tempo[-1]

# Configurações globais
sns.set_theme(style="white")
plt.rcParams.update({'font.size': 14})

# Figura
plt.figure(figsize=(10, 6))

# Plots
plt.plot(n, tempo, 'o-', label='Tempo medido (staticList C)')
plt.plot(n, nlogn_normalizado, 's--', label='Curva n log n')

# Escalas logarítmicas
plt.xscale('log')
plt.yscale('log')

# Rótulos
plt.ylabel('Tempo Total (s)')

# Remover bordas superior e direita
ax = plt.gca()
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)

# Legenda sem borda e título
leg = ax.legend(frameon=False, title='')

plt.tight_layout()
plt.savefig('crescimento_nlogn.png', dpi=600)
plt.close()
