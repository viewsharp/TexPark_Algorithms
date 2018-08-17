#include <iostream>
#include "mergeSort.h"

using namespace std;

struct Date {
    int day;
    int mounth;
    int year;
    bool start;
};

bool operator<(const Date &left, const Date &right) {
    return left.year * 31 * 12 + left.mounth * 12 + left.day < right.year * 31 * 12 + right.mounth * 12 + right.day;
}

int main() {
//    int n = 0;
//    cin >> n;
//
//    n *= 2;
//    Date *dates = new Date[n];
//
//    for (int i = 0; i < n; i += 2) {
//        cin >> dates[i].day >> dates[i].mounth >> dates[i].year;
//        dates[i].start = true;
//
//        cin >> dates[i + 1].day >> dates[i + 1].mounth >> dates[i + 1].year;
//        dates[i + 1].start = false;
//    }
//
//    mergeSort(dates, dates + n);
//
//    int count = 0;
//    int maxCount = 0;
//
//    for (int i = 0; i < n; i++) {
//        if (dates[i].start) {
//            count++;
//            if (count > maxCount) {
//                maxCount = count;
//            }
//        } else {
//            count--;
//        }
//    }
//
//    cout << maxCount;

    int arr1[12] = {8, 3, 6, 2, 8, 5, 3, 1, 5, 0, 7, 4};
    int arr2[12] = {8, 3, 6, 2, 8, 5, 3, 1, 5, 0, 7, 4};

    std::sort(arr1, arr1 + 12);
    mergeSort(arr2, arr2 + 12);

    return 0;
}