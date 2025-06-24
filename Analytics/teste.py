import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

dados = pd.DataFrame({
    "Volume": [100, 1_000, 10_000, 100_000, 1_000_000] * 4,
    "Tempo (s)": (
        [0.000236, 0.002657, 0.055648, 0.554700, 5.223232] +
        [0.000423, 0.004692, 0.062784, 0.650361, 6.938603] +
        [0.000106, 0.001450, 0.026315, 0.297402, 3.297343] +
        [0.000188, 0.003278, 0.034563, 0.370120, 4.715385]
    ),
    "Cenário": (
        ["Static | alta desordem"]*5 +
        ["Dynamic | alta desordem"]*5 +
        ["Static | baixa desordem"]*5 +
        ["Dynamic | baixa desordem"]*5
    )
})

sns.set_theme(style="whitegrid")
plt.figure(figsize=(10,6))
sns.lineplot(data=dados, x="Volume", y="Tempo (s)", hue="Cenário", marker="o")
plt.xscale('log')
plt.yscale('log')
plt.title('Comparativo entre inputs')
plt.xlabel('Volume de Dados')
plt.ylabel('Tempo (s)')

# Só grid principal, sem riscos finos
plt.grid(True, which='major')

plt.tight_layout()
plt.savefig('tempo_comparacao_seaborn.png')
plt.show()
