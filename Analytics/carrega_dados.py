import pandas as pd

def carregar_csv_completo(caminho_csv: str) -> tuple[pd.DataFrame, pd.DataFrame]:
    """
    Carrega os dados brutos do csv
    """
    df_bruto = pd.read_csv(caminho_csv, header=None)

    # Identifica linhas com nome da linguagem
    linhas_linguagem = df_bruto[
        df_bruto[0].notna() & df_bruto.iloc[:, 1].isna()
    ].index.tolist()

    dados = []

    for i in range(len(linhas_linguagem)):
        linguagem = df_bruto.iloc[linhas_linguagem[i], 0]
        inicio = linhas_linguagem[i] + 2
        fim = inicio + 5
        bloco = df_bruto.iloc[inicio:fim, :]

        tempos = bloco.iloc[:, 0:7].copy()
        consumo = bloco.iloc[:, 8:15].copy()

        consumo.iloc[:, 0] = tempos.iloc[:, 0]

        colnames = ['Volume', 'dynamic_list', 'dynamic_queue', 'dynamic_stack',
                    'static_list', 'static_queue', 'static_stack']
        tempos.columns = colnames
        consumo.columns = colnames

        tempos['Linguagem'] = linguagem
        consumo['Linguagem'] = linguagem

        dados.append(('tempo', tempos))
        dados.append(('consumo', consumo))

    df_tempos = pd.concat([t for tipo, t in dados if tipo == 'tempo'], ignore_index=True)
    df_consumo = pd.concat([c for tipo, c in dados if tipo == 'consumo'], ignore_index=True)

    return df_tempos, df_consumo
