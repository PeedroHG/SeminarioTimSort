public class DynamicQueue {
    protected Node head;
    protected Node tail;
    protected int size;

    public DynamicQueue() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public boolean enfileirar(Registro valor) {
        Node novo = new Node(valor);

        if (this.tail == null) {
            this.head = novo;
            this.tail = novo;
        } else {
            this.tail.prox = novo;
            this.tail = novo;
        }

        this.size++;
        return true;
    }

    public Registro desenfileirar() {
        if (filaVazia()) return null;

        Node remover = this.head;
        Registro valor = remover.valor;
        this.head = remover.prox;
        if (this.head == null)
            this.tail = null;

        this.size--;
        return valor;
    }

    public boolean filaVazia() {
        return this.size == 0;
    }

    public void imprimir() {
        Node atual = this.head;
        while (atual != null) {
            System.out.print(atual.valor.valor + " ");
            atual = atual.prox;
        }
        System.out.println();
    }

    public void salvarEmArquivo(String nomeArquivo) {
        try (java.io.FileWriter writer = new java.io.FileWriter(nomeArquivo)) {
            Node atual = this.head;
            while (atual != null) {
                writer.write(atual.valor.valor + "\n");
                atual = atual.prox;
            }
        } catch (java.io.IOException e) {
            System.err.println("Erro ao abrir arquivo para escrita: " + e.getMessage());
        }
    }
}

