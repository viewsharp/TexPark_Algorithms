//
// Created by viewsharp on 28.03.18.
//

#include "radix.h"

void sortLSD(long long *&array, unsigned int size) {
    LLByte *buf = (LLByte *) array;
    sortLSD(buf, size);
    array = (long long *) buf;
}

void sortLSD(LLByte *&array, unsigned int size) {
    for (int i = 0; i < 8; i++) { // байты в памяти хранятся в обратном порядке!!!
        int c[256];

        for (int j = 0; j < 256; j++) {
            c[j] = 0;
        }

        for (int j = 0; j < size; j++) {
            c[array[j].byte[i]]++;
        }

        for (int j = 1; j < 256; j++) {
            c[j] += c[j - 1];
        }

        LLByte *b = new LLByte[size];
        for (int j = size - 1; j >= 0; j--) {
            b[--c[array[j].byte[i]]] = array[j];
        }

        delete[] array;
        array = b;
    }
}
