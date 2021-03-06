#include <iostream>

/*
 * Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
 * Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k],
 * ближайшего по значению к B[i]. n ≤ 110000, m ≤ 1000.
 */

using namespace std;

void indexSearch(const int *A, int n, const int *B, int m, int *result);

int main() {
    int n = 0;
    cin >> n;

    int *A = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int m = 0;
    cin >> m;

    int *B = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    int *result = new int[m];
    indexSearch(A, n, B, m, result);

    delete[] A;
    delete[] B;

    for (int i = 0; i < m; i++) {
        cout << result[i] << ' ';
    }
    delete[] result;

    return 0;
}

int indexNearestValue(const int *array, int value, int first_index, int last_index) {
    int average_index = 0;

    while (first_index < last_index) {
        average_index = first_index + (last_index - first_index) / 2;
        if (value <= array[average_index]) {
            last_index = average_index;
        } else {
            first_index = average_index + 1;
        }
    }
    return last_index;
}

void indexSearch(const int *A, int n, const int *B, int m, int *result) {
    for (int i = 0; i < m; i++) {
        int indexBuf = 0;
        bool found = false;

        if (A[0] >= B[i]) {
            result[i] = 0;
            continue;
        }

        int j = 1;
        for (; j < n; j *= 2) {
            if (A[j] > B[i]) {
                found = true;
                break;
            }
        }

        if (found) {
            indexBuf = indexNearestValue(A, B[i], j / 2, j);
        } else {
            indexBuf = indexNearestValue(A, B[i], j / 2, n - 1);
        }

        if (indexBuf > 0) {
            if (B[i] - A[indexBuf - 1] <= A[indexBuf] - B[i]) {
                result[i] = indexBuf - 1;
            } else {
                result[i] = indexBuf;
            }
        } else {
            result[i] = indexBuf;
        }
    }
}