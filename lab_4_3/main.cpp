#include <iostream>
#include "heap.h"

/*
 * На вокзале есть некоторое количество тупиков, куда прибывают электрички.
 * Этот вокзал является их конечной станцией.
 * Дано расписание движения электричек, в котором для каждой электрички указано время ее прибытия,
 * а также время отправления в следующий рейс. Электрички в расписании упорядочены по времени прибытия.
 * Когда электричка прибывает, ее ставят в свободный тупик с минимальным номером.
 * При этом если электричка из какого-то тупика отправилась в момент времени X,
 * то электричку, которая прибывает в момент времени X, в этот тупик ставить нельзя, а электричку,
 * прибывающую в момент X+1 — можно.
 * В данный момент на вокзале достаточное количество тупиков для работы по расписанию.
 *
 * Напишите программу, которая по данному расписанию определяет, какое минимальное количество тупиков требуется
 * для работы вокзала.
 */

using namespace std;

class Train {
public:
    Train(int input, int output) :
            input(input),
            output(output) {}

    Train() :
            input(0),
            output(0) {}

    int input;
    int output;
};

const bool operator<(const Train first, const Train second) {
    return first.output > second.output;
}

//const bool operator>(const Train first, const Train second) {
//    return first.output < second.output;
//}
//
//const bool operator==(const Train first, const Train second) {
//    return first.output == second.output;
//}
//
//const bool operator<=(const Train first, const Train second) {
//    return not(first > second);
//}

int minEndCount(Train *values, int n);

int main() {
    int n = 0;
    int inBuf = 0;
    int outBuf = 0;

    cin >> n;
    Train *values = new Train[n];

    for (int i = 0; i < n; i++) {
        cin >> inBuf >> outBuf;
        values[i] = Train(inBuf, outBuf);
    }

    cout << minEndCount(values, n);

    delete[] values;

    return 0;
}

int minEndCount(Train *values, int n) {
    int max = 0;
    Heap<Train> buf;

    for (int i = 0; i < n; i++) {
        while (not buf.empty() and buf.top().output < values[i].input) {
            buf.pop();
        }
        buf.push(values[i]);
        if (max < buf.size()) {
            max = buf.size();
        }
    }
    return max;
}