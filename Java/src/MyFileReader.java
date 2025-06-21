import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class MyFileReader {

    public ArrayList<Integer> lerTimestampsCSV(String nomeArquivo) {
        ArrayList<Integer> timestamps = new ArrayList<>();
        
        try (BufferedReader br = new BufferedReader(new FileReader(nomeArquivo))) {
            String linha;
            br.readLine(); // Ignora o cabeçalho
            while ((linha = br.readLine()) != null) {
                String[] valores = linha.split(",");
                if (valores.length > 0) {
                    timestamps.add(Integer.parseInt(valores[0])); // Supondo que o timestamp está na primeira coluna
                }
            }
        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
        }
        
        return timestamps;
    }
    
}
