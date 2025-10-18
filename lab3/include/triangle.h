#pragma once
#include <cmath>
#include <iostream>
#include "figure.h"

class Triangle : public Figure {
   protected:
    double getArea() const override;

   public:
    Triangle();
    Triangle(const Point& point1, const Point& point2, const Point& point3);
    Triangle(const Triangle& other);

    Point getCenter() const override;

    void print(std::ostream& ostream) const override;
    void read(std::istream& istream) override;

    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;

    bool operator==(const Figure& other) const override;
    bool operator==(const Triangle& other) const;
    std::unique_ptr<Figure> clone() const override;
};