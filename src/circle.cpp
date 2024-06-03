// Copyright 2022 Mironov Ilya
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include "circle.h"

void Circle::checkOnNegative(double value) {
    if (value < 0) throw std::logic_error("invalid value");
}

Circle::Circle(double r) {
    checkOnNegative(r);
    this->radius = r;
    this->ference = 2 * PI * r;
    this->area = PI * r * r;
}

void Circle::setRadius(double r) {
    checkOnNegative(r);
    this->radius = r;
    this->ference = 2 * PI * r;
    this->area = PI * r * r;
}

void Circle::setFerence(double f) {
    checkOnNegative(f);
    this->ference = f;
    this->radius = f / (2 * PI);
    this->area = PI * radius * radius;
}

void Circle::setArea(double a) {
    checkOnNegative(a);
    this->area = a;
    this->radius = sqrt(a / PI);
    this->ference = 2 * PI * radius;
}

double Circle::getRadius() {
    return radius;
}

double Circle::getFerence() {
    return ference;
}

double Circle::getArea() {
    return area;
}


