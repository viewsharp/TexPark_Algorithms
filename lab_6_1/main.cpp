#include <iostream>
#include "kstat.h"

using namespace std;

int main() {

    unsigned int n = 0;
    unsigned int k = 0;
    cin >> n >> k;

    int *array = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << *kStat(array, n, k) << endl;
    delete[] array;
}





