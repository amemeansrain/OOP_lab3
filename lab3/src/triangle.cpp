#include "../include/triangle.h"
#include <algorithm>
#include <cmath>

Triangle::Triangle() {
    size_ = 3;
    points_ = new Point[size_];
}

Triangle::Triangle(const Point& point1, const Point& point2, const Point& point3) {
    size_ = 3;
    points_ = new Point[size_]{point1, point2, point3};
}

Triangle::Triangle(const Triangle& other) {
    size_ = other.size_;
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        points_[i] = other.points_[i];
}

Point Triangle::getCenter() const {
    double cx = 0, cy = 0;

    for (size_t i = 0; i < size_; ++i) {
        cx += points_[i].x;
        cy += points_[i].y;
    }

    cx /= size_;
    cy /= size_;

    return Point{cx, cy};
}

double Triangle::getArea() const {
    double a = std::sqrt(std::pow(points_[1].x - points_[0].x, 2) +
                         std::pow(points_[1].y - points_[0].y, 2));
    double b = std::sqrt(std::pow(points_[2].x - points_[1].x, 2) +
                         std::pow(points_[2].y - points_[1].y, 2));
    double c = std::sqrt(std::pow(points_[0].x - points_[2].x, 2) +
                         std::pow(points_[0].y - points_[2].y, 2));
    
    double p = (a + b + c) / 2;
    
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::print(std::ostream& ostream) const {
    for (size_t i = 0; i < size_; ++i)
        ostream << "(" << points_[i].x << ", " << points_[i].y << ") ";
}

void Triangle::read(std::istream& istream) {
    if (points_)
        delete[] points_;

    size_ = 3;  // Исправлено с 4 на 3
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        istream >> points_[i].x >> points_[i].y;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this == &other)
        return *this;

    Figure::operator=(other);
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this == &other)
        return *this;

    Figure::operator=(std::move(other));
    return *this;
}

bool Triangle::operator==(const Triangle& other) const {
    if (size_ != other.size_)
        return false;

    Point sorted1[3];
    Point sorted2[3];
    std::copy(points_, points_ + size_, sorted1);
    std::copy(other.points_, other.points_ + other.size_, sorted2);

    auto cmp = [](const Point& a, const Point& b) {
        return (a.x < b.x) || (a.x == b.x && a.y < b.y);
    };

    std::sort(sorted1, sorted1 + size_, cmp);
    std::sort(sorted2, sorted2 + size_, cmp);

    for (size_t i = 0; i < size_; ++i)
        if (!(sorted1[i] == sorted2[i]))  // Использовано то же сравнение, что в Octagon
            return false;

    return true;
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* t = dynamic_cast<const Triangle*>(&other);
    if (t != nullptr)
        return *this == *t;  // Вызов оператора для Triangle
    return false;
}

std::unique_ptr<Figure> Triangle::clone() const {
    return std::unique_ptr<Figure>(new Triangle(*this));
}