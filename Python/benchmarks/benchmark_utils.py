import csv
import time
import tracemalloc
import sys

def load_data_from_csv(filepath):
    data = []
    with open(filepath, 'r') as f:
        reader = csv.reader(f)
        next(reader)  # Skip header row
        for row in reader:
            data.append(float(row[0]))
    return data

def copy_array_to_structure(arr, structure):
    structure.from_list(arr)

def copy_structure_to_array(structure):
    return structure.to_list()

def copy_array_to_structure_back(arr, structure):
    structure.from_list(arr)

def measure_performance(sort_function, structure):
    tracemalloc.start()
    start_time = time.perf_counter()


    # Copy data from structure to auxiliary array
    aux_array = structure.to_list()
    print('1')
    # Execute TimSort on auxiliary array
    sort_function(aux_array)
    print('2')
    # Copy sorted data back to original structure
    structure.from_list(aux_array)
    print('3')
    
    end_time = time.perf_counter()
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()

    time_taken = end_time - start_time
    memory_used = peak / (1024 * 1024)  # Convert to MB

    return time_taken, memory_used


