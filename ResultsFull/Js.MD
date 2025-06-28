# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

## Estruturas Dinâmicas

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001068         | 40070                   |
| 1K              | 0.003568         | 44851                   |
| 10K             | 0.012930         | 49215                   |
| 100K            | 0.070782         | 93649                   |
| 1M              | 0.565431         | 215632                   |

### **dynamic_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000866         | 40166                   |
| 1K              | 0.003455         | 44856                   |
| 10K             | 0.013927         | 49312                   |
| 100K            | 0.076216         | 93806                   |
| 1M              | 0.542289         | 216098                   |



### **dynamic_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000860         | 40192                   |
| 1K              | 0.003411         | 44876                   |
| 10K             | 0.012453         | 49248                   |
| 100K            | 0.062395         | 93248                   |
| 1M              | 0.626259         | 215037                   |

## Estruturas Staticas

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000905         | 40165                   |
| 1K              | 0.003184         | 44195                   |
| 10K             | 0.011380         | 48974                   |
| 100K            | 0.047541         | 79018                   |
| 1M              | 0.405098         | 193530                   |


### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000765         | 40166                   |
| 1K              | 0.003285         | 44153                   |
| 10K             | 0.010275         | 48877                   |
| 100K            | 0.051220         | 79064                   |
| 1M              | 0.390635         | 194914                   |


### **static_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.001047         | 40150                   |
| 1K              | 0.003195         | 44225                   |
| 10K             | 0.012133         | 48896                   |
| 100K            | 0.050470         | 78952                   |
| 1M              | 0.327313         | 193724                   |
