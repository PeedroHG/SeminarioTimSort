# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000188         | 10768                      |
| 1K              | 0.003278           | 10941                      |
| 10K             | 0.034563           | 12173                      |
| 100K            | 0.370120           | 24191                      |
| 1M              | 4.715385          | 147404                    |


### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000106          | 10704                      |
| 1K              | 0.001450           | 11067                     |
| 10K             | 0.026315           | 12493                     |
| 100K            | 0.297402           | 24860                     |
| 1M              | 3.297343           | 154912                    |

