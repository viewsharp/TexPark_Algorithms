#include <iostream>
#include "radix.h"

using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    long long *array = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sortLSD(array, n);

    for (int i = 0; i < n; i++) {
        cout << array[i] << ' ';
    }

    return 0;
}