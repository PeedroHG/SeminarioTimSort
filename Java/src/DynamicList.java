public class DynamicList {
    protected Node head;
    protected Node tail;
    protected int size;

    public DynamicList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public boolean inserirFim(Registro valor) {
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

    public Registro removerInicio() {
        if (this.head == null) return null; // lista vazia

        Registro valor = this.head.valor;
       // Node temp = this.head;
        this.head = this.head.prox;

        if (this.head == null) {
            this.tail = null;
        }

        // Em Java, o garbage collector lida com a desalocação de memória
        // free(temp);
        this.size--;
        return valor;
    }

    public void imprimir() {
        Node current = this.head;
        while (current != null) {
            System.out.print(current.valor.valor + " ");
            current = current.prox;
        }
        System.out.println();
    }

    public void salvarEmArquivo(String nomeArquivo) {
        try (java.io.FileWriter writer = new java.io.FileWriter(nomeArquivo)) {
            Node current = this.head;
            while (current != null) {
                writer.write(current.valor.valor + "\n");
                current = current.prox;
            }
        } catch (java.io.IOException e) {
            System.err.println("Erro ao abrir o arquivo para escrita: " + e.getMessage());
        }
    }
}

