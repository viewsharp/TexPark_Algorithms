//
// Created by viewsharp on 23.03.18.
//

#include "point.h"

const bool operator<(const Point &left, const Point &right) {
    return left.end < right.end or (left.end == right.end and left.begin > right.begin);
}

/*
16
8 12
1 17
4 17
7 12
1 19
1 7
11 19
6 18
12 20
9 17
11 20
13 17
7 19
9 19
12 15
7 9
 */