import matplotlib.pyplot as plt
import seaborn as sns
import matplotlib.ticker as ticker
import pandas as pd

def plotar_tempo_por_estrutura_e_volume(df_tempos: pd.DataFrame, volume: str):
    estruturas = ['dynamic_list', 'dynamic_queue', 'dynamic_stack',
                  'static_list', 'static_queue', 'static_stack']

    df_filtro = df_tempos[df_tempos['Volume'] == volume].copy()
    df_filtro[estruturas] = df_filtro[estruturas].apply(pd.to_numeric, errors='coerce')
    df_filtro[estruturas] = df_filtro[estruturas] * 1000

    df_melted = df_filtro.melt(
        id_vars=['Linguagem'],
        value_vars=estruturas,
        var_name='Estrutura',
        value_name='Tempo (ms)'
    )

    df_filtro['total_tempo'] = df_filtro[estruturas].sum(axis=1)
    ordem_linguagens = df_filtro.sort_values('total_tempo')['Linguagem'].unique()

    palette = {
        'dynamic_list': '#d44e25',
        'dynamic_queue': '#e6734f',
        'dynamic_stack': '#a8361a',
        'static_list': '#2575d4',
        'static_queue': '#4f8ce6',
        'static_stack': '#1a4f9e',
    }

    aliases = {
        'dynamic_list': 'DL',
        'dynamic_queue': 'DQ',
        'dynamic_stack': 'DS',
        'static_list': 'SL',
        'static_queue': 'SQ',
        'static_stack': 'SS',
    }

    plt.figure(figsize=(10, 6))
    ax = sns.barplot(data=df_melted, x='Linguagem', y='Tempo (ms)', hue='Estrutura',
                     palette=palette, order=ordem_linguagens)
    ax.legend_.remove()
    plt.title(f'Tempo por estrutura - Volume {volume}')
    plt.ylabel('Tempo (ms)')
    plt.xlabel('Linguagem')
    plt.xticks(rotation=45)
    plt.ylim(bottom=0)

    ax.yaxis.set_major_locator(ticker.MaxNLocator(nbins=10))

    for patch, (_, row) in zip(ax.patches, df_melted.iterrows()):
        height = patch.get_height()
        x = patch.get_x() + patch.get_width() / 2
        sigla = aliases[row['Estrutura']]
        ax.text(x, height + (0.01 * height), sigla, ha='center', va='bottom', fontsize=8, rotation=90)

    plt.tight_layout()
    plt.savefig(f'time/grafico_{volume}.png', dpi=300)
    plt.close()

