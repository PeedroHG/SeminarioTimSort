# Resultados de Performance

Esse documento apresenta as métrica em tempo e memória para execução do algoritimo TimSort em dynamic e static list em diferentes volumes de dados em python. O objetivo é testas como o TimSort se comporta em diferentes inputs: baixa desordem, ratings e timestamps 

# Usando Dados com baixa desordem

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

# Usando Ratings

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000354        | 11136                      |
| 1K              | 0.004094           | 11213                      |
| 10K             | 0.056707           | 12544                      |
| 100K            | 0.487099           | 24550                      |
| 1M              | 5.794625          | 147771                    |


### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000117          | 11100                      |
| 1K              | 0.002395           | 11226                     |
| 10K             | 0.045544           | 12493                     |
| 100K            | 0.412003           | 25084                     |
| 1M              | 4.117676           | 155265                    |

# Usando Timestamp

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000423         | 11299                     |
| 1K              | 0.004692          | 11379                     |
| 10K             | 0.062784          | 12493                     |
| 100K            | 0.650361          | 24669                     |
| 1M              | 6.938603          | 147862                    |


### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000236          | 11200                     |
| 1K              | 0.002657          | 11341                     |
| 10K             | 0.055648          | 12582                     |
| 100K            | 0.554700          | 25206                     |
| 1M              | 5.223232          | 155361                    |