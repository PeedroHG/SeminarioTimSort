import matplotlib.pyplot as plt
import seaborn as sns
import matplotlib.ticker as ticker
import pandas as pd

def plotar_tempo_por_estrutura_e_volume(df_tempos: pd.DataFrame, volume: str):
    estruturas = ['dynamic_list', 'dynamic_queue', 'dynamic_stack',
                  'static_list', 'static_queue', 'static_stack']

    nomes_legiveis = {
        'dynamic_list': 'Dynamic List',
        'dynamic_queue': 'Dynamic Queue',
        'dynamic_stack': 'Dynamic Stack',
        'static_list': 'Static List',
        'static_queue': 'Static Queue',
        'static_stack': 'Static Stack',
    }

    cores = {
        'dynamic_list': '#FF5733',   # vermelho-alaranjado
        'dynamic_queue': '#FF8D1A',  # laranja
        'dynamic_stack': '#FFC300',  # amarelo
        'static_list': '#33A1FF',    # azul-claro
        'static_queue': '#1A6EFF',   # azul-médio
        'static_stack': '#0047AB',   # azul-escuro
    }

    # Configurações globais
    sns.set_theme(style="white")
    plt.rcParams.update({'font.size': 14})

    # Filtro
    df_filtro = df_tempos[df_tempos['Volume'] == volume].copy()
    df_filtro[estruturas] = df_filtro[estruturas].apply(pd.to_numeric, errors='coerce')
    df_filtro[estruturas] = df_filtro[estruturas] * 1000

    df_filtro['total_tempo'] = df_filtro[estruturas].sum(axis=1)
    ordem_linguagens = df_filtro.sort_values('total_tempo')['Linguagem'].unique()

    df_melted = df_filtro.melt(
        id_vars=['Linguagem'],
        value_vars=estruturas,
        var_name='Estrutura',
        value_name='Tempo (ms)'
    )

    # Substitui por nomes legíveis
    df_melted['Estrutura'] = df_melted['Estrutura'].map(nomes_legiveis)

    # Plot
    plt.figure(figsize=(10, 6))
    ax = sns.barplot(
        data=df_melted,
        x='Linguagem',
        y='Tempo (ms)',
        hue='Estrutura',
        palette={nomes_legiveis[k]: v for k, v in cores.items()},
        order=ordem_linguagens
    )

    ax.set_xlabel('')
    ax.set_ylabel('Tempo (ms)')
    ax.tick_params(axis='x', rotation=0)
    ax.yaxis.set_major_locator(ticker.MaxNLocator(nbins=10))

    leg = ax.legend()
    leg.set_frame_on(False)
    leg.set_title('')

    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

    # Salva em alta resolução
    plt.tight_layout()
    plt.savefig(f'time/grafico_{volume}.png', dpi=600)
    plt.close()

def plotar_memoria_por_estrutura_e_volume(df_memoria: pd.DataFrame, volume: str):
    import matplotlib.ticker as ticker

    estruturas = ['dynamic_list', 'dynamic_queue', 'dynamic_stack',
                  'static_list', 'static_queue', 'static_stack']

    nomes_legiveis = {
        'dynamic_list': 'Dynamic List',
        'dynamic_queue': 'Dynamic Queue',
        'dynamic_stack': 'Dynamic Stack',
        'static_list': 'Static List',
        'static_queue': 'Static Queue',
        'static_stack': 'Static Stack',
    }

    cores = {
        'dynamic_list': '#FF5733',   # vermelho-alaranjado
        'dynamic_queue': '#FF8D1A',  # laranja
        'dynamic_stack': '#FFC300',  # amarelo
        'static_list': '#33A1FF',    # azul-claro
        'static_queue': '#1A6EFF',   # azul-médio
        'static_stack': '#0047AB',   # azul-escuro
    }

    sns.set_theme(style="white")
    plt.rcParams.update({'font.size': 14})

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

    df_melted['Estrutura'] = df_melted['Estrutura'].map(nomes_legiveis)

    plt.figure(figsize=(10, 6))
    ax = sns.barplot(
        data=df_melted,
        x='Linguagem',
        y='Memória (B)',
        hue='Estrutura',
        palette={nomes_legiveis[k]: v for k, v in cores.items()},
        order=ordem_linguagens
    )

    ax.set_xlabel('')
    ax.set_ylabel('Memória (B)')
    ax.tick_params(axis='x', rotation=0)
    ax.yaxis.set_major_locator(ticker.MaxNLocator(nbins=10))

    leg = ax.legend()
    leg.set_frame_on(False)
    leg.set_title('')

    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

    plt.tight_layout()
    plt.savefig(f'memory/grafico_memoria_{volume}.png', dpi=600)
    plt.close()

