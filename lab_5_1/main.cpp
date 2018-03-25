#include <iostream>
#include <algorithm>
#include "point.h"
#include "merge_sort.h"

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    Point *points = new Point[n];

    int begin = 0;
    int end = 0;

    for (int i = 0; i < n; i++) {
        cin >> begin >> end;
        points[i] = Point(begin, end);
    }

    mergeSort(points, points + n);

    int count = 2;
    int exEnd1 = points[0].end - 1;
    int exEnd2 = points[0].end;

    for (int i = 1; i < n; i++) {
        if (points[i].begin > exEnd1) {
            if (points[i].begin > exEnd2) {
                count += 2;
                exEnd1 = points[i].end - 1;
                exEnd2 = points[i].end;
            } else {
                count++;
                exEnd1 = exEnd2;
                exEnd2 = points[i].end;
                if (exEnd1 == exEnd2) {
                    exEnd1--;
                    count++;
                }
            }
        }
    }

    delete[] points;

    cout << count;

    return 0;
}