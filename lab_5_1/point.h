//
// Created by viewsharp on 23.03.18.
//

#ifndef LAB_5_1_POINT_H
#define LAB_5_1_POINT_H


class Point {
public:
    Point() :
            begin(0),
            end(0) {}

    Point(int begin, int end) :
            begin(begin),
            end(end) {}

    int begin;
    int end;
};

const bool operator<(const Point &left, const Point &right);

#endif //LAB_5_1_POINT_H
