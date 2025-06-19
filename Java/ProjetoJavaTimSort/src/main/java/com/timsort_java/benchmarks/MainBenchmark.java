package com.timsort_java.benchmarks;

import com.timsort_java.structures.ArrayList;
import com.timsort_java.structures.ArrayQueue;
import com.timsort_java.structures.ArrayStack;
import com.timsort_java.structures.LinkedList;
import com.timsort_java.structures.LinkedQueue;
import com.timsort_java.structures.LinkedStack;
import com.timsort_java.timsort_logic.TimSort;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.function.Consumer;

public class MainBenchmark {

    public static void runBenchmark(String dataFilepath, String outputFilePath) {
        int[] data = BenchmarkUtils.loadDataFromCsv(dataFilepath);

        Map<String, Object> structures = new LinkedHashMap<>();
        structures.put("ArrayList", new ArrayList());
        structures.put("ArrayQueue", new ArrayQueue());
        structures.put("ArrayStack", new ArrayStack());
        structures.put("LinkedList", new LinkedList());
        structures.put("LinkedQueue", new LinkedQueue());
        structures.put("LinkedStack", new LinkedStack());

        // Clear the output file for each new benchmark run (as in Python, it appends a new table)
        // This is a slight deviation from Python's 'a' mode, but necessary to prevent duplicate headers
        // and ensure each run starts fresh for its set of results.
        // The Python script adds a newline, effectively starting a new table for each run.
        // Here, we'll append a newline before writing the new set of results if the file is not empty.
        try (PrintWriter writer = new PrintWriter(new FileWriter(outputFilePath, true))) {
            if (new File(outputFilePath).length() > 0) {
                writer.println(); // Add a newline if file is not empty
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (Map.Entry<String, Object> entry : structures.entrySet()) {
            String name = entry.getKey();
            Object structure = entry.getValue();

            System.out.println(String.format("Running benchmark for %s with %d elements...", name, data.length));

            // Copy data to a fresh structure for each benchmark run
            BenchmarkUtils.copyArrayToStructure(data, structure);

            // Create a Consumer for the TimSort function
            Consumer<int[]> timsortConsumer = arr -> TimSort.timsort(arr);

            double[] performance = BenchmarkUtils.measurePerformance(timsortConsumer, structure);
            double timeTaken = performance[0];
            double memoryUsed = performance[1];

            BenchmarkUtils.writeResultsToCsv(outputFilePath, name, data.length, timeTaken, memoryUsed);
            System.out.println(String.format("  Time: %.6f seconds, Memory: %.4f MB", timeTaken, memoryUsed));
        }

        System.out.println(String.format("Benchmark results saved to %s", outputFilePath));
    }
}


