public class StaticList {
    protected Registro[] elementos;
    protected int tamanho;
    protected int capacidade;

    public StaticList(int capacidade) {
        this.capacidade = capacidade;
        this.elementos = new Registro[capacidade];
        this.tamanho = 0;
    }

    public boolean inserirFim(Registro valor) {
        if (this.tamanho < this.capacidade) {
            this.elementos[this.tamanho] = valor;
            this.tamanho++;
            return true;
        }
        return false; // Lista cheia
    }

    public Registro removerInicio() {
        if (this.tamanho == 0) return null; // Lista vazia

        Registro valorRemovido = this.elementos[0];
        for (int i = 0; i < this.tamanho - 1; i++) {
            this.elementos[i] = this.elementos[i + 1];
        }
        this.tamanho--;
        return valorRemovido;
    }

    public void imprimir() {
        for (int i = 0; i < this.tamanho; i++) {
            System.out.print(this.elementos[i].valor + " ");
        }
        System.out.println();
    }

    public void salvarEmArquivo(String nomeArquivo) {
        try (java.io.FileWriter writer = new java.io.FileWriter(nomeArquivo)) {
            System.out.println("Salvando em " + nomeArquivo);
            for (int i = 0; i < this.tamanho; i++) {
                writer.write(this.elementos[i].valor + "\n");
            }
        } catch (java.io.IOException e) {
            System.err.println("Erro ao abrir o arquivo para escrita: " + e.getMessage());
        }
    }
}

