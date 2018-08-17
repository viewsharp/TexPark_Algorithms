//
// Created by views on 16.08.18.
//

#ifndef LAB_1_1_HASHTABLE_H
#define LAB_1_1_HASHTABLE_H

#define HASHTABLE_INIT_CAPACITY 8
#define HASHTABLE_ALPHA 0.6667
#define QUAD_SAMPLE_HASH(default_hash, index)(default_hash + int(index * (index + 1) / 2))

#include <stdexcept>
#include <algorithm>
#include <cassert>
#include "Hash.h"

template<class K, class V>
class HashTable {
public:
    typedef std::pair<K, V> Pair;

    HashTable() :
            _capacity(HASHTABLE_INIT_CAPACITY),
            _size(0),
            _data(new Pair *[HASHTABLE_INIT_CAPACITY]) {}

    explicit HashTable(unsigned long size) :
            _capacity(size),
            _size(0),
            _data(new Pair *[size]) {}

    HashTable(const HashTable<K, V> &other) :
            _capacity(other._capacity),
            _size(other._size),
            _data(new Pair *[other._capacity]) {
        std::copy(other._data, other._data + other._size, _data);
    }

    HashTable(HashTable<K, V> &&other) noexcept  :
            _capacity(other._capacity),
            _size(other._size),
            _data(other._data) {
        other._data = nullptr;
    }

    virtual ~HashTable() noexcept {
        for (unsigned int i = 0; i < _capacity; i++) {
            if (_data[i] != nullptr) {
                delete _data[i];
            }
        }
        delete[] _data;
    }

    bool has(const K &key) {
        Hash<K> hashFunc;
        unsigned long hash = hashFunc(key);

        Pair **ptr;
        for (unsigned long i = 0; i < capacity(); ++i) {
            ptr = _data + QUAD_SAMPLE_HASH(hash, i) % _capacity;

            if (!*ptr) {
                return false;
            }

            if (*ptr != &_deleted && (*ptr)->first == key) {
                return true;
            }
        }

        return false;
    }

    V &at(const K &key) {
        Hash<K> hashFunc;
        unsigned long hash = hashFunc(key);

        Pair **ptr;
        for (unsigned long i = 0; i < capacity(); ++i) {
            ptr = _data + QUAD_SAMPLE_HASH(hash, i) % _capacity;

            if (!*ptr) {
                throw std::out_of_range("no key in hash table");
            }

            if (*ptr != &_deleted && (*ptr)->first == key) {
                return (*ptr)->second;
            }
        }

        throw std::out_of_range("no key in hash table");
    }

    void add(const K &key, const V &value) {
        addAllocatedPair(new Pair(key, value));
    }

    void add(K &&key, const V &value) {
        addAllocatedPair(new Pair(key, value));
    }

    void add(const K &key, V &&value) {
        addAllocatedPair(new Pair(key, value));
    }

    void add(K &&key, V &&value) {
        addAllocatedPair(new Pair(key, value));
    }

    void addAllocatedPair(Pair *pair) {
        if ((float) _size / _capacity > HASHTABLE_ALPHA) {
            resize();
        }

        Pair **firstDeletedPtr = nullptr;
        Hash<K> hashFunc{};
        unsigned long hash = hashFunc(pair->first);
        Pair **ptr;

        for (unsigned long i = 0; i < _capacity; ++i) {
            ptr = _data + QUAD_SAMPLE_HASH(hash, i) % _capacity;

            if (*ptr == &_deleted and !firstDeletedPtr) {
                firstDeletedPtr = ptr;
            }

            if (!*ptr) {
                if (firstDeletedPtr) {
                    *firstDeletedPtr = pair;
                } else {
                    *ptr = pair;
                }
                _size++;
                return;
            }

            if ((*ptr)->first == pair->first) {
                (*ptr)->second = pair->second;
                return;
            }
        }

        assert(firstDeletedPtr);

        *firstDeletedPtr = pair;
        _size++;
    }



    void remove(const K &key) {
        Hash<K> hashFunc;
        unsigned long hash = hashFunc(key);
        Pair **ptr;

        for (unsigned long i = 0; i < _capacity; ++i) {
            ptr = _data + QUAD_SAMPLE_HASH(hash, i) % _capacity;

            if (!*ptr) {
                return;
            }

            if (*ptr != &_deleted && (*ptr)->first == key) {
                delete *ptr;
                *ptr = &_deleted;
                _size--;
                return;
            }
        }
    }

    unsigned long size() {
        return _size;
    }

    unsigned long capacity() {
        return _capacity;
    }

private:
    void resize() {
        Pair **newData = new Pair *[_capacity * 2];
        Pair **newPtr;
        Hash<K> hashFunc;

        for (Pair **ptr = _data; ptr < _data + _capacity; ptr++) {
            if (!*ptr || *ptr == &_deleted) {
                continue;
            }

            for (unsigned long i = 0; i < _capacity * 2; i++) {
                newPtr = newData + QUAD_SAMPLE_HASH(hashFunc((*ptr)->first), i) % (_capacity * 2);

                if (!*newPtr) {
                    *newPtr = *ptr;
                    break;
                }
            }
        }

        delete[] _data;
        _data = newData;
        _capacity *= 2;
    }

    Pair **_data;
    unsigned long _size;
    unsigned long _capacity;
    Pair _deleted;
};

#endif //LAB_1_1_HASHTABLE_H
