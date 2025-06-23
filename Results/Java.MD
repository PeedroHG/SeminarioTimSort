# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

## Estruturas Dinâmicas

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001011        | 44170                    |
| 1K              | 0.002721         | 44754                    |
| 10K             | 0.007876         | 48516                    |
| 100K            | 0.065069         | 73198                    |
| 1M              | 0.313211         | 226536                   |

### **dynamic_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000905         | 44136                    |
| 1K              | 0.002501         | 44771                    |
| 10K             | 0.007962         | 48630                    |
| 100K            | 0.063313         | 73220                    |
| 1M              | 0.334640         | 226479                   |


### **dynamic_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000786         | 44142                    |
| 1K              | 0.004965         | 44635                    |
| 10K             | 0.008278         | 48686                    |
| 100K            | 0.064442         | 73208                    |
| 1M              | 0.346097         | 226468                   |

## Estruturas Staticas

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000284         | 44134                    |
| 1K              | 0.001544         | 44744                    |
| 10K             | 0.006647         | 48306                    |
| 100K            | 0.045313         | 71860                    |
| 1M              | 0.234124         | 238016                   |

### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000287        | 44028                    |
| 1K              | 0.001804        | 44791                    |
| 10K             | 0.007666         | 49608                    |
| 100K            | 0.044791         | 72004                    |
| 1M              | 0.233588         | 237165                   |

### **static_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000227         | 44120                    |
| 1K              | 0.001559         | 44648                    |
| 10K             | 0.007361         | 48525                    |
| 100K            | 0.042345         | 71529                    |
| 1M              | 0.236308         | 234660                   |