def plotar_todos_volumes_aglomerado(df_tempos: pd.DataFrame):
    estruturas = ['dynamic_list', 'dynamic_queue', 'dynamic_stack',
                  'static_list', 'static_queue', 'static_stack']

    volumes = df_tempos['Volume'].unique()
    n = len(volumes)
    
    cols = 2
    rows = (n + 1) // cols

    fig, axes = plt.subplots(rows, cols, figsize=(cols * 8, rows * 6), squeeze=False)

    palette = {
        'dynamic_list': '#d44e25',
        'dynamic_queue': '#e6734f',
        'dynamic_stack': '#a8361a',
        'static_list': '#2575d4',
        'static_queue': '#4f8ce6',
        'static_stack': '#1a4f9e',
    }

    aliases = {
        'dynamic_list': 'DL',
        'dynamic_queue': 'DQ',
        'dynamic_stack': 'DS',
        'static_list': 'SL',
        'static_queue': 'SQ',
        'static_stack': 'SS',
    }

    for i, volume in enumerate(volumes):
        ax = axes[i // cols, i % cols]

        df_filtro = df_tempos[df_tempos['Volume'] == volume].copy()
        df_filtro[estruturas] = df_filtro[estruturas].apply(pd.to_numeric, errors='coerce')
        df_filtro[estruturas] = df_filtro[estruturas] * 1000

        df_melted = df_filtro.melt(
            id_vars=['Linguagem'],
            value_vars=estruturas,
            var_name='Estrutura',
            value_name='Tempo (ms)'
        )

        df_filtro['total_tempo'] = df_filtro[estruturas].sum(axis=1)
        ordem_linguagens = df_filtro.sort_values('total_tempo')['Linguagem'].unique()

        sns.barplot(data=df_melted, x='Linguagem', y='Tempo (ms)', hue='Estrutura',
                    palette=palette, order=ordem_linguagens, ax=ax)
        
        ax.set_title(f'Volume {volume}')
        ax.set_xlabel('Linguagem')
        ax.set_ylabel('Tempo (ms)')
        ax.tick_params(axis='x', rotation=45)
        ax.set_ylim(bottom=0)
        ax.legend_.remove()
        ax.yaxis.set_major_locator(ticker.MaxNLocator(nbins=5))

        for patch, (_, row) in zip(ax.patches, df_melted.iterrows()):
            height = patch.get_height()
            x = patch.get_x() + patch.get_width() / 2
            sigla = aliases[row['Estrutura']]
            ax.text(x, height + (0.01 * height), sigla, ha='center', va='bottom', fontsize=7, rotation=90)

    total_subplots = rows * cols
    for j in range(n, total_subplots):
        fig.delaxes(axes[j // cols, j % cols])

    plt.tight_layout()
    plt.savefig('time/todos_volumes_aglomerado.png', dpi=300)
    plt.close()

def plotar_memoria_por_estrutura_e_volume(df_memoria: pd.DataFrame, volume: str):
    import matplotlib.ticker as ticker

    estruturas = ['dynamic_list', 'dynamic_queue', 'dynamic_stack',
                  'static_list', 'static_queue', 'static_stack']

    df_filtro = df_memoria[df_memoria['Volume'] == volume].copy()
    df_filtro[estruturas] = df_filtro[estruturas].apply(pd.to_numeric, errors='coerce')

    # Calcula a ordem das linguagens pelo consumo total
    df_filtro['total_mem'] = df_filtro[estruturas].sum(axis=1)
    ordem_linguagens = df_filtro.sort_values('total_mem')['Linguagem'].unique()

    palette = {
        'dynamic_list': '#d44e25',
        'dynamic_queue': '#e6734f',
        'dynamic_stack': '#a8361a',
        'static_list': '#2575d4',
        'static_queue': '#4f8ce6',
        'static_stack': '#1a4f9e',
    }

    aliases = {
        'dynamic_list': 'DL',
        'dynamic_queue': 'DQ',
        'dynamic_stack': 'DS',
        'static_list': 'SL',
        'static_queue': 'SQ',
        'static_stack': 'SS',
    }

    df_melted = df_filtro.melt(
        id_vars=['Linguagem'],
        value_vars=estruturas,
        var_name='Estrutura',
        value_name='Memória (B)'
    )

    plt.figure(figsize=(10, 6))
    ax = sns.barplot(data=df_melted, x='Linguagem', y='Memória (B)',
                     hue='Estrutura', palette=palette, order=ordem_linguagens)
    ax.legend_.remove()
    ax.set_title(f'Memória por estrutura - Volume {volume}')
    ax.set_ylabel('Memória (B)')
    ax.set_xlabel('Linguagem')
    ax.tick_params(axis='x', rotation=45)
    ax.yaxis.set_major_locator(ticker.MaxNLocator(nbins=10))

    # Rótulo nas barras
    for patch, (_, row) in zip(ax.patches, df_melted.iterrows()):
        height = patch.get_height()
        x = patch.get_x() + patch.get_width() / 2
        sigla = aliases[row['Estrutura']]
        ax.text(x, height + (0.01 * height), sigla, ha='center', va='bottom', fontsize=8, rotation=90)

    plt.tight_layout()
    plt.savefig(f'memory/grafico_memoria_{volume}.png', dpi=300)
    plt.close()

def plotar_todas_memorias_aglomerado(df_memoria: pd.DataFrame):
    import matplotlib.ticker as ticker

    estruturas = ['dynamic_list', 'dynamic_queue', 'dynamic_stack',
                  'static_list', 'static_queue', 'static_stack']

    volumes = df_memoria['Volume'].unique()
    n = len(volumes)
    cols = 2
    rows = (n + 1) // cols

    fig, axes = plt.subplots(rows, cols, figsize=(cols * 8, rows * 6), squeeze=False)

    palette = {
        'dynamic_list': '#d44e25',
        'dynamic_queue': '#e6734f',
        'dynamic_stack': '#a8361a',
        'static_list': '#2575d4',
        'static_queue': '#4f8ce6',
        'static_stack': '#1a4f9e',
    }

    aliases = {
        'dynamic_list': 'DL',
        'dynamic_queue': 'DQ',
        'dynamic_stack': 'DS',
        'static_list': 'SL',
        'static_queue': 'SQ',
        'static_stack': 'SS',
    }

    for i, volume in enumerate(volumes):
        ax = axes[i // cols, i % cols]

        df_filtro = df_memoria[df_memoria['Volume'] == volume].copy()
        df_filtro[estruturas] = df_filtro[estruturas].apply(pd.to_numeric, errors='coerce')
        df_filtro['total_mem'] = df_filtro[estruturas].sum(axis=1)
        ordem_linguagens = df_filtro.sort_values('total_mem')['Linguagem'].unique()

        df_melted = df_filtro.melt(
            id_vars=['Linguagem'],
            value_vars=estruturas,
            var_name='Estrutura',
            value_name='Memória (B)'
        )

        sns.barplot(data=df_melted, x='Linguagem', y='Memória (B)', hue='Estrutura',
                    palette=palette, order=ordem_linguagens, ax=ax)
        ax.legend_.remove()
        ax.set_title(f'Memória por estrutura - Volume {volume}')
        ax.set_xlabel('Linguagem')
        ax.set_ylabel('Memória (B)')
        ax.tick_params(axis='x', rotation=45)
        ax.yaxis.set_major_locator(ticker.MaxNLocator(nbins=5))

        for patch, (_, row) in zip(ax.patches, df_melted.iterrows()):
            height = patch.get_height()
            x = patch.get_x() + patch.get_width() / 2
            sigla = aliases[row['Estrutura']]
            ax.text(x, height + (0.01 * height), sigla, ha='center', va='bottom', fontsize=7, rotation=90)

    total_subplots = rows * cols
    for j in range(n, total_subplots):
        fig.delaxes(axes[j // cols, j % cols])

    plt.tight_layout()
    plt.savefig('memory/todos_volumes_memoria_aglomerado.png', dpi=300)
    plt.close()
