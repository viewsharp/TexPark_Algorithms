#include <iostream>
#include <vector>
#include <queue>

#include "Heap.h"

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    Heap<int> heap;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        heap.push(value);
    }
    int maxWeight;
    cin >> maxWeight;

    int result = 0;
    int weight = 0;
    int maxCount = heap.size();
    int count = 0;
    int fruit_weight = 0;

    while (!heap.empty()) {
        fruit_weight = heap.pop();

        if (weight + fruit_weight > maxWeight || count == maxCount) {
            result++;
            weight = 0;
            count = 0;
        }

        weight += fruit_weight;
        count++;

        if (fruit_weight != 1) {
            heap.push(fruit_weight / 2);
        }
    }

    if (weight != 0) {
        result++;
    }

    cout << result;



    return 0;
}