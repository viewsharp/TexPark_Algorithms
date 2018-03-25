//
// Created by viewsharp on 25.03.18.
//

#ifndef INC_6_1_KSTAT_H
#define INC_6_1_KSTAT_H


#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

template<class T>
T *kStat(T *array, unsigned long size, unsigned int k);

template<class T>
static T *threeMedian(T *begin) {
    if (begin[0] < begin[1]) {
        if (begin[1] < begin[2])
            return begin + 1; // 0 1 2

        if (begin[2] < begin[0])
            return begin; // 2 0 1

        return begin + 2; // 0 2 1

    } else {
        if (begin[0] < begin[2])
            return begin; // 1 0 2

        if (begin[2] < begin[1])
            return begin + 1; // 2 1 0

        return begin + 2; // 1 2 0
    }
}

template<class T>
T *pivot(T *begin, T *end) {
    long size = end - begin;

    if (size <= 2) {
        return begin;
    } else if (size < 6) {
        return threeMedian(begin);
    }

    unsigned long threeCount = (unsigned long) floor(size / 3);
    T *threeMedians = new T[threeCount];

    for (int i = 0; i < threeCount; i++) {
        threeMedians[i] = *threeMedian(begin + i * 3);
    }

    // median position in 'threeMedians' array
    unsigned long index = kStat(threeMedians, threeCount, (unsigned int) (threeCount / 2)) - threeMedians;
    delete[] threeMedians;

    return begin + 2 * index + 1;
}

template<class T>
T *partition(T *begin, T *end) {
    assert(end - begin > 0);

    if (end - begin == 1)
        return begin;

    swap(*pivot(begin, end), *(end - 1)); // put pivot on the last position

    T *pvt = end - 1;
    T *i = begin;
    T *j = begin;

    for (; *j < *pvt; j++) {}
    while (true) { // while j != pvt
        for (; *pvt < *j; j++) {}
        for (; *i < *pvt; i++) {}

        if (j == pvt) {
            break;
        }

        swap(*i, *j);
    }

    swap(*i, *pvt);

    return i;
}

template<class T>
T *kStat(T *array, unsigned long size, unsigned int k) {
    assert(size != 0);
    assert(k <= size);

    if (size == 1 and k == 0)
        return array;

    T *pivot = nullptr;
    T *begin = array;
    T *end = array + size;

    do {
        pivot = partition(begin, end);

        if (array + k < pivot) {
            end = pivot;
        } else {
            begin = pivot + 1;
        }
    } while (pivot != array + k);
    return pivot;
}

#endif //INC_6_1_KSTAT_H
