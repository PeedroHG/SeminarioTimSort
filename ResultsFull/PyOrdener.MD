# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do método para diferentes volumes de dados e diferentes estruturas. A medição foi realizada utilizando o comando `/usr/bin/time -v`.

### **dynamic_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000380          | 11008                   |
| 1K              | 0.004549         | 11136                   |
| 10K             | 0.031878         | 12416                   |
| 100K            | 0.343921         | 24309                  |
| 1M              | 5.177725         | 143981                  |

### **static_list**
| Volume de Dados | Tempo Total (s) | Memória Máxima (kbytes) |
|-----------------|-----------------|------------------------|
| 100             | 0.000144         | 10912                   |
| 1K              | 0.001911         | 11136                   |
| 10K             | 0.022107         | 12288                   |
| 100K            | 0.291499         | 24933                   |
| 1M              | 3.329111         | 155066                   |