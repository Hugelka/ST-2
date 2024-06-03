// Copyright 2022 Mironov Ilya
#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159;

TEST(CircleTests, checkZeroRadius) {
    Circle c = Circle(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, checkNoZeroRadius) {
    Circle c = Circle(2.1);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.1);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2.1 * PI * 2);
    EXPECT_DOUBLE_EQ(c.getArea(), 2.1 * 2.1 * PI);
}

TEST(CircleTests, checkSetZeroRadius) {
    Circle c = Circle(1.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, checkSetNoZeroRadius) {
    Circle c = Circle(1.0);
    c.setRadius(24.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 24.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 24.0 * PI * 2);
    EXPECT_DOUBLE_EQ(c.getArea(), 24.0 * 11.0 * PI);
}

TEST(CircleTests, checkSetZeroFerence) {
    Circle c = Circle(1.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, checkSetNoZeroFerence) {
    Circle c = Circle(1.0);
    c.setFerence(29.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 29.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 29.0 / (2 * PI));
    EXPECT_DOUBLE_EQ(c.getArea(), 29.0 * (29.0 / (2 * PI)) / 2);
}

TEST(CircleTests, checkSetZeroArea) {
    Circle c = Circle(1.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTests, checkSetNoZeroArea) {
    Circle c = Circle(1.0);
    c.setArea(234.4);
    EXPECT_DOUBLE_EQ(c.getArea(), 234.4);
    EXPECT_DOUBLE_EQ(c.getRadius(), sqrt(234.4 / PI));
    EXPECT_DOUBLE_EQ(c.getFerence(), sqrt(234.4 / PI) * 2 * PI);
}

TEST(CircleTests, checkNegativeRadius) {
    Circle c = Circle(1.0);
    ASSERT_ANY_THROW(c.setRadius(-1.0));
}

TEST(CircleTests, checkSetNegativeFerence) {
    Circle c = Circle(1.0);
    ASSERT_ANY_THROW(c.setFerence(-1.0));
}

TEST(CircleTests, checkSetNegativeArea) {
    Circle c = Circle(1.0);
    ASSERT_ANY_THROW(c.setArea(-1.0));
}

TEST(TasksTests, SwimmingpoolNegativeParams) {
    ASSERT_ANY_THROW(Swimmingpool(-1.0, -1.0));
}

TEST(CircleTests, checkSetRadius) {
    Circle c = Circle(5.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 10.0 * PI * 2);
    EXPECT_DOUBLE_EQ(c.getArea(), 10.0 * 10.0 * PI);
}

TEST(CircleTests, checkSetFerence) {
    Circle c = Circle(5.0);
    c.setFerence(20.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 20.0 / (2 * PI));
    EXPECT_DOUBLE_EQ(c.getFerence(), 20.0);
    EXPECT_DOUBLE_EQ(c.getArea(), pow(20.0 / (2 * PI), 2) * PI);
}

TEST(CircleTests, checkSetArea) {
    Circle c = Circle(5.0);
    c.setArea(100.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), sqrt(100.0 / PI));
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * sqrt(100.0 / PI));
    EXPECT_DOUBLE_EQ(c.getArea(), 100.0);
}

TEST(EarthAndRopeTest, checkNegativeRope) {
    EXPECT_THROW(EarthAndRope(-1000.0), std::logic_error);
}

TEST(EarthAndRopeTest, checkEarthRopeDifference) {
    double diff = EarthAndRope(1000.0);
    EXPECT_DOUBLE_EQ(diff, Circle(6378.1 + 1.0).getArea() -
                               Circle(6378.1).getArea());
}

TEST(SwimmingpoolTest, checkRoadPrice) {
    double price = Swimmingpool(10.0, 5.0);
    Circle poolCircle = Circle(10.0);
    Circle poolAndRoadCircle = Circle(10.0 + 5.0);
    double expected = 1000 * (poolAndRoadCircle.getArea() -
                              poolCircle.getArea());
    EXPECT_DOUBLE_EQ(price, expected);
}

TEST(SwimmingpoolTest, checkFencePrice) {
    double price = Swimmingpool(10.0, 5.0);
    Circle poolAndRoadCircle = Circle(10.0 + 5.0);
    double expected = 2000 * poolAndRoadCircle.getFerence();
    EXPECT_DOUBLE_EQ(price, expected);
}
