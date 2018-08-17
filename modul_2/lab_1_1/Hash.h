//
// Created by views on 16.08.18.
//

#ifndef LAB_1_1_HASH_H
#define LAB_1_1_HASH_H
#define HASH_ALPHA 13

#include <string>

template<class T>
struct Hash {};

template<>
struct Hash<std::string> {
    unsigned long operator()(const std::string &value) const noexcept {
        unsigned long hash = 0;
        for (auto it: value) {
            hash *= HASH_ALPHA;
            hash += it;
        }
        return hash;
    }
};

#endif //LAB_1_1_HASH_H
