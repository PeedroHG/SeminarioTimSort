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
  const outputDir = path.join('.', 'ordened', 'dynamic_stack');
  const outputPath = path.join(outputDir, `sample_${tam}.csv`);

  if (!fs.existsSync(outputDir)) {
    fs.mkdirSync(outputDir, { recursive: true });
  }

  // Lê CSV
  const timestamps = lerTimestampsCSV(inputPath);

  const linkedStack = new LinkedStack();

  // Começa a contar tempo
  const start = process.hrtime.bigint();

  // Passa pra estrutura
  for (const t of timestamps) {
    linkedStack.push(t);
  }

  // Transforma em array normal
  const normalList = linkedStack.toList();

  // Ordena
  timsort(normalList);

  // Limpa estrutura e copia ordenado
  linkedStack.clear();
  for (const t of normalList) {
    linkedStack.push(t);
  }

  // Termina de contar tempo
  const end = process.hrtime.bigint();

  const tempoExecucao = Number(end - start) / 1_000_000_000; // converte nanosegundos para segundos
  console.log(`Tempo de execução: ${tempoExecucao.toFixed(6)} segundos`);

  // Salva resultado em CSV
  linkedStack.saveToCSV(outputPath);
}

main().catch(console.error);
