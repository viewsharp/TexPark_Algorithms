//
// Created by viewsharp on 14.03.18.
//

#ifndef LAB_4_3_HEAP_H
#define LAB_4_3_HEAP_H

#include <utility>
#include <cassert>

template<class T>
class Heap {
public:
    Heap() :
            data(new T[4]),
            capacity(4),
            dataSize(0) {}

    ~Heap() {
        delete[] data;
    }

    void push(T value) {
        if (dataSize == capacity) {
            resize();
        }

        data[dataSize] = value;
        dataSize++;

        siftUp(dataSize - 1);
    }

    T pop() {
        assert(!empty());

        // Запоминаем значение корня.
        T result = data[0];

        // Переносим последний элемент в корень.
        data[0] = data[dataSize - 1];
        dataSize--;

        // Вызываем SiftDown для корня.
        if (!empty()) {
            siftDown(0);
        }
        return result;
    }

    T top() const {
        assert(!empty());

        return data[0];
    }

    bool empty() const {
        return dataSize == 0;
    }

    int size() const {
        return dataSize;
    }

private:
    T *data;
    int capacity;
    int dataSize;

    void resize() {

        T *buf = new T[capacity * 2];
        for (int i = 0; i < capacity; i++) {
            buf[i] = data[i];
        }

        delete[] data;
        data = buf;

        capacity *= 2;
    }

    void siftDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            // Ищем большего сына, если такой есть.
            int largest = index;
            if (left < dataSize && data[index] < data[left])
                largest = left;
            if (right < dataSize && data[largest] < data[right])
                largest = right;

            // Если больший сын есть, то проталкиваем корень в него.
            if (largest == index) {
                break;
            }

            std::swap(data[index], data[largest]);
            index = largest;
        }
    }

    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (not(data[parent] < data[index]))
                return;
            std::swap(data[index], data[parent]);
            index = parent;
        }
    }
};

#endif //LAB_4_3_HEAP_H
