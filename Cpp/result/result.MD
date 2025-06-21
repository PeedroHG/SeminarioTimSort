# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

## Estruturas Dinâmicas

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000011         | 3840                    |
| 1K              | 0.000128         | 3878                    |
| 10K             | 0.001234         | 4224                    |
| 100K            | 0.013012         | 7680                    |
| 1M              | 0.144850         | 46357                   |

### **dynamic_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000011         | 3840                    |
| 1K              | 0.000127         | 3878                    |
| 10K             | 0.001079         | 4288                    |
| 100K            | 0.012745         | 7680                    |
| 1M              | 0.125960         | 46328                   |



### **dynamic_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000012         | 3827                    |
| 1K              | 0.000111         | 3853                    |
| 10K             | 0.001061         | 4250                    |
| 100K            | 0.012708         | 7680                    |
| 1M              | 0.136208         | 46380                   |


## Estruturas Staticas

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000004          | 3827                     |
| 1K              | 0.000049         | 3827                     |
| 10K             | 0.000494          | 3968                     |
| 100K            | 0.006898          | 4992                     |
| 1M              | 0.082516          | 19018                    |


### **static_queue**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000005         | 3840                    |
| 1K              | 0.000054         | 3827                    |
| 10K             | 0.000628         | 3968                    |
| 100K            | 0.007650         | 4992                    |
| 1M              | 0.089734         | 18991                   |


### **static_stack**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000004         | 3827                    |
| 1K              | 0.000045         | 3840                    |
| 10K             | 0.000513         | 3968                    |
| 100K            | 0.006690         | 4992                    |
| 1M              | 0.071319         | 19033                   |
