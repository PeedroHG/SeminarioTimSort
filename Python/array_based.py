import csv

class ArrayList:
    def __init__(self):
        self._data = []

    def append(self, item):
        self._data.append(item)

    def get(self, index):
        if 0 <= index < len(self._data):
            return self._data[index]
        raise IndexError("Index out of bounds")

    def set(self, index, item):
        if 0 <= index < len(self._data):
            self._data[index] = item
        else:
            raise IndexError("Index out of bounds")

    def __len__(self):
        return len(self._data)

    def to_list(self):
        return list(self._data)

    def from_list(self, data_list):
        self._data = list(data_list)

    def clear(self):
        self._data = []

    def save_to_csv(self, filename):
        with open(filename, 'w', newline='') as file:
            writer = csv.writer(file)
            writer.writerows([[x] for x in self._data])


class ArrayQueue(ArrayList):
    def enqueue(self, item):
        self.append(item)

    def dequeue(self):
        if not self._data:
            raise IndexError("Queue is empty")
        return self._data.pop(0)

    def peek(self):
        if not self._data:
            raise IndexError("Queue is empty")
        return self._data[0]

    def is_empty(self):
        return len(self._data) == 0

class ArrayStack(ArrayList):
    def push(self, item):
        self.append(item)

    def pop(self):
        if not self._data:
            raise IndexError("Stack is empty")
        return self._data.pop()

    def peek(self):
        if not self._data:
            raise IndexError("Stack is empty")
        return self._data[-1]

    def is_empty(self):
        return len(self._data) == 0


