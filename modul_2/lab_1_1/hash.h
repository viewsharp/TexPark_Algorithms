//
// Created by viewsharp on 17.04.18.
//

#ifndef LAB_1_1_HASH_H
#define LAB_1_1_HASH_H

#include <string>

using namespace std;

unsigned long quadSampleHash(string value, unsigned long index, unsigned long m);
unsigned long quadSampleHash(unsigned long default_hash, unsigned long index);
unsigned long StringHash(string value, unsigned long m);

#endif //LAB_1_1_HASH_H
