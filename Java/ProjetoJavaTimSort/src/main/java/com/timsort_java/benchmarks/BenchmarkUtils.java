package com.timsort_java.benchmarks;

import com.timsort_java.structures.ArrayList;
import com.timsort_java.structures.ArrayQueue;
import com.timsort_java.structures.ArrayStack;
import com.timsort_java.structures.LinkedList;
import com.timsort_java.structures.LinkedQueue;
import com.timsort_java.structures.LinkedStack;
import com.timsort_java.timsort_logic.TimSort;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.management.ManagementFactory;
import java.lang.management.MemoryMXBean;
import java.lang.management.MemoryUsage;
import java.util.Arrays;
import java.util.function.Consumer;

public class BenchmarkUtils {

    public static int[] loadDataFromCsv(String filepath) {
        java.util.ArrayList<Integer> data = new java.util.ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filepath))) {
            String line;
            while ((line = br.readLine()) != null) {
                data.add(Integer.parseInt(line.trim()));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return data.stream().mapToInt(i -> i).toArray();
    }

    public static void copyArrayToStructure(int[] data, Object structure) {
        if (structure instanceof ArrayList) {
            ((ArrayList) structure).fromArray(data);
        } else if (structure instanceof ArrayQueue) {
            // Clear existing elements
            while (!((ArrayQueue) structure).isEmpty()) {
                ((ArrayQueue) structure).dequeue();
            }
            for (int item : data) {
                ((ArrayQueue) structure).enqueue(item);
            }
        } else if (structure instanceof ArrayStack) {
            // Clear existing elements
            while (!((ArrayStack) structure).isEmpty()) {
                ((ArrayStack) structure).pop();
            }
            for (int item : data) {
                ((ArrayStack) structure).push(item);
            }
        } else if (structure instanceof LinkedList) {
            ((LinkedList) structure).fromArray(data);
        } else if (structure instanceof LinkedQueue) {
            // Clear existing elements
            while (!((LinkedQueue) structure).isEmpty()) {
                ((LinkedQueue) structure).dequeue();
            }
            for (int item : data) {
                ((LinkedQueue) structure).enqueue(item);
            }
        } else if (structure instanceof LinkedStack) {
            // Clear existing elements
            while (!((LinkedStack) structure).isEmpty()) {
                ((LinkedStack) structure).pop();
            }
            for (int item : data) {
                ((LinkedStack) structure).push(item);
            }
        }
    }

    public static double[] measurePerformance(Consumer<int[]> sortFunction, Object structure) {
        long startTime = System.nanoTime();

        MemoryMXBean memoryBean = ManagementFactory.getMemoryMXBean();
        MemoryUsage beforeHeap = memoryBean.getHeapMemoryUsage();

        int[] arrayToSort = null;

        if (structure instanceof ArrayList) {
            arrayToSort = ((ArrayList) structure).toArray();
        } else if (structure instanceof ArrayQueue) {
            arrayToSort = ((ArrayQueue) structure).toArray();
        } else if (structure instanceof ArrayStack) {
            arrayToSort = ((ArrayStack) structure).toArray();
        } else if (structure instanceof LinkedList) {
            arrayToSort = ((LinkedList) structure).toArray();
        } else if (structure instanceof LinkedQueue) {
            arrayToSort = ((LinkedQueue) structure).toArray();
        } else if (structure instanceof LinkedStack) {
            arrayToSort = ((LinkedStack) structure).toArray();
        }

        if (arrayToSort != null) {
            sortFunction.accept(arrayToSort);
        }

        long endTime = System.nanoTime();
        MemoryUsage afterHeap = memoryBean.getHeapMemoryUsage();

        double timeTaken = (endTime - startTime) / 1_000_000_000.0; // seconds
        double memoryUsed = (afterHeap.getUsed() - beforeHeap.getUsed()) / (1024.0 * 1024.0); // MB

        return new double[]{timeTaken, memoryUsed};
    }

    public static void writeResultsToCsv(String outputFilePath, String structureName, int dataSize, double timeTaken, double memoryUsedMb) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(outputFilePath, true))) {
            // Check if file is empty to write header
            if (new java.io.File(outputFilePath).length() == 0) {
                writer.println("structure,data_size,time_taken,memory_used_mb");
            }
            writer.printf("%s,%d,%.6f,%.4f%n", structureName, dataSize, timeTaken, memoryUsedMb);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


