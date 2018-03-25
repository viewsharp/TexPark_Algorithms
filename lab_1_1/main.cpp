#include <iostream>
#include <climits>

/*
 * Даны два массива целых чисел одинаковой длины A[0..n-1] и B[0..n-1].
 * Необходимо найти первую пару индексов i0 и j0, i0 <= j0, такую что A[i0] + B[j0] = max {A[i] + B[j],
 * где 0 <= i < n, 0 <= j < n, i <= j}. Время работы - O(n). n ≤ 100000.
 */

using namespace std;

void indexSearch(const int *A, const int *B, int n, int &i, int &j);

int main() {
    int n = 0;
    cin >> n;

    int *A = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int *B = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int i = 0;
    int j = 0;

    indexSearch(A, B, n, i, j);

    delete[] A;
    delete[] B;

    cout << i << ' ' << j << endl;

    return 0;
}

void indexSearch(const int *A, const int *B, int n, int &i, int &j) {
    int max = INT_MIN;
    int maxB = INT_MIN;
    int maxBIndex = n;
    for (int k = n - 1; k >= 0; k--) {
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