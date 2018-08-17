#include <iostream>

/*
 * Вычислить площадь выпуклого n-угольника, заданного координатами своих вершин.
 * Вначале вводится количество вершин, затем последовательно целочисленные координаты всех вершин
 * в порядке обхода против часовой стрелки. n < 1000, координаты < 10000
 */

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    int firstX = 0;
    int firstY = 0;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    float result = 0;

    cin >> firstX >> firstY;

    x1 = firstX;
    y1 = firstY;
    for (int i = 0; i < n-1; i++) {
        cin >> x2 >> y2;
        result += (x2 - x1) * (y2 - y1) / 2.0f;
        x1 = x2;
        y1 = y2;
    }
    result += (x1 - firstX) * (y1 - firstY) / 2.0f;

    cout << result;

    return 0;
}