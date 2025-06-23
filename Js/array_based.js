const fs = require('fs');

class ArrayList {
  constructor() {
    this._data = [];
  }

  append(item) {
    this._data.push(item);
  }

  get(index) {
    if (index >= 0 && index < this._data.length) {
      return this._data[index];
    }
    throw new Error("Index out of bounds");
  }

  set(index, item) {
    if (index >= 0 && index < this._data.length) {
      this._data[index] = item;
    } else {
      throw new Error("Index out of bounds");
    }
  }

  length() {
    return this._data.length;
  }

  toList() {
    return [...this._data];
  }

  fromList(dataList) {
    this._data = [...dataList];
  }

  clear() {
    this._data = [];
  }

  saveToCSV(filename) {
    console.log(`Salvando dados em ${filename}`);
    const rows = this._data.map(x => [x].join(',')); // transforma cada item em linha CSV
    const content = rows.join('\n');
    fs.writeFileSync(filename, content);
  }
}

class ArrayQueue extends ArrayList {
  enqueue(item) {
    this.append(item);
  }

  dequeue() {
    if (this._data.length === 0) {
      throw new Error("Queue is empty");
    }
    return this._data.shift();
  }

  peek() {
    if (this._data.length === 0) {
      throw new Error("Queue is empty");
    }
    return this._data[0];
  }

  isEmpty() {
    return this._data.length === 0;
  }
}

class ArrayStack extends ArrayList {
  push(item) {
    this.append(item);
  }

  pop() {
    if (this._data.length === 0) {
      throw new Error("Stack is empty");
    }
    return this._data.pop();
  }

  peek() {
    if (this._data.length === 0) {
      throw new Error("Stack is empty");
    }
    return this._data[this._data.length - 1];
  }

  isEmpty() {
    return this._data.length === 0;
  }
}

module.exports = { ArrayList, ArrayQueue, ArrayStack };
