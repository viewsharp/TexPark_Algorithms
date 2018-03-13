#include <iostream>

/*
 * Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
 * Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k],
 * ближайшего по значению к B[i]. n ≤ 110000, m ≤ 1000.
 */

using namespace std;

void indexSearch(const int* A, int n, const int* B, int m, int* result);

int main() {
    int n = 0;
    cin >> n;

    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>A[i];
    }

    int m = 0;
    cin >> m;

    int* B = new int[m];
    for (int i = 0; i < m; i++) {
        cin>>B[i];
    }

    int* result = new int[m];
    indexSearch(A, n, B, m, result);

    delete[] A;
    delete[] B;

    for (int i = 0; i < m; i++) {

    }
    delete[] result;

    return 0;
}

void indexSearch(const int* A, int n, const int* B, int m, int* result) {
    int maxBIndex = n;
    for (int k = n-1; k >= 0; k--) {
        if (maxB <= B[k]) {
            maxBIndex = k;
            maxB = B[k];
        }
        if (max <= A[k] + maxB) {
            max = A[k] + maxB;
            i = k;
            j = maxBIndex;
        }
    }
}