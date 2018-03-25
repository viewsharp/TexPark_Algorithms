//
// Created by viewsharp on 13.03.18.
//

#ifndef LAB_3_3_STACK_H
#define LAB_3_3_STACK_H

template <typename T>
class Stack {
public:

    Stack(): dataSize(0),
             capacity(4),
             data(new T[4])
    {}

    ~Stack() {
        delete [] data;
    }

    T pop() {
        if (dataSize == 0) {
            throw std::out_of_range("the stack is empty");
        }

        dataSize--;
        return data[dataSize];
    }

    void push(T value) {
        if (dataSize == capacity) {
            this->resize();
        }

        data[dataSize] = value;
        dataSize++;
    }

    bool empty() const {
        return dataSize == 0;
    }

    unsigned int size() const {
        return dataSize;
    }

private:

    void resize() {
        T* buf = new T[capacity*2];
        for (int i = 0; i < capacity; i++) {
            buf[i] = data[i];
        }

        delete[] data;
        data = buf;

        capacity *= 2;
    }

    unsigned int capacity;

    unsigned int dataSize;

    T* data;

};

#endif //LAB_3_3_STACK_H
