# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2 -I src

# Caminhos
SRC_DIR = src
BUILD_DIR = build

# Arquivos-fonte e objetos
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Nome do executável
TARGET = main

# Regra padrão
all: $(TARGET)

# Como compilar o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Como compilar cada objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cria pasta build se não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Limpeza
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Roda o programa
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
