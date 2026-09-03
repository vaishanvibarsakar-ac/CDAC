/*
 * Question7.cpp
 *
 *  Created on: 02-Sept-2026
 *      Author: user
 */


#include <iostream>
#include <cstring>
using namespace std;

class LogBuffer {
private:
    char* buffer;
    int capacity;
    int size;
    static int instanceCount;

    mutable int accessCount = 0;

public:

    LogBuffer(int cap) : capacity(cap), size(0) {
        buffer = new char[capacity];
        buffer[0] = '\0';
        instanceCount++;
        cout << "[LogBuffer Created] capacity=" << capacity << endl;
    }


    LogBuffer(const LogBuffer& other) : capacity(other.capacity), size(other.size) {
        buffer = new char[capacity];
        memcpy(buffer, other.buffer, size + 1);
        instanceCount++;
        cout << "[LogBuffer Deep Copied] capacity=" << capacity << endl;
    }


    ~LogBuffer() {
        delete[] buffer;
        instanceCount--;
        cout << "[LogBuffer Destroyed]" << endl;
    }

    void append(const char* msg) {
        int len = strlen(msg);
        if (size + len < capacity) {
            memcpy(buffer + size, msg, len + 1);
            size += len;
        }
    }

    void print() const {
        cout << buffer << endl;
        accessCount++;
    }

    int getAccessCount() const {
        return accessCount;
    }

    static int getInstanceCount() {
        return instanceCount;
    }
};


int LogBuffer::instanceCount = 0;

int main() {
    LogBuffer log1(256);
    log1.append("Server started on port 8080");


    const LogBuffer readOnly(log1);

    readOnly.print();
    readOnly.print();
    readOnly.print();


    cout << "Times printed: " << readOnly.getAccessCount() << endl;

    return 0;
}


