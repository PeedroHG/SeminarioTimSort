
public class StaticQueue {
    protected Registro[] elementos;
    protected int head;
    protected int tail;
    protected int size;
    protected int capacidade;

    public StaticQueue(int capacidade) {
        this.capacidade = capacidade;
        this.elementos = new Registro[capacidade];
        this.head = 0;
        this.tail = -1;
        this.size = 0;
    }

    public boolean enfileirar(Registro valor) {
        if (this.size == this.capacidade) return false; // Fila cheia

        this.tail = (this.tail + 1) % this.capacidade;
        this.elementos[this.tail] = valor;
        this.size++;
        return true;
    }

    public Registro desenfileirar() {
        if (filaVazia()) return null; // Fila vazia

        Registro valorRemovido = this.elementos[this.head];
        this.head = (this.head + 1) % this.capacidade;
        this.size--;
        return valorRemovido;
    }

    public boolean filaVazia() {
        return this.size == 0;
    }

    public void imprimir() {
        if (filaVazia()) {
            System.out.println("Fila vazia.");
            return;
        }
        for (int i = 0; i < this.size; i++) {
            System.out.print(this.elementos[(this.head + i) % this.capacidade].valor + " ");
        }
        System.out.println();
    }

    public void salvarEmArquivo(String nomeArquivo) {
        try (java.io.FileWriter writer = new java.io.FileWriter(nomeArquivo)) {
            for (int i = 0; i < this.size; i++) {
                writer.write(this.elementos[(this.head + i) % this.capacidade].valor + "\n");
            }
        } catch (java.io.IOException e) {
            System.err.println("Erro ao abrir arquivo para escrita: " + e.getMessage());
        }
    }
}

