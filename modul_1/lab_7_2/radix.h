//
// Created by viewsharp on 28.03.18.
//

#ifndef LAB_7_2_RADIX_H
#define LAB_7_2_RADIX_H

struct LLByte {
    unsigned char byte[8];
};

void sortLSD(long long *&array, unsigned int size);

void sortLSD(LLByte *&array, unsigned int size);

#endif //LAB_7_2_RADIX_H
