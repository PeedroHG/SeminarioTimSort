package com.timsort_java.structures;

public class ArrayStack {
    private ArrayList arrayList;

    public ArrayStack() {
        arrayList = new ArrayList();
    }

    public void push(int item) {
        arrayList.append(item);
    }

    public int pop() {
        if (isEmpty()) {
            throw new IndexOutOfBoundsException("Stack is empty");
        }
        int item = arrayList.get(arrayList.size() - 1);
        arrayList.fromArray(java.util.Arrays.copyOf(arrayList.toArray(), arrayList.size() - 1));
        return item;
    }

    public int peek() {
        if (isEmpty()) {
            throw new IndexOutOfBoundsException("Stack is empty");
        }
        return arrayList.get(arrayList.size() - 1);
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


