#include "../include/octagon.h"
#include <algorithm>

Octagon::Octagon() {
    size_ = 8;
    points_ = new Point[size_];
}

Octagon::Octagon(const Point& point1, const Point& point2, const Point& point3, const Point& point4,
                     const Point& point5, const Point& point6, const Point& point7, const Point& point8) {
    size_ = 8;
    points_ = new Point[size_]{point1, point2, point3, point4, point5, point6, point7, point8};
}

Octagon::Octagon(const Octagon& other) {
    size_ = other.size_;
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        points_[i] = other.points_[i];
}

Point Octagon::getCenter() const {
    double cx = 0, cy = 0;

    for (size_t i = 0; i < size_; ++i) {
        cx += points_[i].x;
        cy += points_[i].y;
    }

    cx /= size_;
    cy /= size_;

    return Point{cx, cy};
}

double Octagon::getArea() const {
    double area = 0.0;
        
    for (size_t i = 0; i < size_; ++i) {
        size_t next = (i + 1) % size_;
        area += points_[i].x * points_[next].y - 
                points_[next].x * points_[i].y;
    }
    
    area = std::abs(area) / 2;

    return area;
}

void Octagon::print(std::ostream& ostream) const {
    for (size_t i = 0; i < size_; ++i)
        ostream << "(" << points_[i].x << ", " << points_[i].y << ") ";
}

void Octagon::read(std::istream& istream) {
    if (points_)
        delete[] points_;

    size_ = 4;
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        istream >> points_[i].x >> points_[i].y;
}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this == &other)
        return *this;

    Figure::operator=(other);
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this == &other)
        return *this;

    Figure::operator=(std::move(other));
    return *this;
}

bool Octagon::operator==(const Octagon& other) const {
    if (size_ != other.size_)
        return false;

    Point sorted1[8];
    Point sorted2[8];
    std::copy(points_, points_ + size_, sorted1);
    std::copy(other.points_, other.points_ + other.size_, sorted2);

    auto cmp = [](const Point& a, const Point& b) {
        return (a.x < b.x) || (a.x == b.x && a.y < b.y);
    };

    std::sort(sorted1, sorted1 + size_, cmp);
    std::sort(sorted2, sorted2 + size_, cmp);

    for (size_t i = 0; i < size_; ++i)
        if (!(sorted1[i] == sorted2[i]))
            return false;

    return true;
}

bool Octagon::operator==(const Figure& other) const {
    if (const Octagon* o = dynamic_cast<const Octagon*>(&other))
        return *this == *o;
    return false;
}

std::unique_ptr<Figure> Octagon::clone() const {
    return std::unique_ptr<Figure>(new Octagon(*this));
}