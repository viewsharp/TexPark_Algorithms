//
// Created by views on 16.08.18.
//

#ifndef LAB_5_2_MERGESORT_H
#define LAB_5_2_MERGESORT_H

#include <algorithm>

template<class T>
void mergeSort(T *const first, T *const last) {
    unsigned long size = last - first;
    if (size < 2) {
        return;
    }

    T *const middle = first + size / 2;

    mergeSort(first, middle);
    mergeSort(middle, last);

    T *const temp = new T[size];

    T *leftPtr = first;
    T *rightPtr = middle;
    T *tempPtr = temp;

    while (leftPtr < middle && rightPtr < last) {
        if (*leftPtr < *rightPtr) {
            *tempPtr++ = std::move(*leftPtr++);
        } else {
            *tempPtr++ = std::move(*rightPtr++);
        }
    }

    if (rightPtr == last) {
        std::move(leftPtr, middle, leftPtr + (last - middle)); // [size - size / 2] is size of left side
    }
    std::move(temp, tempPtr, first);

    delete[] temp;
}

#endif //LAB_5_2_MERGESORT_H
