//
// Created by viewsharp on 23.03.18.
//

#include "point.h"

const bool operator<(const Point &left, const Point &right) {
    return left.end < right.end or (left.end == right.end and left.begin > right.begin);
}
