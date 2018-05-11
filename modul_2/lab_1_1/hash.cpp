//
// Created by viewsharp on 18.04.18.
//
#include "hash.h"

unsigned long quadSampleHash(string value, unsigned long index, unsigned long m) {
    return quadSampleHash(StringHash(value, m), index);
}

unsigned long quadSampleHash(unsigned long default_hash, unsigned long index) {
    return default_hash + int(index * (index + 1) / 2); // хеш + сумма членов ар. прогрессии
}

unsigned long StringHash(string value, unsigned long m) {
    unsigned long hash = 0;
    unsigned long a = 2 * m - 1;
    //for (String::iterator it = value.begin() ; it != value.end(); ++it)
    for (auto it: value) {
        hash = (hash * a + it) % m;
    }
    return hash;
}