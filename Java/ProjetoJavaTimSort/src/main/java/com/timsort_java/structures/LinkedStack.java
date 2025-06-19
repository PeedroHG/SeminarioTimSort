package com.timsort_java.structures;

public class LinkedStack {
    private LinkedList linkedList;

    public LinkedStack() {
        linkedList = new LinkedList();
    }

    public void push(int item) {
        // For a stack, push should add to the beginning for efficiency
        // However, to mimic the Python behavior of appending and then popping from end,
        // we will append and then manipulate the underlying list for pop/peek.
        // A true LinkedStack would add/remove from head.
        linkedList.append(item);
    }

    public int pop() {
        if (isEmpty()) {
            throw new IndexOutOfBoundsException("Stack is empty");
        }
        int item = linkedList.get(linkedList.size() - 1);
        int[] tempArray = linkedList.toArray();
        int[] newArray = new int[tempArray.length - 1];
        System.arraycopy(tempArray, 0, newArray, 0, tempArray.length - 1);
        linkedList.fromArray(newArray);
        return item;
    }

    public int peek() {
        if (isEmpty()) {
            throw new IndexOutOfBoundsException("Stack is empty");
        }
        return linkedList.get(linkedList.size() - 1);
    }

    public boolean isEmpty() {
        return linkedList.size() == 0;
    }

    public int size() {
        return linkedList.size();
    }

    public int[] toArray() {
        return linkedList.toArray();
    }
}


