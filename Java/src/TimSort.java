import java.util.*;

public class TimSort {

    private static final int MIN_MERGE = 32;

    private static int calcMinRun(int n) {
        int r = 0;
        while (n >= MIN_MERGE) {
            r |= (n & 1);
            n >>= 1;
        }
        return n + r;
    }

    private static void insertionSort(int[] arr, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int temp = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    private static void merge(int[] arr, int start, int mid, int end) {
        int[] left = Arrays.copyOfRange(arr, start, mid + 1);
        int[] right = Arrays.copyOfRange(arr, mid + 1, end + 1);

        int i = 0, j = 0, k = start;
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

    private static void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
    }

    public static void timsort(int[] arr, int n) {
        int minRun = calcMinRun(n);
        Stack<int[]> runs = new Stack<>();

        int i = 0;
        while (i < n) {
            int runStart = i;
            int runEnd = i + 1;

            if (runEnd == n) {
                runEnd = n;
            } else if (arr[runStart] <= arr[runEnd]) {
                while (runEnd < n - 1 && arr[runEnd] <= arr[runEnd + 1]) runEnd++;
            } else {
                while (runEnd < n - 1 && arr[runEnd] > arr[runEnd + 1]) runEnd++;
                reverse(arr, runStart, runEnd);
            }

            int runLen = runEnd - runStart + 1;
            if (runLen < minRun) {
                int forcedEnd = Math.min(n - 1, runStart + minRun - 1);
                insertionSort(arr, runStart, forcedEnd);
                runEnd = forcedEnd;
                runLen = runEnd - runStart + 1;
            }

            runs.push(new int[]{runStart, runLen});
            mergeCollapse(arr, runs);
            i = runEnd + 1;
        }

        mergeForceCollapse(arr, runs);
    }

    private static void mergeCollapse(int[] arr, Stack<int[]> runs) {
        while (runs.size() > 1) {
            int n = runs.size();
            int[] A = (n >= 3) ? runs.get(n - 3) : null;
            int[] B = runs.get(n - 2);
            int[] C = runs.get(n - 1);

            boolean condition1 = (A != null && A[1] <= B[1] + C[1]);
            boolean condition2 = (B[1] <= C[1]);

            if (condition1) {
                if (A[1] < C[1]) {
                    mergeAt(arr, runs, n - 3);
                } else {
                    mergeAt(arr, runs, n - 2);
                }
            } else if (condition2) {
                mergeAt(arr, runs, n - 2);
            } else {
                break;
            }
        }
    }

    private static void mergeForceCollapse(int[] arr, Stack<int[]> runs) {
        while (runs.size() > 1) {
            int n = runs.size();
            mergeAt(arr, runs, n - 2);
        }
    }

    private static void mergeAt(int[] arr, Stack<int[]> runs, int i) {
        int[] run1 = runs.get(i);
        int[] run2 = runs.get(i + 1);

        int start1 = run1[0], len1 = run1[1];
        int start2 = run2[0], len2 = run2[1];

        merge(arr, start1, start1 + len1 - 1, start2 + len2 - 1);

        runs.set(i, new int[]{start1, len1 + len2});
        runs.remove(i + 1);
    }

    // ======== Métodos de ordenação para suas estruturas ========

    public void ordenarStaticList(StaticList l) {
        if (l.tamanho > 1) {
            int[] arr = new int[l.tamanho];
            for (int i = 0; i < l.tamanho; i++) {
                arr[i] = l.elementos[i].valor;
            }

            timsort(arr, l.tamanho);

            for (int i = 0; i < l.tamanho; i++) {
                l.elementos[i].valor = arr[i];
            }
        }
    }

    public void ordenarStaticQueue(StaticQueue q) {
        if (q.size > 1) {
            int[] arr = new int[q.size];
            int idx = q.head;
            for (int i = 0; i < q.size; i++) {
                arr[i] = q.elementos[idx].valor;
                idx = (idx + 1) % q.capacidade;
            }

            timsort(arr, q.size);

            idx = q.head;
            for (int i = 0; i < q.size; i++) {
                q.elementos[idx].valor = arr[i];
                idx = (idx + 1) % q.capacidade;
            }
        }
    }

    public void ordenarStaticStack(StaticStack s) {
        if (s.topo > 0) {
            int[] arr = new int[s.topo + 1];
            for (int i = 0; i <= s.topo; i++) {
                arr[i] = s.elementos[i].valor;
            }

            timsort(arr, s.topo + 1);

            for (int i = 0; i <= s.topo; i++) {
                s.elementos[i].valor = arr[i];
            }
        }
    }

    public void ordenarDynamicList(DynamicList l) {
        if (l.size > 1) {
            int[] arr = new int[l.size];
            Node aux = l.head;
            for (int i = 0; i < l.size && aux != null; i++) {
                arr[i] = aux.valor.valor;
                aux = aux.prox;
            }

            timsort(arr, l.size);

            aux = l.head;
            for (int i = 0; i < l.size && aux != null; i++) {
                aux.valor.valor = arr[i];
                aux = aux.prox;
            }
        }
    }

    public void ordenarDynamicStack(DynamicStack s) {
        if (s.size > 1) {
            int[] arr = new int[s.size];
            Node atual = s.topo;
            for (int i = 0; i < s.size && atual != null; i++) {
                arr[i] = atual.valor.valor;
                atual = atual.prox;
            }

            timsort(arr, s.size);

            atual = s.topo;
            for (int i = 0; i < s.size && atual != null; i++) {
                atual.valor.valor = arr[i];
                atual = atual.prox;
            }
        }
    }

    public void ordenarDynamicQueue(DynamicQueue q) {
        if (q.size > 1) {
            int[] arr = new int[q.size];
            Node atual = q.head;
            for (int i = 0; i < q.size && atual != null; i++) {
                arr[i] = atual.valor.valor;
                atual = atual.prox;
            }

            timsort(arr, q.size);

            atual = q.head;
            for (int i = 0; i < q.size && atual != null; i++) {
                atual.valor.valor = arr[i];
                atual = atual.prox;
            }
        }
    }
}
