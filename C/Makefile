CC = gcc
CFLAGS = -I src -Wall -Wextra -O2

# Fontes principais compartilhadas
SRCS = src/dynamic_list.c src/dynamic_stack.c src/dynamic_queue.c src/static_list.c src/static_queue.c src/static_stack.c src/file_reader.c src/tim_sort.c

# Alvos disponíveis
TARGETS = dynamic_list_ts dynamic_stack_ts dynamic_queue_ts static_list_ts static_queue_ts static_stack_ts

# Regras principais
all: $(TARGETS)

dynamic_list_ts: src/dynamic_list_ts.c $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

dynamic_stack_ts: src/dynamic_stack_ts.c $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

dynamic_queue_ts: src/dynamic_queue_ts.c $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

static_list_ts: src/static_list_ts.c $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

static_queue_ts: src/static_queue_ts.c $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

static_stack_ts: src/static_stack_ts.c $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

# Alvos específicos
stack: dynamic_stack_ts static_stack_ts
queue: dynamic_queue_ts static_queue_ts
list: dynamic_list_ts static_list_ts

# Limpar binários
clean:
	rm -f $(TARGETS) *.o

.PHONY: all clean stack queue list
