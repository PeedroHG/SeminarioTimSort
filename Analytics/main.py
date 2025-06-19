import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd

# Dados de tempo (s) e memória (kB) para cada estrutura e volume
data = {
    "Estrutura": [
        "dynamic_list", "dynamic_list", "dynamic_list", "dynamic_list", "dynamic_list",
        "dynamic_queue", "dynamic_queue", "dynamic_queue", "dynamic_queue", "dynamic_queue",
        "dynamic_stack", "dynamic_stack", "dynamic_stack", "dynamic_stack", "dynamic_stack",
        "static_list", "static_list", "static_list", "static_list", "static_list",
        "static_queue", "static_queue", "static_queue", "static_queue", "static_queue",
        "static_stack", "static_stack", "static_stack", "static_stack", "static_stack"
    ],
    "Volume": [100, 1000, 10000, 100000, 1000000] * 6,
    "Tempo (s)": [
        0.000008, 0.000143, 0.001174, 0.013513, 0.155000,
        0.000008, 0.000104, 0.001194, 0.013986, 0.146444,
        0.000008, 0.000101, 0.001157, 0.015206, 0.156902,
        0.000007, 0.000059, 0.000654, 0.006817, 0.082311,
        0.000007, 0.000067, 0.000733, 0.007634, 0.090133,
        0.000006, 0.000059, 0.000534, 0.006553, 0.078459,
    ],
    "Memória (kB)": [
        1536, 1664, 2048, 5888, 44480,
        1536, 1664, 2048, 5888, 44484,
        1536, 1664, 2048, 5888, 44484,
        1536, 1536, 1792, 3072, 17140,
        1536, 1536, 1792, 3072, 17136,
        1536, 1536, 1792, 3072, 16904,
    ]
}

df = pd.DataFrame(data)


def plot_tempo_vs_volume(df):
    plt.figure(figsize=(10, 6))
    sns.lineplot(data=df, x="Volume", y="Tempo (s)", hue="Estrutura", marker="o")
    plt.title("Tempo de Execução vs Volume de Dados")
    plt.xscale("log")
    plt.yscale("log")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig("tempo_vs_volume.png")

def plot_memoria_vs_volume(df):
    plt.figure(figsize=(10, 6))
    sns.lineplot(data=df, x="Volume", y="Memória (kB)", hue="Estrutura", marker="o")
    plt.title("Uso de Memória vs Volume de Dados")
    plt.xscale("log")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig("memoria_vs_volume.png")



plot_tempo_vs_volume(df)
plot_memoria_vs_volume(df)

