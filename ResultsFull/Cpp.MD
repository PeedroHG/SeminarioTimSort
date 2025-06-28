# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

## Estruturas Dinâmicas

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000014         | 3840                   |
| 1K              | 0.000118         | 3856                   |
| 10K             | 0.001351         | 4268                   |
| 100K            | 0.013950         | 7795                   |
| 1M              | 0.126359         | 46315                   |

### **dynamic_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000014         | 3827                   |
| 1K              | 0.000145         | 3855                   |
| 10K             | 0.001792         | 4208                   |
| 100K            | 0.014919         | 7808                   |
| 1M              | 0.132393         | 46258                   |



### **dynamic_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000012         | 3814                   |
| 1K              | 0.000095         | 3872                   |
| 10K             | 0.001551         | 4224                   |
| 100K            | 0.013562         | 7296                   |
| 1M              | 0.125568         | 42355                   |


## Estruturas Staticas

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000005         | 3840                   |
| 1K              | 0.000053         | 3851                   |
| 10K             | 0.000609         | 3968                   |
| 100K            | 0.006382         | 4992                   |
| 1M              | 0.068767         | 18944                   |


### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000006         | 3840                   |
| 1K              | 0.000067         | 3851                   |
| 10K             | 0.000760         | 3968                   |
| 100K            | 0.009930         | 4992                   |
| 1M              | 0.077471         | 18944                   |


### **static_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000006         | 3840                   |
| 1K              | 0.000091         | 3851                   |
| 10K             | 0.000649         | 3968                   |
| 100K            | 0.007291         | 4992                   |
| 1M              | 0.067372         | 18944                   |
