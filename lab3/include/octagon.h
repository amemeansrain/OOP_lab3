#pragma once
#include <cmath>
#include <iostream>
#include "figure.h"

class Octagon : public Figure {
   protected:
    double getArea() const override;

   public:
    Octagon();
    Octagon(const Point& point1, const Point& point2, const Point& point3, const Point& point4,
            const Point& point5, const Point& point6, const Point& point7, const Point& point8);
    Octagon(const Octagon& other);

    Point getCenter() const override;

    void print(std::ostream& ostream) const override;
    void read(std::istream& istream) override;

    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& other) noexcept;

    bool operator==(const Figure& other) const override;
    bool operator==(const Octagon& other) const;
    std::unique_ptr<Figure> clone() const override;
};