# Diretórios
SRC_DIR = src
OBJ_DIR = obj

# Arquivos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
EXEC = main

# Compilador e flags
CC = gcc
CFLAGS = -Wall -O2

# Regra padrão
all: $(EXEC)

# Linkagem final
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilação dos .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Executar o programa
run: $(EXEC)
	./$(EXEC)

# Limpar os arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(EXEC)
