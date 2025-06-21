
public class StaticStack {
    protected Registro[] elementos;
    protected int topo;
    protected int capacidade;

    public StaticStack(int capacidade) {
        this.capacidade = capacidade;
        this.elementos = new Registro[capacidade];
        this.topo = -1;
    }

    public boolean empilhar(Registro valor) {
        if (this.topo == this.capacidade - 1) return false; // Pilha cheia

        this.topo++;
        this.elementos[this.topo] = valor;
        return true;
    }

    public Registro desempilhar() {
        if (pilhaVazia()) return null; // Pilha vazia

        Registro valorRemovido = this.elementos[this.topo];
        this.topo--;
        return valorRemovido;
    }

    public boolean pilhaVazia() {
        return this.topo == -1;
    }

    public void imprimir() {
        if (pilhaVazia()) {
            System.out.println("Pilha vazia.");
            return;
        }
        for (int i = this.topo; i >= 0; i--) {
            System.out.print(this.elementos[i].valor + " ");
        }
        System.out.println();
    }

    public void salvarEmArquivo(String nomeArquivo) {
        try (java.io.FileWriter writer = new java.io.FileWriter(nomeArquivo)) {
            for (int i = this.topo; i >= 0; i--) {
                writer.write(this.elementos[i].valor + "\n");
            }
        } catch (java.io.IOException e) {
            System.err.println("Erro ao abrir arquivo para escrita: " + e.getMessage());
        }
    }
}

