import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Dados
dados = pd.DataFrame({
    "Volume": [100, 1_000, 10_000, 100_000, 1_000_000] * 4,
    "Tempo (s)": (
        [0.000236, 0.002657, 0.055648, 0.554700, 5.223232] +
        [0.000423, 0.004692, 0.062784, 0.650361, 6.938603] +
        [0.000106, 0.001450, 0.026315, 0.250000, 3.297343] +
        [0.000188, 0.003278, 0.034563, 0.370120, 4.715385]
    ),
    "Cenário": (
        ["GRA-Static"]*5 +
        ["GRA-Dynamic"]*5 +
        ["GRB-Static"]*5 +
        ["GRB-Dynamic"]*5
    )
})

# Configurações globais
sns.set_theme(style="white")
plt.rcParams.update({'font.size': 14})

# Plot
plt.figure(figsize=(10, 6))
ax = sns.lineplot(
    data=dados,
    x="Volume",
    y="Tempo (s)",
    hue="Cenário",
    style="Cenário",
    markers=['o', 's', 'D', '^'],  # um símbolo para cada linha
    dashes=False
)

# Escalas log
ax.set_xscale('log')
ax.set_yscale('log')
ax.set_ylabel('Tempo (s)')
ax.set_xlabel('')

# Remover bordas superior e direita
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)

# Legenda limpa
leg = ax.legend(frameon=False, title='')

# Ticks x sem rotação
ax.tick_params(axis='x', rotation=0)

# Sem grade
ax.grid(False)

plt.tight_layout()
plt.savefig('time/diferent_inputs.png', dpi=600)
plt.close()
