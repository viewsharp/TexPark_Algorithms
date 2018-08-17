//
// Created by views on 16.08.18.
//

#ifndef LAB_4_1_HEAP_H
#define LAB_4_1_HEAP_H
#define INIT_HEAP__CAPACITY 8

#include <algorithm>
#include <stdexcept>

template<class T>
class Heap {
public:
    Heap() :
            _capacity(INIT_HEAP__CAPACITY),
            _data(new T[_capacity]),
            _size(0) {}

    Heap(const Heap &other) :
            _capacity(other._capacity),
            _data(new T[_capacity]),
            _size(other._size) {
        std::copy(other._data, other._data + _size, _data);
    }

    Heap(Heap &&other) noexcept:
            _capacity(other._capacity),
            _data(other._data),
            _size(other._size) {
        other._data = nullptr;
    }

    virtual ~Heap() noexcept {
        delete[] _data;
    }

    void push(const T &value) {
        if (_size == _capacity) {
            resize();
        }

        _data[_size] = value;
        siftUp(_size);
        _size++;
    }

    void push(T &&value) {
        if (_size == _capacity) {
            resize();
        }

        _data[_size] = std::move(value);
        siftUp(_size);
        _size++;
    }

    const T &top() {
        if (_size == 0)
            throw std::out_of_range("heap is empty");

        return _data[0];
    }

    const T &pop()  {
        if (_size == 0)
            throw std::out_of_range("heap is empty");

        std::swap(_data[0], _data[--_size]);
        siftDown(0);
        return _data[_size];
    }

    bool empty() const {
        return _size == 0;
    }

    int size() const {
        return _size;
    }

private:
    void siftDown(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
// Ищем большего сына, если такой есть.
        int largest = i;
        if (left < _size && _data[left] > _data[i])
            largest = left;
        if (right < _size && _data[right] > _data[largest])
            largest = right;
// Если больший сын есть, то проталкиваем корень в него.
        if (largest != i) {
            std::swap(_data[i], _data[largest]);
            siftDown(largest);
        }
    }

    // Проталкивание элемента наверх.
    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (_data[index] <= _data[parent])
                return;
            std::swap(_data[index], _data[parent]);
            index = parent;
        }
    }

    void resize() {
        T *new_data = new T[_capacity * 2];
        for (int i = 0; _size; i++) {
            new_data[i] = _data[i];
        }

        delete _data;
        _data = new_data;
        _capacity *= 2;
    }


    T *_data;
    int _size;
    int _capacity;
};

#endif //LAB_4_1_HEAP_H
