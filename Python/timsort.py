MIN_MERGE = 32

def calc_min_run(n):
    r = 0
    while n >= MIN_MERGE:
        r |= n & 1
        n >>= 1
    return n + r

def insertion_sort(arr, left, right):
    for i in range(left + 1, right + 1):
        temp = arr[i]
        j = i - 1
        while j >= left and arr[j] > temp:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = temp

def merge(arr, start, mid, end):
    left = arr[start:mid + 1]
    right = arr[mid + 1:end + 1]
    len_left, len_right = len(left), len(right)

    i = j = 0
    k = start

    while i < len_left and j < len_right:
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    while i < len_left:
        arr[k] = left[i]
        i += 1
        k += 1
    while j < len_right:
        arr[k] = right[j]
        j += 1
        k += 1

class TimSort:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)
        self.min_run = calc_min_run(self.n)
        self.runs = []  # stack of (start, length)

    def sort(self):
        i = 0
        while i < self.n:
            run_start = i
            run_end = i + 1

            # Detect run direction (ascending or descending)
            if run_end == self.n:
                run_end = self.n
            elif self.arr[run_start] <= self.arr[run_end]:
                while run_end < self.n - 1 and self.arr[run_end] <= self.arr[run_end + 1]:
                    run_end += 1
            else:
                while run_end < self.n - 1 and self.arr[run_end] > self.arr[run_end + 1]:
                    run_end += 1
                # Reverse descending run
                self.arr[run_start:run_end + 1] = reversed(self.arr[run_start:run_end + 1])

            run_len = run_end - run_start + 1

            # Pad run to minimum size using insertion sort
            if run_len < self.min_run:
                forced_end = min(self.n - 1, run_start + self.min_run - 1)
                insertion_sort(self.arr, run_start, forced_end)
                run_end = forced_end
                run_len = run_end - run_start + 1

            self.runs.append((run_start, run_len))
            self.merge_collapse()
            i = run_end + 1

        self.merge_force_collapse()

    def merge_collapse(self):
        while len(self.runs) > 1:
            n = len(self.runs)
            A = self.runs[n - 3] if n >= 3 else None
            B = self.runs[n - 2]
            C = self.runs[n - 1]

            if n >= 3 and A[1] <= B[1] + C[1]:
                if A[1] < C[1]:
                    self.merge_at(n - 3)
                else:
                    self.merge_at(n - 2)
            elif B[1] <= C[1]:
                self.merge_at(n - 2)
            else:
                break

    def merge_force_collapse(self):
        while len(self.runs) > 1:
            n = len(self.runs)
            self.merge_at(n - 2)

    def merge_at(self, i):
        start1, len1 = self.runs[i]
        start2, len2 = self.runs[i + 1]

        merge(self.arr, start1, start1 + len1 - 1, start2 + len2 - 1)
        self.runs[i] = (start1, len1 + len2)
        del self.runs[i + 1]