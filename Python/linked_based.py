import csv

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None  # Add tail pointer
        self._size = 0

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.tail = new_node  # Set tail for the first node
        else:
            self.tail.next = new_node  # Use tail to append in O(1)
            self.tail = new_node      # Update tail
        self._size += 1

    def get(self, index):
        if index < 0 or index >= self._size:
            raise IndexError("Index out of bounds")
        current = self.head
        for _ in range(index):
            current = current.next
        return current.data

    def set(self, index, data):
        if index < 0 or index >= self._size:
            raise IndexError("Index out of bounds")
        current = self.head
        for _ in range(index):
            current = current.next
        current.data = data

    def __len__(self):
        return self._size

    def to_list(self):
        result = []
        current = self.head
        while current:
            result.append(current.data)
            current = current.next
        return result

    def from_list(self, data_list):
        self.head = None
        self.tail = None  # Reset tail
        self._size = 0
        for data in data_list:
            self.append(data)

    def clear(self):
        self.head = None
        self.tail = None  # Reset tail
        self._size = 0

    def save_to_csv(self, filename):
        with open(filename, 'w', newline='') as file:
            writer = csv.writer(file)
            current = self.head
            while current:
                writer.writerow([current.data])
                current = current.next

class LinkedQueue(LinkedList):
    def enqueue(self, data):
        # Inherits append from LinkedList, which now uses tail
        self.append(data)

    def dequeue(self):
        if not self.head:
            raise IndexError("Queue is empty")
        data = self.head.data
        self.head = self.head.next
        if self.head is None: # If queue becomes empty, tail should also be None
            self.tail = None
        self._size -= 1
        return data

    def peek(self):
        if not self.head:
            raise IndexError("Queue is empty")
        return self.head.data

    def is_empty(self):
        return self.head is None

class LinkedStack(LinkedList):
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        if self.tail is None: # If stack was empty, new node is also the tail
            self.tail = new_node
        self._size += 1

    def pop(self):
        if not self.head:
            raise IndexError("Stack is empty")
        data = self.head.data
        self.head = self.head.next
        if self.head is None: # If stack becomes empty, tail should also be None
            self.tail = None
        self._size -= 1
        return data

    def peek(self):
        if not self.head:
            raise IndexError("Stack is empty")
        return self.head.data

    def is_empty(self):
        return self.head is None


