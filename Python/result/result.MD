# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

## Estruturas Dinâmicas

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000423         | 11299                     |
| 1K              | 0.004692          | 11379                     |
| 10K             | 0.062784          | 12493                     |
| 100K            | 0.650361          | 24669                     |
| 1M              | 6.938603          | 147862                    |

### **dynamic_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000439          | 11239                     |
| 1K              | 0.005206          | 11340                     |
| 10K             | 0.067339          | 12582                     |
| 100K            | 0.652316          | 24651                     |
| 1M              | 6.661681          | 147962                    |


### **dynamic_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000426          | 11226                     |
| 1K              | 0.004946          | 11345                     |
| 10K             | 0.065053          | 12495                     |
| 100K            | 0.628269          | 24620                     |
| 1M              | 6.895984          | 147893                    |

## Estruturas Staticas

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000236          | 11200                     |
| 1K              | 0.002657          | 11341                     |
| 10K             | 0.055648          | 12582                     |
| 100K            | 0.554700          | 25206                     |
| 1M              | 5.223232          | 155361                    |

### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000219          | 11194                     |
| 1K              | 0.002975          | 11379                     |
| 10K             | 0.056288          | 12586                     |
| 100K            | 0.574234          | 25195                     |
| 1M              | 5.163898          | 155331                    |

### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000290          | 11228                     |
| 1K              | 0.002822          | 11366                    |
| 10K             | 0.055990          | 12554                    |
| 100K            | 0.556504          | 25184                     |
| 1M              | 5.473893          | 155282                   |