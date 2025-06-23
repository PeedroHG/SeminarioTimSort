from carrega_dados import carregar_csv_completo
import plot

df_tempos, df_consumo = carregar_csv_completo('dados.csv')

# Gerar gráficos separados para todos os volumes
volumes = df_tempos['Volume'].unique()
for volume in volumes:
    plot.plotar_tempo_por_estrutura_e_volume(df_tempos, volume)
    plot.plotar_memoria_por_estrutura_e_volume(df_consumo, volume)

# Gerar gráfico aglomerado com todos os volumes
plot.plotar_todos_volumes_aglomerado(df_tempos)
plot.plotar_todas_memorias_aglomerado(df_consumo)

