# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

## Estruturas Dinâmicas

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000009         | 1536                   |
| 1K              | 0.000124         | 1664                   |
| 10K             | 0.001183         | 2048                   |
| 100K            | 0.013318         | 5760                   |
| 1M              | 0.134499         | 44416                  |

### **dynamic_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000008         | 1536                   |
| 1K              | 0.000129         | 1664                   |
| 10K             | 0.001184         | 2048                   |
| 100K            | 0.012378         | 5760                   |
| 1M              | 0.148240         | 44278                   |


### **dynamic_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000009         | 1536                   |
| 1K              | 0.000156         | 1664                   |
| 10K             | 0.001162         | 2048                   |
| 100K            | 0.012331         | 5760                   |
| 1M              | 0.113088         | 44422                   |

## Estruturas Staticas

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000006         | 1536                   |
| 1K              | 0.000060         | 1536                   |
| 10K             | 0.000614          | 1792                   |
| 100K            | 0.008886         | 3059                   |
| 1M              | 0.063661         | 16938                   |

### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000008         | 5504                   |
| 1K              | 0.000066         | 1536                   |
| 10K             | 0.000756         | 1792                   |
| 100K            | 0.008605         | 3059                   |
| 1M              | 0.073918         | 16949                   |

### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000008         | 1536                   |
| 1K              | 0.000070         | 1536                   |
| 10K             | 0.000679         | 1792                   |
| 100K            | 0.006345         | 3072                   |
| 1M              | 0.072833         | 16947                   |