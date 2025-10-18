#include "../include/point.h"

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

std::istream& operator>>(std::istream& istream, Point& point) {
    return istream >> point.x >> point.y;
}

std::ostream& operator<<(std::ostream& ostream, const Point& point) {
    return ostream << "(" << point.x << ", " << point.y << ")";
}