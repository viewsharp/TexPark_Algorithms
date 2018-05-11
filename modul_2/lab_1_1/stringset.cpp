//
// Created by viewsharp on 17.04.18.
//

#include "stringset.h"

StringSet::StringSet() :
        _capacity(STRINGSET_INIT_CAPACITY),
        _size(0),
        data(new String[STRINGSET_INIT_CAPACITY]) {
}

StringSet::StringSet(unsigned long size) :
        _capacity(size),
        _size(0),
        data(new String[size]) {
}

bool StringSet::has(const string &value) {
    unsigned long hash = StringHash(value, _capacity);

    for (unsigned long i = 0; i < capacity(); ++i) {
        String *place = data + quadSampleHash(hash, i) % _capacity;

        if (place->empty())
            return false;

        if (*place == value) {
            return not place->isDeleted;
        }
    }

    return false;
}

bool StringSet::add(const string &value) {
    if ((float) _size / _capacity > STRINGSET_ALPHA) {
        resize();
    }

    String* deletedPlace = nullptr;

    unsigned long hash = StringHash(value, _capacity);

    for (unsigned long i = 0; i < _capacity; ++i) {
        String *place = data + quadSampleHash(hash, i) % _capacity;

        if (place->isDeleted and deletedPlace == nullptr) {
            deletedPlace = place;
        }

        if (*place == value) {
            if (place->isDeleted) {
                place->isDeleted = false;
                return true;
            }
            return false;
        }

        if (place->empty()) {
            if (deletedPlace) {
                *deletedPlace = String(value);
            } else {
                *place = String(value);
            }
            _size++;
            return true;
        }
    }

    if (deletedPlace) {
        *deletedPlace = String(value);
        _size++;
        return true;
    }

    throw StringSetException("Overflow");
}

bool StringSet::remove(const string &value) {
    unsigned long hash = StringHash(value, this->_capacity);

    for (unsigned long i = 0; i < _capacity; ++i) {
        String *place = data + quadSampleHash(hash, i) % _capacity;

        if (place->empty()) {
            return false;
        }

        if (*place == value) {
            if (place->isDeleted) {
                return false;
            }

            place->isDeleted = true;
            _size--;
            return true;
        }
    }
    return false;
}

void StringSet::resize() {
    String *lastData = data;
    unsigned long lastCapacity = _capacity;

    data = new String[_capacity * 2];
    _capacity *= 2;

    for (String *it = lastData; it < lastData + lastCapacity; it++) {
        if (not it->empty() and not it->isDeleted) {
            add(*it);
        }
    }

    delete[] lastData;
}

StringSet::~StringSet() {
    delete[] this->data;
}