package com.timsort_java.structures;

public class LinkedQueue {
    private LinkedList linkedList;

    public LinkedQueue() {
        linkedList = new LinkedList();
    }

    public void enqueue(int item) {
        linkedList.append(item);
    }

    public int dequeue() {
        if (isEmpty()) {
            throw new IndexOutOfBoundsException("Queue is empty");
        }
        int item = linkedList.get(0);
        // To replicate Python's list.pop(0) behavior, we need to remove the head.
        // Since LinkedList doesn't have a direct removeHead method, we simulate it.
        // This is not efficient for a real LinkedList-based queue, but for replication.
        int[] tempArray = linkedList.toArray();
        int[] newArray = new int[tempArray.length - 1];
        System.arraycopy(tempArray, 1, newArray, 0, tempArray.length - 1);
        linkedList.fromArray(newArray);
        return item;
    }

    public int peek() {
        if (isEmpty()) {
            throw new IndexOutOfBoundsException("Queue is empty");
        }
        return linkedList.get(0);
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


