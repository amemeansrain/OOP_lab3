#pragma once
#include <iostream>

struct Point {
    double x{}, y{};

    bool operator==(const Point& other) const;
};

std::istream& operator>>(std::istream& istream, Point& point);
std::istream& operator<<(std::istream& ostream, const Point& point);