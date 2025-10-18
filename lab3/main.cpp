#include "include/array.h"
#include "include/point.h"
#include "include/triangle.h"
#include "include/square.h"
#include "include/octagon.h"
#include <iostream>

int main() {
    Triangle triangle({0, 0}, {3, 0}, {0, 4});
    Square square({0, 0}, {2, 0}, {2, 2}, {0, 2});
    Octagon octagon({0, 0}, {1, 0}, {2, 1}, {2, 2}, 
                   {1, 3}, {0, 3}, {-1, 2}, {-1, 1});

    std::cout << "Triangle: ";
    triangle.print(std::cout);
    std::cout << "Center: (" << triangle.getCenter().x << ", " << triangle.getCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(triangle) << std::endl;

    std::cout << "Square: ";
    square.print(std::cout);
    std::cout << "Center: (" << square.getCenter().x << ", " << square.getCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(square) << std::endl;

    std::cout << "Octagon: ";
    octagon.print(std::cout);
    std::cout << "Center: (" << octagon.getCenter().x << ", " << octagon.getCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(octagon) << std::endl << std::endl;

    Array arr;
    arr.addFigure(new Triangle(triangle));
    arr.addFigure(new Square(square));
    arr.addFigure(new Octagon(octagon));

    arr.printFigures();

    std::cout << "Total area: " << arr.getTotalArea() << std::endl;

    Figure* figure = arr[1];
    std::cout << "Figure at index 1: ";
    figure->print(std::cout);
    std::cout << "Area: " << static_cast<double>(*figure) << std::endl << std::endl;

    auto clonedTriangle = triangle.clone();
    std::cout << "Cloned triangle: ";
    clonedTriangle->print(std::cout);
    std::cout << "Area: " << static_cast<double>(*clonedTriangle) << std::endl;
    std::cout << "Original == Clone: " << (triangle == *clonedTriangle ? "true" : "false") << std::endl << std::endl;

    Triangle triangle2({0, 0}, {3, 0}, {0, 4}); // Такой же треугольник
    Triangle triangle3({0, 0}, {4, 0}, {0, 3}); // Другой треугольник
    
    std::cout << "Triangle1 == Triangle2 (same): " << (triangle == triangle2 ? "true" : "false") << std::endl;
    std::cout << "Triangle1 == Triangle3 (different): " << (triangle == triangle3 ? "true" : "false") << std::endl << std::endl;

    Figure* figures[] = {new Triangle({0, 0}, {1, 0}, {0, 1}), 
                        new Square({0, 0}, {1, 0}, {1, 1}, {0, 1}),
                        new Octagon({1, 0}, {0.707, 0.707}, {0, 1}, {-0.707, 0.707},
                                   {-1, 0}, {-0.707, -0.707}, {0, -1}, {0.707, -0.707})};

    for (int i = 0; i < 3; ++i) {
        std::cout << "Figure " << i << " type: ";
        if (dynamic_cast<Triangle*>(figures[i])) std::cout << "Triangle, ";
        else if (dynamic_cast<Square*>(figures[i])) std::cout << "Square, ";
        else if (dynamic_cast<Octagon*>(figures[i])) std::cout << "Octagon, ";
        
        std::cout << "Area: " << static_cast<double>(*figures[i]) << std::endl;
        delete figures[i];
    }

    return 0;
}