import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Dados
n = np.array([100, 1_000, 10_000, 100_000, 1_000_000])
tempo = np.array([0.000004, 0.000055, 0.000654, 0.006817, 0.082311])

# Calculando n * log2(n)
nlogn = n * np.log2(n)

# Normalizar para facilitar a comparação visual (ajustar escala de nlogn)
nlogn_normalizado = nlogn / nlogn[-1] * tempo[-1]

sns.set_theme(style="dark")
plt.figure(figsize=(10,6))

# Plot do tempo real
plt.plot(n, tempo, 'o-', label='Tempo medido (staticList C)')

# Plot do n log n normalizado
plt.plot(n, nlogn_normalizado, 's--', label='Curva n log n')

plt.xscale('log')
plt.yscale('log')
plt.xlabel('Volume de Dados (n)')
plt.ylabel('Tempo Total (s)')
plt.title('Comparação: Tempo medido vs. n log n')
plt.legend()
plt.grid(False)
plt.tight_layout()

plt.savefig('crescimento_nlogn.png')
plt.show()