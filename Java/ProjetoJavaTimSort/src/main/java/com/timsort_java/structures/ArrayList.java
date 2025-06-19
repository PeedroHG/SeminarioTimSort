package com.timsort_java.structures;

import java.util.Arrays;

public class ArrayList {
    private int[] data;
    private int size;
    private static final int DEFAULT_CAPACITY = 10;

    public ArrayList() {
        data = new int[DEFAULT_CAPACITY];
        size = 0;
    }

    public void append(int item) {
        if (size == data.length) {
            ensureCapacity();
        }
        data[size++] = item;
    }

    public int get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        return data[index];
    }

    public void set(int index, int item) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        data[index] = item;
    }

    public int size() {
        return size;
    }

    public int[] toArray() {
        return Arrays.copyOf(data, size);
    }

    public void fromArray(int[] arr) {
        data = Arrays.copyOf(arr, arr.length);
        size = arr.length;
    }

    private void ensureCapacity() {
        int newCapacity = data.length * 2;
        data = Arrays.copyOf(data, newCapacity);
    }
}


