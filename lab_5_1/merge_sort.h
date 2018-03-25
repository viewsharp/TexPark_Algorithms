//
// Created by viewsharp on 23.03.18.
//

#ifndef LAB_5_1_MERGE_SORT_H
#define LAB_5_1_MERGE_SORT_H

#include <iostream>

using namespace std;

template<typename T>
void mergeSort(T *begin, T *end) noexcept {
    unsigned long size = end - begin;

    if (size > 1) {
        T* middle = begin + size / 2;

        mergeSort(begin, middle);
        mergeSort(middle, end);

        T *tmpArray(new T[size]);

        T *left = begin;
        T *right = middle;
        T *last = tmpArray;


        while (left < middle and right < end) {
            if (*left < *right) {
                *last++ = move(*left++);
            } else {
                *last++ = move(*right++);
            }
        }
        if (left == middle) {
            copy(right, end, last);
        } else if (right == end) {
            copy(left, middle, last);
        }

        copy(tmpArray, &tmpArray[size], begin);
    }
}

#endif //LAB_5_1_MERGE_SORT_H
