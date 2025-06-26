import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

def plotar_tempo_static_list():
    dados = pd.DataFrame({
        "Volume": [100, 1_000, 10_000, 100_000, 1_000_000] * 3,
        "Tempo (s)": [
            0.000106, 0.001450, 0.026315, 0.297402, 3.297343,  # Baixa desordem
            0.000117, 0.002395, 0.045544, 0.412003, 4.117676,  # Ratings
            0.000236, 0.002657, 0.055648, 0.554700, 5.223232,  # Timestamps
        ],
        "Cenário": (
            ["Baixa Desordem"] * 5 +
            ["Ratings"] * 5 +
            ["Timestamps"] * 5
        )
    })
    _plotar_tempo(dados, 'static_list_comparacao_tempo.png')

def plotar_tempo_dynamic_list():
    dados = pd.DataFrame({
        "Volume": [100, 1_000, 10_000, 100_000, 1_000_000] * 3,
        "Tempo (s)": [
            0.000188, 0.003278, 0.034563, 0.370120, 4.715385,  # Baixa desordem
            0.000354, 0.004094, 0.056707, 0.487099, 5.794625,  # Ratings
            0.000423, 0.004692, 0.062784, 0.650361, 6.938603,  # Timestamps
        ],
        "Cenário": (
            ["Baixa Desordem"] * 5 +
            ["Ratings"] * 5 +
            ["Timestamps"] * 5
        )
    })
    _plotar_tempo(dados, 'dynamic_list_comparacao_tempo.png')

def _plotar_tempo(dados: pd.DataFrame, nome_arquivo: str):
    sns.set_theme(style="white")
    plt.rcParams.update({"font.size": 14})

    plt.figure(figsize=(10, 6))
    ax = sns.lineplot(
        data=dados,
        x="Volume",
        y="Tempo (s)",
        hue="Cenário",
        style="Cenário",
        markers=['o', 's', '^'],
        dashes=False
    )

    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.set_xlabel('')
    ax.set_ylabel('Tempo (s)')

    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.legend(frameon=False, title='')
    ax.grid(False)

    plt.tight_layout()
    plt.savefig(nome_arquivo, dpi=600)
    plt.close()


plotar_tempo_static_list()
plotar_tempo_dynamic_list()