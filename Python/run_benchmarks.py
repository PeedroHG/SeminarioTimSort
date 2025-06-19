from benchmarks.main_benchmark import run_benchmark
import os

def main():
    # =========================================================================
    # ATENÇÃO: Configure o caminho para a pasta 'Samples' aqui
    # Por exemplo: samples_dir = "/caminho/completo/para/sua/pasta/Samples"
    # Se a pasta 'Samples' estiver no mesmo nível do diretório 'Python', use:
    samples_dir = "../SamplesR"
    # =========================================================================

    results_dir = "results"

    os.makedirs(results_dir, exist_ok=True)

    # Mapeamento de nomes de arquivos para tamanhos de dados
    data_files = {
        "sample_100.csv": 100,
        "sample_1000.csv": 1000,
        "sample_10000.csv": 10000,
        "sample_100000.csv": 100000,
        "sample_1000000.csv": 1000000
    }
 
    for _ in range(10):
        for filename, size in data_files.items():
            data_filepath = os.path.join(samples_dir, filename)
            output_filepath = os.path.join(results_dir, f"benchmark_results_{size}.csv")
            print(f"Processing {filename} with {size} elements...")
            run_benchmark(data_filepath, output_filepath)

if __name__ == "__main__":
    main()


