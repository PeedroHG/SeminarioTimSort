
public class TimSort {

    private static final int RUN = 32;

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

    private static void merge(int[] arr, int l, int m, int r) {
        int len1 = m - l + 1, len2 = r - m;
        int[] left = new int[len1];
        int[] right = new int[len2];

        for (int i = 0; i < len1; i++) {
            left[i] = arr[l + i];
        }
        for (int i = 0; i < len2; i++) {
            right[i] = arr[m + 1 + i];
        }

        int i = 0, j = 0, k = l;

        while (i < len1 && j < len2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < len1) {
            arr[k++] = left[i++];
        }
        while (j < len2) {
            arr[k++] = right[j++];
        }
    }

    public static void timsort(int[] arr, int n) {
        for (int i = 0; i < n; i += RUN) {
            int right = Math.min((i + RUN - 1), (n - 1));
            insertionSort(arr, i, right);
        }

        for (int size = RUN; size < n; size = 2 * size) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = Math.min((left + 2 * size - 1), (n - 1));

                if (mid < right) {
                    merge(arr, left, mid, right);
                }
            }
        }
    }

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
