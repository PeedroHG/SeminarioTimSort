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
| 100             | 0.000007        | 1536                   |
| 1K              | 0.000059        | 1536                   |
| 10K             | 0.000654        | 1792                   |
| 100K            | 0.006817        | 3072                   |
| 1M              | 0.082311        | 17140                  |

### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000007        | 1536                   |
| 1K              | 0.000067        | 1536                   |
| 10K             | 0.000733        | 1792                   |
| 100K            | 0.007634        | 3072                   |
| 1M              | 0.090133        | 17136                  |

### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000006        | 1536                   |
| 1K              | 0.000059        | 1536                   |
| 10K             | 0.000534        | 1792                   |
| 100K            | 0.006553        | 3072                   |
| 1M              | 0.078459        | 16904                  |