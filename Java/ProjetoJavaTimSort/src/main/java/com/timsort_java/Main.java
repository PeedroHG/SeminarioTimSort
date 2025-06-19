
package com.timsort_java;

import com.timsort_java.benchmarks.MainBenchmark;

import java.io.File;
import java.util.LinkedHashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) {
        // =========================================================================
        // ATENÇÃO: Configure o caminho para a pasta 'Samples' aqui
        // Por exemplo: samples_dir = "/caminho/completo/para/sua/pasta/Samples"
        // Se a pasta 'Samples' estiver no mesmo nível do diretório 'JavaProject', use:
        String samplesDir = "samples"; // Assuming 'samples' is a sibling of 'src'
        // =========================================================================

        String resultsDir = "results";

        // Create results directory if it doesn't exist
        new File(resultsDir).mkdirs();

        // Mapping of filenames to data sizes
        Map<String, Integer> dataFiles = new LinkedHashMap<>();
        dataFiles.put("sample_100.csv", 100);
        dataFiles.put("sample_1000.csv", 1000);
        dataFiles.put("sample_10000.csv", 10000);
        dataFiles.put("sample_100000.csv", 100000);
        dataFiles.put("sample_1000000.csv", 1000000);

        for (int i = 0; i < 10; i++) { // Loop 10 times as in Python script
            for (Map.Entry<String, Integer> entry : dataFiles.entrySet()) {
                String filename = entry.getKey();
                int size = entry.getValue();

                String dataFilepath = samplesDir + File.separator + filename;
                String outputFilePath = resultsDir + File.separator + "benchmark_results_" + size + ".csv";

                System.out.println(String.format("Processing %s with %d elements...", filename, size));
                MainBenchmark.runBenchmark(dataFilepath, outputFilePath);
            }
        }
    }
}


