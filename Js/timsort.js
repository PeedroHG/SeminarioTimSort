const MIN_MERGE = 32;

function calcMinRun(n) {
  let r = 0;
  while (n >= MIN_MERGE) {
    r |= n & 1;
    n >>= 1;
  }
  return n + r;
}

function insertionSort(arr, left, right) {
  for (let i = left + 1; i <= right; i++) {
    const temp = arr[i];
    let j = i - 1;
    while (j >= left && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

function merge(arr, start, mid, end) {
  const left = arr.slice(start, mid + 1);
  const right = arr.slice(mid + 1, end + 1);

  let i = 0, j = 0, k = start;
  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }
  while (i < left.length) arr[k++] = left[i++];
  while (j < right.length) arr[k++] = right[j++];
}

class TimSort {
  constructor(arr) {
    this.arr = arr;
    this.n = arr.length;
    this.minRun = calcMinRun(this.n);
    this.runs = []; // stack of [start, length]
  }

  sort() {
    let i = 0;
    while (i < this.n) {
      let runStart = i;
      let runEnd = i + 1;

      // Detecta se é crescente ou decrescente
      if (runEnd === this.n) {
        runEnd = this.n;
      } else if (this.arr[runStart] <= this.arr[runEnd]) {
        while (runEnd < this.n - 1 && this.arr[runEnd] <= this.arr[runEnd + 1]) {
          runEnd++;
        }
      } else {
        while (runEnd < this.n - 1 && this.arr[runEnd] > this.arr[runEnd + 1]) {
          runEnd++;
        }
        this.reverse(runStart, runEnd);
      }

      let runLen = runEnd - runStart + 1;

      if (runLen < this.minRun) {
        const forcedEnd = Math.min(this.n - 1, runStart + this.minRun - 1);
        insertionSort(this.arr, runStart, forcedEnd);
        runEnd = forcedEnd;
        runLen = runEnd - runStart + 1;
      }

      this.runs.push([runStart, runLen]);
      this.mergeCollapse();

      i = runEnd + 1;
    }

    this.mergeForceCollapse();
  }

  reverse(start, end) {
    while (start < end) {
      [this.arr[start], this.arr[end]] = [this.arr[end], this.arr[start]];
      start++;
      end--;
    }
  }

  mergeCollapse() {
    while (this.runs.length > 1) {
      const n = this.runs.length;
      const A = n >= 3 ? this.runs[n - 3] : null;
      const B = this.runs[n - 2];
      const C = this.runs[n - 1];

      if (n >= 3 && A[1] <= B[1] + C[1]) {
        if (A[1] < C[1]) {
          this.mergeAt(n - 3);
        } else {
          this.mergeAt(n - 2);
        }
      } else if (B[1] <= C[1]) {
        this.mergeAt(n - 2);
      } else {
        break;
      }
    }
  }

  mergeForceCollapse() {
    while (this.runs.length > 1) {
      const n = this.runs.length;
      this.mergeAt(n - 2);
    }
  }

  mergeAt(i) {
    const [start1, len1] = this.runs[i];
    const [start2, len2] = this.runs[i + 1];

    merge(this.arr, start1, start1 + len1 - 1, start2 + len2 - 1);

    this.runs[i] = [start1, len1 + len2];
    this.runs.splice(i + 1, 1);
  }
}

function timsort(arr) {
  const sorter = new TimSort(arr);
  sorter.sort();
}

module.exports = { timsort };
