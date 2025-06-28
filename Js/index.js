const fs = require('fs');
const path = require('path');
const { LinkedStack, LinkedQueue, LinkedList } = require('./linked_based');
const { ArrayList, ArrayQueue, ArrayStack } = require('./array_based');
const { timsort } = require('./timsort');          

const tam = 1000000;

function lerTimestampsCSV(nomeArquivo) {
  const content = fs.readFileSync(nomeArquivo, 'utf-8');
  const linhas = content.split('\n');
  const timestamps = [];

  // Pula o cabeçalho (linha 0)
  for (let i = 1; i < linhas.length; i++) {
    const linha = linhas[i].trim();
    if (linha) {
      // Supondo que o timestamp está na primeira coluna
      timestamps.push(parseInt(linha.split(',')[0], 10));
    }
  }
  return timestamps;
}

async function main() {
  const inputPath = path.join('..', 'Samples', `sample_${tam}.csv`);
  const outputDir = path.join('.', 'ordened', 'dynamic_queue');
  const outputPath = path.join(outputDir, `sample_${tam}.csv`);

  if (!fs.existsSync(outputDir)) {
    fs.mkdirSync(outputDir, { recursive: true });
  }

  // Lê CSV
  const timestamps = lerTimestampsCSV(inputPath);

  const linkedQueue = new LinkedQueue();

  // Começa a contar tempo
  const start = process.hrtime.bigint();

  // Passa pra estrutura
  for (const t of timestamps) {
    linkedQueue.enqueue(t);
  }

  // Transforma em array normal
  const normalList = linkedQueue.toList();

  // Ordena
  timsort(normalList);

  // Limpa estrutura e copia ordenado
  linkedQueue.clear();
  for (const t of normalList) {
    linkedQueue.enqueue(t);
  }

  // Termina de contar tempo
  const end = process.hrtime.bigint();

  const tempoExecucao = Number(end - start) / 1_000_000_000; // converte nanosegundos para segundos
  console.log(`Tempo de execução: ${tempoExecucao.toFixed(6)} segundos`);

  // Salva resultado em CSV
  linkedQueue.saveToCSV(outputPath);
}

main().catch(console.error);
