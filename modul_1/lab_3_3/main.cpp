#include <iostream>
#include "queue.h"

/*
 * Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью динамического буфера.
 * Обрабатывать команды push back и pop front.
 */

using namespace std;

int main() {
    Queue<int> queue;

    int n = 0;
    cin >> n;

    int action = 0;
    int value = 0;

    for (int i = 0; i < n; i++) {
        cin >> action >> value;
        if (action == 2) {
            try {
                if (queue.pop() != value) {
                    cout<<"NO";
                    return 0;
                }
            }
            catch (out_of_range error) {
                if (value != -1) {
                    cout << "NO";
                    return 0;
                }
            }
        }
        else {
            queue.push(value);
        }
    }

    cout << "YES";
    return 0;
}