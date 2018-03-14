//
// Created by viewsharp on 13.03.18.
//

#ifndef LAB_3_3_QUEUE_H
#define LAB_3_3_QUEUE_H

#include "stack.h"

template<typename T>
class Queue {
public:
    T pop() {
        if (secondStack.empty()) {
            if (firstStack.empty()) {
                throw std::out_of_range("the queue is empty");
            }

            while (firstStack.size() != 1) {
                secondStack.push(firstStack.pop());
            }
            return firstStack.pop();
        } else {
            return secondStack.pop();
        }
    }

    void push(T value) {
        firstStack.push(value);
    }

private:
    Stack<T> firstStack;
    Stack<T> secondStack;

};

#endif //LAB_3_3_QUEUE_H
