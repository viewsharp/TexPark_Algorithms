#include <iostream>

/*
 * Дан отсортированный массив целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
 * Для каждого элемента массива B[i] найдите минимальный индекс k минимального элемента массива A,
 * равного или превосходящего B[i]: A[k] >= B[i]. Если такого элемента нет, выведите n.
 * Время работы поиска k для каждого элемента B[i]: O(log(k)).
 * n, m ≤ 10000.
 */

using namespace std;

int searchIndex(const int *array, int size, int value) {
    int left = 0;
    int right = size - 1;
    int middle;

    while (left < right) {
        middle = (right + left) / 2;
        if (array[middle] == value) {
            return middle;
        } else if (array[middle] < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return left;
}


int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;

    int *A = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int b = 0;
    for (int i = 0; i < m; i++) {
        cin >> b;
        cout << searchIndex(A, n, b) << ' ';
    }
    delete[] A;

    return 0;
}
