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
    let j = i;
    while (j > left && arr[j] < arr[j - 1]) {
      [arr[j], arr[j - 1]] = [arr[j - 1], arr[j]]; // swap
      j--;
    }
  }
}

function merge(arr, l, m, r) {
  const len1 = m - l + 1;
  const len2 = r - m;
  const left = [];
  const right = [];

  for (let i = 0; i < len1; i++) left.push(arr[l + i]);
  for (let i = 0; i < len2; i++) right.push(arr[m + 1 + i]);

  let i = 0, j = 0, k = l;

  while (i < len1 && j < len2) {
    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }

  while (i < len1) arr[k++] = left[i++];
  while (j < len2) arr[k++] = right[j++];
}

function timsort(arr) {
  const n = arr.length;
  const minRun = calcMinRun(n);

  for (let i = 0; i < n; i += minRun) {
    insertionSort(arr, i, Math.min(i + MIN_MERGE - 1, n - 1));
  }

  let size = minRun;
  while (size < n) {
    for (let left = 0; left < n; left += 2 * size) {
      const mid = Math.min(left + size - 1, n - 1);
      const right = Math.min(left + 2 * size - 1, n - 1);
      if (mid < right) {
        merge(arr, left, mid, right);
      }
    }
    size *= 2;
  }
}

module.exports = { timsort };
