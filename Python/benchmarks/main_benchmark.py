from timsort.timsort import timsort
from structures.array_based import ArrayList, ArrayQueue, ArrayStack
from structures.linked_based import LinkedList, LinkedQueue, LinkedStack
from benchmarks.benchmark_utils import load_data_from_csv, copy_array_to_structure, measure_performance
import os
import csv

def run_benchmark(data_filepath, output_filepath):
    data = load_data_from_csv(data_filepath)
    results = []

    structures = {
        "ArrayList": ArrayList(),
        "ArrayQueue": ArrayQueue(),
        "ArrayStack": ArrayStack(),
        "LinkedList": LinkedList(),
        "LinkedQueue": LinkedQueue(),
        "LinkedStack": LinkedStack()
    }

    for name, structure in structures.items():
        print(f"Running benchmark for {name} with {len(data)} elements...")
        copy_array_to_structure(data, structure)
        time_taken, memory_used = measure_performance(timsort, structure)
        results.append({
            "structure": name,
            "data_size": len(data),
            "time_taken": time_taken,
            "memory_used_mb": memory_used
        })
        print(f"  Time: {time_taken:.6f} seconds, Memory: {memory_used:.4f} MB")

    # Append results to CSV
    with open(output_filepath, 'a', newline='') as csvfile:
        fieldnames = ["structure", "data_size", "time_taken", "memory_used_mb"]
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

        if os.path.getsize(output_filepath) == 0:
            writer.writeheader()

        csvfile.write("\n")  # Add an empty line between each table

        for row in results:
            writer.writerow(row)

    print(f"Benchmark results saved to {output_filepath}")


