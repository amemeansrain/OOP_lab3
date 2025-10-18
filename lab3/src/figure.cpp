#include "../include/figure.h"

Figure::~Figure() {
    delete[] points_;
}

Figure::operator double() const {
    return getArea();
}

size_t Figure::getSize() const {
    return size_;
}

const Point* Figure::getPoints() const {
    return points_;
}

Figure& Figure::operator=(const Figure& other) {
    if (this == &other)
        return *this;

    delete[] points_;
    size_ = other.size_;
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        points_[i] = other.points_[i];
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this == &other)
        return *this;

    delete[] points_;
    points_ = other.points_;
    size_ = other.size_;

    other.points_ = nullptr;
    other.size_ = 0;
    return *this;
}

std::istream& operator>>(std::istream& istream, Figure& figure) {
    return figure.read(istream), istream;
}

std::ostream& operator<<(std::ostream& ostream, const Figure& figure) {
    return figure.print(ostream), ostream;
}