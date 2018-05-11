//
// Created by viewsharp on 17.04.18.
//

#ifndef LAB_1_1_STRINGSET_H
#define LAB_1_1_STRINGSET_H

#define STRINGSET_INIT_CAPACITY 8
#define STRINGSET_ALPHA 0.667

#include <exception>
#include <string>
#include "hash.h"

using namespace std;

class String : public string {
public:
    String() :
            string(),
            isDeleted(false) {
    }

    explicit String(const string &value) :
            string(value),
            isDeleted(false) {
    }

    bool isDeleted;
};

class StringSetException : public exception {
public:
    const string msg;

    StringSetException(const string &msg) :
            msg(msg) {}
};

class StringSet {
public:
    StringSet();

    explicit StringSet(unsigned long size);

    bool has(const string &value);

    bool add(const string &value);

    bool remove(const string &);

    unsigned long size() { return _size; }

    unsigned long capacity() { return _capacity; }

    ~StringSet();

private:
    String *data;
    unsigned long _size;
    unsigned long _capacity;

    void resize();
};

#endif //LAB_1_1_STRINGSET_H
