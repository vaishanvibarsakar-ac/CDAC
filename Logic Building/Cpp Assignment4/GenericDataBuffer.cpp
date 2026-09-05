/*
 * Question3B.cpp
 *
 *  Created on: 03-Sept-2026
 *      Author: user
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class DataBuffer {
private:
    T* data;
    int capacity;
    int head;
    int tail;
    int count;

public:
    DataBuffer(int cap) : capacity(cap), head(0), tail(0), count(0) {
        data = new T[capacity];
    }

    ~DataBuffer() {
        delete[] data;
    }

    void push(const T& value) {
        data[tail] = value;
        tail = (tail + 1) % capacity;
        if (count == capacity) {
            head = (head + 1) % capacity;
        } else {
            count++;
        }
    }

    T pop() {
        if (isEmpty()) throw underflow_error("Buffer is empty");
        T value = data[head];
        head = (head + 1) % capacity;
        count--;
        return value;
    }

    T peek() const {
        if (isEmpty()) throw underflow_error("Buffer is empty");
        return data[head];
    }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }

    friend ostream& operator<<(ostream& cout, const DataBuffer<T>& buf) {
        cout << "[";
        for (int i = 0; i < buf.count; i++) {
            int idx = (buf.head + i) % buf.capacity;
            cout << buf.data[idx];
            if (i < buf.count - 1) cout << ", ";
        }
        cout << "]";
        return cout;
    }
};

int main4() {
    DataBuffer<int> tickBuffer(5);
    for (int i = 1; i <= 7; i++) tickBuffer.push(i * 10);
    cout << "Tick Buffer: " << tickBuffer << endl;

    DataBuffer<double> tempBuffer(4);
    tempBuffer.push(36.6); tempBuffer.push(37.1);
    tempBuffer.push(38.2); tempBuffer.push(36.9);
    cout << "Before pop: " << tempBuffer << endl;
    cout << "Popped: " << tempBuffer.pop() << endl;
    cout << "After pop: " << tempBuffer << endl;


    DataBuffer<string> logBuffer(3);
    logBuffer.push("INFO: Server started");
    logBuffer.push("WARN: High memory usage");
    logBuffer.push("ERROR: DB connection timeout");
    logBuffer.push("INFO: Retry successful");
    cout << "Log Buffer: " << logBuffer << endl;

    return 0;
}



