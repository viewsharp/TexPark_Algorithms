#include <iostream>
#include "Deque.h"

using namespace std;

int main() {
    Deque<int> deque;
    int n;
    cin >> n;
    bool result = true;

    int a, value;
    for (int i = 0; i < n; i++) {
        cin >> a >> value;

        switch (a) {
            case 1:
                deque.push_front(value);
                break;
            case 2:
                try {
                    result &= value == deque.pop_front();
                } catch (const std::out_of_range &e) {
                    result &= value == -1;
                }
                break;
            case 3:
                deque.push_back(value);
                break;
            case 4:
                try {
                    result &= value == deque.pop_back();
                } catch (const std::out_of_range &e) {
                    result &= value == -1;
                }
                break;
        }
    }

    if (result) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}