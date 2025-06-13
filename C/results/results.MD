# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

## Estruturas Dinâmicas

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000008        | 1536                   |
| 1K              | 0.000143        | 1664                   |
| 10K             | 0.001174        | 2048                   |
| 100K            | 0.013513        | 5888                   |
| 1M              | 0.155000        | 44480                  |

### **dynamic_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000008        | 1536                   |
| 1K              | 0.000104        | 1664                   |
| 10K             | 0.001194        | 2048                   |
| 100K            | 0.013986        | 5888                   |
| 1M              | 0.146444        | 44484                  |


### **dynamic_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000008        | 1536                   |
| 1K              | 0.000101        | 1664                   |
| 10K             | 0.001157        | 2048                   |
| 100K            | 0.015206        | 5888                   |
| 1M              | 0.156902        | 44484                  |

## Estruturas Staticas

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0000008        | 1536                   |
| 1K              | 0000143        | 1664                   |
| 10K             | 0001174        | 2048                   |
| 100K            | 0013513        | 5888                   |
| 1M              | 0155000        | 44480                  |

