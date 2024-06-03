// Copyright 2022 Mironov Ilya
#include <stdexcept>
#include "tasks.h"
#include "circle.h"

double EarthAndRope(double LengthRope) {
    if (LengthRope < 0) throw std::logic_error("invalid error");
    const double EarthR = 6378.1;
    Circle oldLength = Circle(EarthR);
    Circle newLength = Circle(EarthR + LengthRope / 1000);
    return newLength.getArea() - oldLength.getArea();
}

double Swimmingpool(double pool, double width) {
    double roadPrice = 1000, fencePrice = 2000;
    Circle poolCircle = Circle(pool);
    Circle poolAndRoadCircle = Circle(pool + width);
    fencePrice *= poolAndRoadCircle.getFerence();
    roadPrice *= (poolAndRoadCircle.getArea() - poolCircle.getArea());
    return roadPrice + fencePrice;
}
