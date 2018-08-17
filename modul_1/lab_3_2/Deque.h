//
// Created by views on 15.08.18.
//

#ifndef LAB_3_2_DEQUE_H
#define LAB_3_2_DEQUE_H

#include <stdexcept>

#define INIT_DEQUE_CAPACITY 8

template<class T>
class Deque {
public:
    Deque() :
            data(new T[INIT_DEQUE_CAPACITY]),
            capacity(INIT_DEQUE_CAPACITY),
            size(0),
            front(0),
            back(0) {}

    ~Deque() {
        delete data;
    }

    void push_front(const T &value) {
        if (front == back && size != 0) {
            resize();
        }

        front--;
        if (front < 0) {
            front = capacity - 1;
        }
        data[front] = value;
        size++;
    }

    void push_back(const T &value) {
        if (front == back && size != 0) {
            resize();
        }

        data[back] = value;
        back++;
        if (back >= capacity) {
            back = 0;
        }
        size++;
    }

    T &pop_front() {
        if (size == 0) {
            throw std::out_of_range("the queue is empty");
        }

        T& result = data[front];
        front++;
        if (front >= capacity) {
            front = 0;
        }
        size--;
        return result;
    }

    T &pop_back() {
        if (size == 0) {
            throw std::out_of_range("the queue is empty");
        }

        back--;
        if (back < 0) {
            back = capacity - 1;
        }
        size++;
        return data[back];
    }

private:
    void resize() {
        T* newData = new T[capacity*2];
        for (int i = 0; size; i++) {
            newData[i] = pop_front();
        }

        delete data;
        data = newData;

        front = 0;
        back = capacity;
        capacity *= 2;
    }

    int capacity;
    int size;
    int front;
    int back;
    T *data;
};

#endif //LAB_3_2_DEQUE_H
