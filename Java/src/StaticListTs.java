import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

public class StaticListTs {
    public static void main(String[] args) throws InterruptedException {
        TimSort timSort = new TimSort();
        ArrayList<Integer> arr = new ArrayList<>(); 
        StaticList lista = new StaticList(1000000); 

        MyFileReader reader = new MyFileReader();
        arr = reader.lerTimestampsCSV("../../Samples/sample_1000000.csv");

        long inicio = System.nanoTime();
        for (Integer timestamp : arr) {
            lista.inserirFim(new Registro(timestamp));
        }
        
        timSort.ordenarStaticList(lista);

        long fim = System.nanoTime();
        long tempo = fim - inicio;
        System.out.println("Tempo de execucao: " + TimeUnit.NANOSECONDS.toMillis(tempo) + " ms");
        
        lista.salvarEmArquivo("sample_1000000_ordenado.csv");
    }
}

