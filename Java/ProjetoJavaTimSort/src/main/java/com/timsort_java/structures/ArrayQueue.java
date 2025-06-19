package com.timsort_java.structures;

public class ArrayQueue {
    private ArrayList arrayList;

    public ArrayQueue() {
        arrayList = new ArrayList();
    }

    public void enqueue(int item) {
        arrayList.append(item);
    }

    public int dequeue() {
        if (isEmpty()) {
            throw new IndexOutOfBoundsException("Queue is empty");
        }
        int item = arrayList.get(0);
        // Shift elements to the left
        for (int i = 0; i < arrayList.size() - 1; i++) {
            arrayList.set(i, arrayList.get(i + 1));
        }
        // Decrease size
        // This is a simplified approach. A more efficient queue would use a circular array or linked list.
        // For direct replication of Python's list.pop(0) behavior, this is functionally equivalent.
        arrayList.fromArray(java.util.Arrays.copyOf(arrayList.toArray(), arrayList.size() - 1));
        return item;
    }

    public int peek() {
        if (isEmpty()) {
            throw new IndexOutOfBoundsException("Queue is empty");
        }
        return arrayList.get(0);
    }

    public boolean isEmpty() {
        return arrayList.size() == 0;
    }

    public int size() {
        return arrayList.size();
    }

    public int[] toArray() {
        return arrayList.toArray();
    }
}


