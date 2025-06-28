# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

## Estruturas Dinâmicas

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000380          | 11008                   |
| 1K              | 0.004549         | 11136                   |
| 10K             | 0.031878         | 12416                   |
| 100K            | 0.343921         | 24309                  |
| 1M              | 5.177725         | 143981                  |

### **dynamic_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000329         | 10995                   |
| 1K              | 0.004388         | 11136                   |
| 10K             | 0.036245         | 12282                   |
| 100K            | 0,366000         | 24280                   |
| 1M              | 5,006197         | 144068                   |


### **dynamic_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000372         | 11007                   |
| 1K              | 0.004796         | 11136                   |
| 10K             | 0.031072        | 12279                   |
| 100K            | 0.374642         | 24254                   |
| 1M              | 5.243565         | 144021                   |

## Estruturas Staticas

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000144         | 10912                   |
| 1K              | 0.001911         | 11136                   |
| 10K             | 0.022107         | 12288                   |
| 100K            | 0.291499         | 24933                   |
| 1M              | 3.329111         | 155066                   |

### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000150         | 11008                   |
| 1K              | 0.001742         | 11120                   |
| 10K             | 0.024014         | 12276                   |
| 100K            | 0.274102         | 24918                   |
| 1M              | 3.389937         | 155084                   |

### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000157         | 10982                   |
| 1K              | 0.002026         | 11136                   |
| 10K             | 0.025415         | 12262                   |
| 100K            | 0.311625         | 24899                   |
| 1M              | 3.402854         | 155096                   |