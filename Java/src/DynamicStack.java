
public class DynamicStack {
    protected Node topo;
    protected int size;

    public DynamicStack() {
        this.topo = null;
        this.size = 0;
    }

    public boolean empilhar(Registro valor) {
        Node novo = new Node(valor);
        novo.prox = this.topo;
        this.topo = novo;
        this.size++;
        return true;
    }

    public Registro desempilhar() {
        if (pilhaVazia()) return null;

        Node remover = this.topo;
        Registro valor = remover.valor;
        this.topo = remover.prox;
        // Em Java, o garbage collector lida com a desalocação de memória
        // free(remover);
        this.size--;
        return valor;
    }

    public boolean pilhaVazia() {
        return this.size == 0;
    }

    public void imprimir() {
        Node atual = this.topo;
        while (atual != null) {
            System.out.print(atual.valor.valor + " ");
            atual = atual.prox;
        }
        System.out.println();
    }

    public void salvarEmArquivo(String nomeArquivo) {
        try (java.io.FileWriter writer = new java.io.FileWriter(nomeArquivo)) {
            Node atual = this.topo;
            while (atual != null) {
                writer.write(atual.valor.valor + "\n");
                atual = atual.prox;
            }
        } catch (java.io.IOException e) {
            System.err.println("Erro ao abrir arquivo para escrita: " + e.getMessage());
        }
    }
}