def plotar_todos_volumes_aglomerado(df_tempos: pd.DataFrame):
    import matplotlib.ticker as ticker

    estruturas = ['dynamic_list', 'dynamic_queue', 'dynamic_stack',
                  'static_list', 'static_queue', 'static_stack']

    nomes_legiveis = {
        'dynamic_list': 'Dynamic List',
        'dynamic_queue': 'Dynamic Queue',
        'dynamic_stack': 'Dynamic Stack',
        'static_list': 'Static List',
        'static_queue': 'Static Queue',
        'static_stack': 'Static Stack',
    }

    cores = {
        'dynamic_list': '#FF5733',   # vermelho-alaranjado
        'dynamic_queue': '#FF8D1A',  # laranja
        'dynamic_stack': '#FFC300',  # amarelo
        'static_list': '#33A1FF',    # azul-claro
        'static_queue': '#1A6EFF',   # azul-médio
        'static_stack': '#0047AB',   # azul-escuro
    }

    sns.set_theme(style="white")
    plt.rcParams.update({'font.size': 14})

    volumes = df_tempos['Volume'].unique()
    n = len(volumes)
    
    cols = 2
    rows = (n + 1) // cols

    fig, axes = plt.subplots(rows, cols, figsize=(cols * 8, rows * 6), squeeze=False)

    for i, volume in enumerate(volumes):
        ax = axes[i // cols, i % cols]

        df_filtro = df_tempos[df_tempos['Volume'] == volume].copy()
        df_filtro[estruturas] = df_filtro[estruturas].apply(pd.to_numeric, errors='coerce')
        df_filtro[estruturas] = df_filtro[estruturas] * 1000

        df_filtro['total_tempo'] = df_filtro[estruturas].sum(axis=1)
        ordem_linguagens = df_filtro.sort_values('total_tempo')['Linguagem'].unique()

        df_melted = df_filtro.melt(
            id_vars=['Linguagem'],
            value_vars=estruturas,
            var_name='Estrutura',
            value_name='Tempo (ms)'
        )
        df_melted['Estrutura'] = df_melted['Estrutura'].map(nomes_legiveis)

        sns.barplot(
            data=df_melted,
            x='Linguagem',
            y='Tempo (ms)',
            hue='Estrutura',
            palette={nomes_legiveis[k]: v for k, v in cores.items()},
            order=ordem_linguagens,
            ax=ax
        )

        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)
        ax.set_title(f'Volume {volume}')
        ax.set_xlabel('')
        ax.set_ylabel('Tempo (ms)')
        ax.tick_params(axis='x', rotation=0)
        ax.set_ylim(bottom=0)
        ax.legend().set_visible(False)  # sem legenda por subplot
        ax.yaxis.set_major_locator(ticker.MaxNLocator(nbins=5))

    # Remove axes extras
    total_subplots = rows * cols
    for j in range(n, total_subplots):
        fig.delaxes(axes[j // cols, j % cols])

    # Coloca uma legenda geral
    handles, labels = ax.get_legend_handles_labels()
    fig.legend(
        handles, labels,
        loc='lower right',       # Canto inferior direito
        bbox_to_anchor=(1, 0),   # Âncora para o canto inferior direito
        frameon=False,
        fontsize=14,
        title=''
    )
    plt.tight_layout(rect=[0, 0, 0.9, 1])  # espaço para legenda
    plt.savefig('time/todos_volumes_aglomerado.png', dpi=600)
    plt.close()

def plotar_todas_memorias_aglomerado(df_memoria: pd.DataFrame):
    import matplotlib.ticker as ticker

    estruturas = ['dynamic_list', 'dynamic_queue', 'dynamic_stack',
                  'static_list', 'static_queue', 'static_stack']

    nomes_legiveis = {
        'dynamic_list': 'Dynamic List',
        'dynamic_queue': 'Dynamic Queue',
        'dynamic_stack': 'Dynamic Stack',
        'static_list': 'Static List',
        'static_queue': 'Static Queue',
        'static_stack': 'Static Stack',
    }

    cores = {
        'dynamic_list': '#FF5733',   # vermelho-alaranjado
        'dynamic_queue': '#FF8D1A',  # laranja
        'dynamic_stack': '#FFC300',  # amarelo
        'static_list': '#33A1FF',    # azul-claro
        'static_queue': '#1A6EFF',   # azul-médio
        'static_stack': '#0047AB',   # azul-escuro
    }

    sns.set_theme(style="white")
    plt.rcParams.update({'font.size': 14})

    volumes = df_memoria['Volume'].unique()
    n = len(volumes)
    cols = 2
    rows = (n + 1) // cols

    fig, axes = plt.subplots(rows, cols, figsize=(cols * 8, rows * 6), squeeze=False)

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
        df_melted['Estrutura'] = df_melted['Estrutura'].map(nomes_legiveis)

        sns.barplot(
            data=df_melted,
            x='Linguagem',
            y='Memória (B)',
            hue='Estrutura',
            palette={nomes_legiveis[k]: v for k, v in cores.items()},
            order=ordem_linguagens,
            ax=ax
        )

        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)
        ax.set_title(f'Volume {volume}')
        ax.set_xlabel('')
        ax.set_ylabel('Memória (B)')
        ax.tick_params(axis='x', rotation=0)
        ax.legend().set_visible(False)  # sem legenda por subplot
        ax.yaxis.set_major_locator(ticker.MaxNLocator(nbins=5))

    # Remove axes extras se houver
    total_subplots = rows * cols
    for j in range(n, total_subplots):
        fig.delaxes(axes[j // cols, j % cols])

    # Legenda geral no canto superior direito, sem borda e sem título
    handles, labels = ax.get_legend_handles_labels()
    fig.legend(
        handles, labels,
        loc='lower right',       # Canto inferior direito
        bbox_to_anchor=(1, 0),   # Âncora para o canto inferior direito
        frameon=False,
        fontsize=14,
        title=''
    )
    plt.tight_layout(rect=[0, 0, 0.9, 1])  # espaço para legenda geral
    plt.savefig('memory/todos_volumes_memoria_aglomerado.png', dpi=600)
    plt.close()

def plotar_tempo_static_list_10k(df_tempos: pd.DataFrame):
    # Configurações globais
    sns.set_theme(style="white")
    plt.rcParams.update({'font.size': 14})

    # Filtro apenas para volume = "10K"
    df_filtro = df_tempos[df_tempos['Volume'] == "10K"].copy()

    # Converter a coluna static_list para numérica e em ms
    df_filtro['static_list'] = pd.to_numeric(df_filtro['static_list'], errors='coerce') * 1000

    # Ordenar por tempo (caso queira que as barras fiquem em ordem crescente)
    df_filtro = df_filtro.sort_values('static_list', ascending=False)

    cores_map = {
        'C': '#A6C8FF',       # Azul claro vibrante
        'C++': '#6699FF',     # Azul médio claro
        'Java': '#3366FF',    # Azul vibrante
        'Python': '#0047AB',  # Azul forte
        'JavaScript': '#002F6C' # Azul escuro profundo
    }
    # Plot
    plt.figure(figsize=(8, 5))
    ax = sns.barplot(
        data=df_filtro,
        hue='Linguagem',
        x='Linguagem',
        y='static_list',
        palette=cores_map  # mesma cor que você usou antes para static_list
    )

    ax.set_xlabel('')
    ax.set_ylabel('Tempo (ms)')
    ax.yaxis.set_major_locator(ticker.MaxNLocator(nbins=10))

    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

    # Salvar imagem em alta resolução
    plt.tight_layout()
    plt.savefig('time/grafico_static_list_10K.png', dpi=600)
    plt.close()

def plotar_memoria_static_list_10k(df_consumo: pd.DataFrame):
    # Configurações globais
    sns.set_theme(style="white")
    plt.rcParams.update({'font.size': 14})

    # Filtra só volume = "10K"
    df_filtro = df_consumo[df_consumo['Volume'] == "10K"].copy()

    # Converter a coluna static_list para numérica (é inteiro, não precisa multiplicar)
    df_filtro['static_list'] = pd.to_numeric(df_filtro['static_list'], errors='coerce')

    # Ordenar para barras em ordem decrescente (de cima para baixo)
    df_filtro = df_filtro.sort_values('static_list', ascending=False)

    cores_map = {
        'C': '#FFBA08',        # Amarelo-laranja quente (mais claro)
        'C++': '#FFA41B',      # Laranja forte
        'Java': '#F77F00',     # Laranja vibrante
        'Python': '#F06543',   # Laranja avermelhado forte
        'JavaScript': '#E63946' # Vermelho-alaranjado vivo (mais escuro)
    }
    
    # Plot
    plt.figure(figsize=(8, 5))
    ax = sns.barplot(
        data=df_filtro,
        hue='Linguagem',
        x='Linguagem',
        y='static_list',
        palette=cores_map
    )

    ax.set_xlabel('')
    ax.set_ylabel('Memória (bytes)')
    ax.yaxis.set_major_locator(ticker.MaxNLocator(nbins=10))

    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

    plt.tight_layout()
    plt.savefig('memory/grafico_static_list_10K.png', dpi=600)
    plt.close()