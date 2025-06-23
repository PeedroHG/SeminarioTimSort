const fs = require('fs');

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this._size = 0;
  }

  append(data) {
    const newNode = new Node(data);
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
    this._size++;
  }

  get(index) {
    if (index < 0 || index >= this._size) {
      throw new Error("Index out of bounds");
    }
    let current = this.head;
    for (let i = 0; i < index; i++) {
      current = current.next;
    }
    return current.data;
  }

  set(index, data) {
    if (index < 0 || index >= this._size) {
      throw new Error("Index out of bounds");
    }
    let current = this.head;
    for (let i = 0; i < index; i++) {
      current = current.next;
    }
    current.data = data;
  }

  length() {
    return this._size;
  }

  toList() {
    const result = [];
    let current = this.head;
    while (current) {
      result.push(current.data);
      current = current.next;
    }
    return result;
  }

  fromList(dataList) {
    this.head = null;
    this.tail = null;
    this._size = 0;
    for (const data of dataList) {
      this.append(data);
    }
  }

  clear() {
    this.head = null;
    this.tail = null;
    this._size = 0;
  }

  saveToCSV(filename) {
    const rows = [];
    let current = this.head;
    while (current) {
      rows.push(current.data);
      current = current.next;
    }
    const content = rows.map(x => [x].join(',')).join('\n');
    fs.writeFileSync(filename, content);
  }
}

class LinkedQueue extends LinkedList {
  enqueue(data) {
    this.append(data);
  }

  dequeue() {
    if (!this.head) {
      throw new Error("Queue is empty");
    }
    const data = this.head.data;
    this.head = this.head.next;
    if (!this.head) {
      this.tail = null;
    }
    this._size--;
    return data;
  }

  peek() {
    if (!this.head) {
      throw new Error("Queue is empty");
    }
    return this.head.data;
  }

  isEmpty() {
    return this.head === null;
  }
}

class LinkedStack extends LinkedList {
  push(data) {
    const newNode = new Node(data);
    newNode.next = this.head;
    this.head = newNode;
    if (!this.tail) {
      this.tail = newNode;
    }
    this._size++;
  }

  pop() {
    if (!this.head) {
      throw new Error("Stack is empty");
    }
    const data = this.head.data;
    this.head = this.head.next;
    if (!this.head) {
      this.tail = null;
    }
    this._size--;
    return data;
  }

  peek() {
    if (!this.head) {
      throw new Error("Stack is empty");
    }
    return this.head.data;
  }

  isEmpty() {
    return this.head === null;
  }
}

module.exports = { Node, LinkedList, LinkedQueue, LinkedStack };
