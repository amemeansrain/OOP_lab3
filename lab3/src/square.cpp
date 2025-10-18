#include "../include/square.h"
#include <algorithm>
#include <cmath>

Square::Square() {
    size_ = 4;
    points_ = new Point[size_];
}

Square::Square(const Point& point1, const Point& point2, const Point& point3, const Point& point4) {
    size_ = 4;
    points_ = new Point[size_]{point1, point2, point3, point4};
}

Square::Square(const Square& other) {
    size_ = other.size_;
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        points_[i] = other.points_[i];
}

Point Square::getCenter() const {
    double cx = 0, cy = 0;

    for (size_t i = 0; i < size_; ++i) {
        cx += points_[i].x;
        cy += points_[i].y;
    }

    cx /= size_;
    cy /= size_;

    return Point{cx, cy};
}                  

double Square::getArea() const {
    double dx = points_[1].x - points_[0].x;
    double dy = points_[1].y - points_[0].y;

    double side = std::sqrt(dx * dx + dy * dy);
    return side * side;
}

void Square::print(std::ostream& ostream) const {
    for (size_t i = 0; i < size_; ++i)
        ostream << "(" << points_[i].x << ", " << points_[i].y << ") ";  // Убрана лишняя запятая
}

void Square::read(std::istream& istream) {
    if (points_)
        delete[] points_;

    size_ = 4;
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        istream >> points_[i].x >> points_[i].y;
}

Square& Square::operator=(const Square& other) {
    if (this == &other)
        return *this;

    Figure::operator=(other);
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this == &other)
        return *this;

    Figure::operator=(std::move(other));
    return *this;
}

bool Square::operator==(const Square& other) const {
    if (size_ != other.size_)
        return false;

    Point sorted1[4];
    Point sorted2[4];
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

bool Square::operator==(const Figure& other) const {
    const Square* s = dynamic_cast<const Square*>(&other);
    if (s != nullptr)
        return *this == *s;  // Вызов оператора для Square
    return false;
}

std::unique_ptr<Figure> Square::clone() const {
    return std::unique_ptr<Figure>(new Square(*this));
}