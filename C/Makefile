CC = gcc
CFLAGS = -I src -Wall -Wextra -O2

SRCS = src/static_list.c src/static_queue.c src/static_stack.c src/file_reader.c src/tim_sort.c

# Executáveis
TARGETS = static_list_ts static_queue_ts static_stack_ts

# Dependências dos sources para cada target (basicamente os mesmos)
STATIC_LIST_TS_SRCS = src/static_list_ts.c $(SRCS)
STATIC_QUEUE_TS_SRCS = src/static_queue_ts.c $(SRCS)
STATIC_STACK_TS_SRCS = src/static_stack_ts.c $(SRCS)

all: $(TARGETS)

static_list_ts: $(STATIC_LIST_TS_SRCS)
	$(CC) $(CFLAGS) -o $@ $^

static_queue_ts: $(STATIC_QUEUE_TS_SRCS)
	$(CC) $(CFLAGS) -o $@ $^

static_stack_ts: $(STATIC_STACK_TS_SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS) *.o

.PHONY:
