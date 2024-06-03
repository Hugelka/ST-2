// Copyright 2022 Mironov Ilya
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
 private:
    const double PI = 3.14159;
    double radius;
    double ference;
    double area;
    void checkOnNegative(double value);
 public:
    explicit Circle(double r);

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    double getRadius();
    double getFerence();
    double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
