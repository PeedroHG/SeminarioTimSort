# Resultados de Performance

Este documento apresenta os resultados obtidos durante a execução do programa **dynamic_list_ts** para diferentes volumes de dados. A medição foi realizada utilizando o comando `/usr/bin/time -v`.


### 1M registros

```
User time (seconds): 0.20
System time (seconds): 0.15
Percent of CPU this job got: 107%
Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.33
Average shared text size (kbytes): 0
Average unshared data size (kbytes): 0
Average stack size (kbytes): 0
Average total size (kbytes): 0
Maximum resident set size (kbytes): 40452
Average resident set size (kbytes): 0
Major (requiring I/O) page faults: 0
Minor (reclaiming a frame) page faults: 12249
Voluntary context switches: 0
Involuntary context switches: 3
Swaps: 0
File system inputs: 0
File system outputs: 20992
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0
```

### 1OOK registros

```
User time (seconds): 0.02
System time (seconds): 0.01
Percent of CPU this job got: 81%
Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.05
Average shared text size (kbytes): 0
Average unshared data size (kbytes): 0
Average stack size (kbytes): 0
Average total size (kbytes): 0
Maximum resident set size (kbytes): 5376
Average resident set size (kbytes): 0
Major (requiring I/O) page faults: 0
Minor (reclaiming a frame) page faults: 1120
Voluntary context switches: 2
Involuntary context switches: 0
Swaps: 0
File system inputs: 2096
File system outputs: 2096
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0
```

### 10K registros

```
User time (seconds): 0.00
System time (seconds): 0.00
Percent of CPU this job got: 57%
Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.00
Average shared text size (kbytes): 0
Average unshared data size (kbytes): 0
Average stack size (kbytes): 0
Average total size (kbytes): 0
Maximum resident set size (kbytes): 1792
Average resident set size (kbytes): 0
Major (requiring I/O) page faults: 0
Minor (reclaiming a frame) page faults: 171
Voluntary context switches: 2
Involuntary context switches: 0
Swaps: 0
File system inputs: 216
File system outputs: 216
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0
```

### 1K registros

```
User time (seconds): 0.00
System time (seconds): 0.00
Percent of CPU this job got: 18%
Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.01
Average shared text size (kbytes): 0
Average unshared data size (kbytes): 0
Average stack size (kbytes): 0
Average total size (kbytes): 0
Maximum resident set size (kbytes): 1536
Average resident set size (kbytes): 0
Major (requiring I/O) page faults: 0
Minor (reclaiming a frame) page faults: 84
Voluntary context switches: 1
Involuntary context switches: 1
Swaps: 0
File system inputs: 24
File system outputs: 24
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0
```

### 100 registros

```
User time (seconds): 0.00
System time (seconds): 0.00
Percent of CPU this job got: 0%
Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.00
Average shared text size (kbytes): 0
Average unshared data size (kbytes): 0
Average stack size (kbytes): 0
Average total size (kbytes): 0
Maximum resident set size (kbytes): 1408
Average resident set size (kbytes): 0
Major (requiring I/O) page faults: 0
Minor (reclaiming a frame) page faults: 73
Voluntary context switches: 0
Involuntary context switches: 0
Swaps: 0
File system inputs: 0
File system outputs: 0
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0
```