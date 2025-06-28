import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        TimSort timSort = new TimSort();
        ArrayList<Integer> arr = new ArrayList<>();



        DynamicStack stack = new DynamicStack(); 

        MyFileReader reader = new MyFileReader();
        arr = reader.lerTimestampsCSV("../../Samples/sample_1000000.csv");

        long inicio = System.nanoTime();
        for (Integer timestamp : arr) {
            stack.empilhar(new Registro(timestamp));
        }
        
        timSort.ordenarDynamicStack(stack);

        long fim = System.nanoTime();
        double tempo = (double) (fim - inicio) / 1e9;
        System.out.printf("Tempo de execucao: %.6f s%n", tempo);
        
        stack.salvarEmArquivo("../ordened/dynamicList/sample_1000000.csv");
    }
}

