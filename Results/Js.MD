# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

## Estruturas Dinâmicas

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001401          | 40263                      |
| 1K              | 0.009048            | 46540                      |
| 10K             | 0.021711           | 50309                      |
| 100K            | 0.083576           | 98867                      |
| 1M              | 0.773838           | 233759                     |

### **dynamic_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001551          | 40297                      |
| 1K              | 0.008978           | 46449                      |
| 10K             | 0.018436           | 50239                      |
| 100K            | 0.088463           | 98944                      |
| 1M              | 0.796932           | 232669                     |

### **dynamic_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001260          | 40294                      |
| 1K              | 0.009042          | 46499                     |
| 10K             | 0.021998          | 50036                     |
| 100K            | 0.084912          | 98970                     |
| 1M              | 0.819633          | 232158                    |


## Estruturas Staticas

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001199          | 40307                      |
| 1K              | 0.009029           | 46365                      |
| 10K             | 0.017188           | 49337                      |
| 100K            | 0.069002           | 78109                      |
| 1M              | 0.621102           | 206097                     |


### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001217          | 40292                      |
| 1K              | 0.007611           | 46363                      |
| 10K             | 0.018257           | 49443                     |
| 100K            | 0.071473           | 78018                     |
| 1M              | 0.563100           | 209074                     |


### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001126          | 40296                      |
| 1K              | 0.008738            | 46371                      |
| 10K             | 0.018590           | 49357                      |
| 100K            | 0.068361           | 77958                      |
| 1M              | 0.608552           | 208829                     |
