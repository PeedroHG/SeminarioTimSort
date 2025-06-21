import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

public class StaticListTs {
    public static void main(String[] args) throws InterruptedException {
        TimSort timSort = new TimSort();
        ArrayList<Integer> arr = new ArrayList<>(); 
        DynamicStack pilha = new DynamicStack(); 

        MyFileReader reader = new MyFileReader();
        arr = reader.lerTimestampsCSV("../../Samples/sample_1000000.csv");

        long inicio = System.nanoTime();
        for (Integer timestamp : arr) {
            pilha.empilhar(new Registro(timestamp));
        }
        
        timSort.ordenarDynamicStack(pilha);

        long fim = System.nanoTime();
        double tempo = (double) (fim - inicio) / 1e9;
        System.out.printf("Tempo de execucao: %.6f s%n", tempo);
        
        pilha.salvarEmArquivo("../ordened/dynamicStack/sample_1000000.csv");
    }
}

