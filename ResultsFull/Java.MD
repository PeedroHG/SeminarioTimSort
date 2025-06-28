# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

## Estruturas Dinâmicas

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001345         | 116349                   |
| 1K              | 0.003054         | 116668                   |
| 10K             | 0.010360         | 116767                   |
| 100K            | 0.041430         | 130081                   |
| 1M              | 0.324562         | 242421                   |

### **dynamic_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001250         | 116689                   |
| 1K              | 0.003418         | 116884                   |
| 10K             | 0.010210         | 116823                   |
| 100K            | 0.041024         | 131343                   |
| 1M              | 0.361962         | 237015                   |


### **dynamic_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001435         | 116490                   |
| 1K              | 0.003310         | 116490                   |
| 10K             | 0.011703         | 117168                   |
| 100K            | 0.040710         | 130973                   |
| 1M              | 0.376101          | 234679                    |

## Estruturas Staticas

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001168         | 116471                   |
| 1K              | 0.002403        | 116374                   |
| 10K             | 0.008680         | 116751                   |
| 100K            | 0.038840         | 128919                   |
| 1M              | 0.258217         | 227271                   |

### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000929         | 116294                   |
| 1K              | 0.002639         | 116719                   |
| 10K             | 0.009402         | 116584                   |
| 100K            | 0.040407         | 129007                   |
| 1M              | 0.298287         | 238711                   |

### **static_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000956         | 116632                   |
| 1K              | 0.002305         | 116410                   |
| 10K             | 0.010245         | 116591                   |
| 100K            | 0.038879         | 129217                   |
| 1M              | 0.265328         | 232842                   |