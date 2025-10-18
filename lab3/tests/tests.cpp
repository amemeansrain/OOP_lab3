#include <gtest/gtest.h>
#include "../include/point.h"
#include "../include/triangle.h"
#include "../include/square.h"
#include "../include/octagon.h"
#include "../include/array.h"

TEST(PointTest, DefaultConstructor) {
    Point p;
    EXPECT_DOUBLE_EQ(p.x, 0.0);
    EXPECT_DOUBLE_EQ(p.y, 0.0);
}

TEST(PointTest, EqualityOperator) {
    Point p1{1.0, 2.0};
    Point p2{1.0, 2.0};
    Point p3{1.0, 3.0};
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(TriangleTest, ConstructorAndArea) {
    Triangle t({0, 0}, {3, 0}, {0, 4});
    EXPECT_DOUBLE_EQ(static_cast<double>(t), 6.0);  // Используем оператор double()
}

TEST(TriangleTest, Center) {
    Triangle t({0, 0}, {3, 0}, {0, 3});
    Point center = t.getCenter();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(TriangleTest, Equality) {
    Triangle t1({0, 0}, {3, 0}, {0, 4});
    Triangle t2({0, 0}, {3, 0}, {0, 4});
    Triangle t3({0, 1}, {3, 1}, {0, 5});
    
    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

TEST(TriangleTest, EqualityDifferentOrder) {
    Triangle t1({0, 0}, {3, 0}, {0, 4});
    Triangle t2({3, 0}, {0, 4}, {0, 0});
    
    EXPECT_TRUE(t1 == t2);
}

TEST(TriangleTest, Clone) {
    Triangle t1({0, 0}, {3, 0}, {0, 4});
    auto clone = t1.clone();
    
    EXPECT_TRUE(*clone == t1);
    EXPECT_DOUBLE_EQ(static_cast<double>(*clone), static_cast<double>(t1));  // Используем оператор double()
}

TEST(SquareTest, ConstructorAndArea) {
    Square s({0, 0}, {2, 0}, {2, 2}, {0, 2});
    EXPECT_DOUBLE_EQ(static_cast<double>(s), 4.0);  // Используем оператор double()
}

TEST(SquareTest, Center) {
    Square s({0, 0}, {2, 0}, {2, 2}, {0, 2});
    Point center = s.getCenter();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(SquareTest, Equality) {
    Square s1({0, 0}, {2, 0}, {2, 2}, {0, 2});
    Square s2({0, 0}, {2, 0}, {2, 2}, {0, 2});
    Square s3({1, 1}, {3, 1}, {3, 3}, {1, 3});
    
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
}

TEST(SquareTest, EqualityDifferentOrder) {
    Square s1({0, 0}, {2, 0}, {2, 2}, {0, 2});
    Square s2({2, 2}, {0, 2}, {0, 0}, {2, 0});
    
    EXPECT_TRUE(s1 == s2);
}

TEST(SquareTest, Clone) {
    Square s1({0, 0}, {2, 0}, {2, 2}, {0, 2});
    auto clone = s1.clone();
    
    EXPECT_TRUE(*clone == s1);
    EXPECT_DOUBLE_EQ(static_cast<double>(*clone), static_cast<double>(s1));  // Используем оператор double()
}

TEST(OctagonTest, ConstructorAndArea) {
    Octagon o({1, 0}, {0.707, 0.707}, {0, 1}, {-0.707, 0.707},
              {-1, 0}, {-0.707, -0.707}, {0, -1}, {0.707, -0.707});
    
    double area = static_cast<double>(o);  // Используем оператор double()
    EXPECT_NEAR(area, 2.828, 0.001);
}

TEST(OctagonTest, Center) {
    Octagon o({1, 1}, {2, 1}, {3, 2}, {3, 3},
              {2, 4}, {1, 4}, {0, 3}, {0, 2});
    Point center = o.getCenter();
    EXPECT_DOUBLE_EQ(center.x, 1.5);
    EXPECT_DOUBLE_EQ(center.y, 2.5);
}

TEST(OctagonTest, Equality) {
    Octagon o1({0, 0}, {1, 0}, {2, 1}, {2, 2},
               {1, 3}, {0, 3}, {-1, 2}, {-1, 1});
    Octagon o2({0, 0}, {1, 0}, {2, 1}, {2, 2},
               {1, 3}, {0, 3}, {-1, 2}, {-1, 1});
    Octagon o3({1, 1}, {2, 1}, {3, 2}, {3, 3},
               {2, 4}, {1, 4}, {0, 3}, {0, 2});
    
    EXPECT_TRUE(o1 == o2);
    EXPECT_FALSE(o1 == o3);
}

TEST(OctagonTest, Clone) {
    Octagon o1({0, 0}, {1, 0}, {2, 1}, {2, 2},
               {1, 3}, {0, 3}, {-1, 2}, {-1, 1});
    auto clone = o1.clone();
    
    EXPECT_TRUE(*clone == o1);
    EXPECT_DOUBLE_EQ(static_cast<double>(*clone), static_cast<double>(o1));  // Используем оператор double()
}

TEST(ArrayTest, DefaultConstructor) {
    Array arr;
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_EQ(arr.getCapacity(), 2);
}

TEST(ArrayTest, AddFigures) {
    Array arr;
    arr.addFigure(new Triangle({0, 0}, {3, 0}, {0, 4}));
    arr.addFigure(new Square({0, 0}, {2, 0}, {2, 2}, {0, 2}));
    
    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_GE(arr.getCapacity(), 2);
}

TEST(ArrayTest, TotalArea) {
    Array arr;
    arr.addFigure(new Triangle({0, 0}, {3, 0}, {0, 4}));
    arr.addFigure(new Square({0, 0}, {2, 0}, {2, 2}, {0, 2}));
    
    EXPECT_DOUBLE_EQ(arr.getTotalArea(), 10.0);
}

TEST(ArrayTest, DeleteFigure) {
    Array arr;
    arr.addFigure(new Triangle({0, 0}, {3, 0}, {0, 4}));
    arr.addFigure(new Square({0, 0}, {2, 0}, {2, 2}, {0, 2}));
    
    EXPECT_EQ(arr.getSize(), 2);
    arr.deleteFigure(0);
    EXPECT_EQ(arr.getSize(), 1);
    
    auto figure = arr[0];
    EXPECT_NE(dynamic_cast<Square*>(figure), nullptr);
}

TEST(ArrayTest, CopyConstructor) {
    Array arr1;
    arr1.addFigure(new Triangle({0, 0}, {3, 0}, {0, 4}));
    
    Array arr2(arr1);
    
    EXPECT_EQ(arr1.getSize(), arr2.getSize());
    EXPECT_TRUE(*arr1[0] == *arr2[0]);
    EXPECT_NE(arr1[0], arr2[0]);
}

TEST(ArrayTest, MoveConstructor) {
    Array arr1;
    arr1.addFigure(new Triangle({0, 0}, {3, 0}, {0, 4}));
    
    Array arr2(std::move(arr1));
    
    EXPECT_EQ(arr2.getSize(), 1);
    EXPECT_EQ(arr1.getSize(), 0);
}

TEST(ArrayTest, AssignmentOperator) {
    Array arr1;
    arr1.addFigure(new Triangle({0, 0}, {3, 0}, {0, 4}));
    
    Array arr2;
    arr2 = arr1;
    
    EXPECT_EQ(arr1.getSize(), arr2.getSize());
    EXPECT_TRUE(*arr1[0] == *arr2[0]);
}

TEST(PolymorphismTest, FigurePointer) {
    Figure* fig = new Triangle({0, 0}, {3, 0}, {0, 4});
    EXPECT_DOUBLE_EQ(static_cast<double>(*fig), 6.0);
    delete fig;
}

TEST(PolymorphismTest, ArrayWithDifferentFigures) {
    Array arr;
    arr.addFigure(new Triangle({0, 0}, {3, 0}, {0, 4}));
    arr.addFigure(new Square({0, 0}, {2, 0}, {2, 2}, {0, 2}));
    arr.addFigure(new Octagon({0, 0}, {1, 0}, {2, 1}, {2, 2},
                             {1, 3}, {0, 3}, {-1, 2}, {-1, 1}));
    
    EXPECT_EQ(arr.getSize(), 3);
    
    EXPECT_NE(dynamic_cast<Triangle*>(arr[0]), nullptr);
    EXPECT_NE(dynamic_cast<Square*>(arr[1]), nullptr);
    EXPECT_NE(dynamic_cast<Octagon*>(arr[2]), nullptr);
}

TEST(EdgeCasesTest, EmptyArrayOperations) {
    Array arr;
    
    EXPECT_EQ(arr[0], nullptr);
    EXPECT_EQ(arr.getTotalArea(), 0.0);
    
    arr.deleteFigure(0);
    EXPECT_EQ(arr.getSize(), 0);
}

TEST(EdgeCasesTest, InvalidIndex) {
    Array arr;
    arr.addFigure(new Triangle({0, 0}, {1, 0}, {0, 1}));
    
    EXPECT_EQ(arr[5], nullptr);
    EXPECT_EQ(arr.getFigure(5), nullptr);
}

TEST(IOTest, TriangleIO) {
    Triangle t1({1, 2}, {3, 4}, {5, 6});
    
    std::stringstream ss;
    t1.print(ss);
    
    std::string output = ss.str();
    EXPECT_TRUE(output.find("1") != std::string::npos);
    EXPECT_TRUE(output.find("2") != std::string::npos);
}

TEST(IOTest, SquareIO) {
    Square s1({1, 2}, {3, 4}, {5, 6}, {7, 8});
    
    std::stringstream ss;
    s1.print(ss);
    
    std::string output = ss.str();
    EXPECT_TRUE(output.find("1") != std::string::npos);
    EXPECT_TRUE(output.find("2") != std::string::npos);
}

TEST(IOTest, OctagonIO) {
    Octagon o1({1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}, {13, 14}, {15, 16});
    
    std::stringstream ss;
    o1.print(ss);
    
    std::string output = ss.str();
    EXPECT_TRUE(output.find("1") != std::string::npos);
    EXPECT_TRUE(output.find("2") != std::string::npos);
}

TEST(PerformanceTest, LargeArray) {
    Array arr;
    
    for (int i = 0; i < 100; ++i) {
        arr.addFigure(new Triangle({0, 0}, {1, 0}, {0, 1}));
    }
    
    EXPECT_EQ(arr.getSize(), 100);
    EXPECT_GE(arr.getCapacity(), 100);
}

// Тесты для проверки корректности геометрических вычислений
TEST(GeometryTest, TriangleAreaConsistency) {
    // Прямоугольный треугольник
    Triangle t1({0, 0}, {3, 0}, {0, 4});
    EXPECT_DOUBLE_EQ(static_cast<double>(t1), 6.0);
    
    // Разносторонний треугольник
    Triangle t2({0, 0}, {4, 0}, {2, 3});
    EXPECT_NEAR(static_cast<double>(t2), 6.0, 0.001);
}

TEST(GeometryTest, SquareAreaConsistency) {
    // Квадрат со стороной 2
    Square s1({0, 0}, {2, 0}, {2, 2}, {0, 2});
    EXPECT_DOUBLE_EQ(static_cast<double>(s1), 4.0);
    
    // Квадрат со стороной 5
    Square s2({0, 0}, {5, 0}, {5, 5}, {0, 5});
    EXPECT_DOUBLE_EQ(static_cast<double>(s2), 25.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}