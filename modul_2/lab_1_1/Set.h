//
// Created by views on 17.08.18.
//

#ifndef LAB_1_1_SET_H
#define LAB_1_1_SET_H

#include "HashTable.h"

template<class T>
class Set : public HashTable<T, bool> {
public:
    void add(T &&value) {
        HashTable<T,bool>::add(std::move(value), true);
    }

    void add(T &value) {
        HashTable<T,bool>::add(value, true);
    }
};

#endif //LAB_1_1_SET_H
