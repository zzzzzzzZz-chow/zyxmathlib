#include "point.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Point2d::Point2d() : x{0}, y{0} {}

Point2d::Point2d(const Point2d &point2d) : x{point2d.x}, y{point2d.y} {}

Point2d::Point2d(double x, double y) : x{x}, y{y} {}

Point2d &Point2d::operator=(const Point2d &point) {
  x = point.x;
  y = point.y;
  return *this;
}

Point2d::operator string() const {
  return "x = " + std::to_string(x) + "\t" + "y = " + std::to_string(y);
}

ostream &operator<<(ostream &os, const Point2d &point) {
  return os << static_cast<string>(point);
}

double Point2d::distance(const Point2d &point) const noexcept {
  return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
}

Point2d Point2d::operator*(double number) const noexcept {
  return Point2d{x * number, y * number};
}

Point2d &Point2d::operator*=(double number) noexcept {
  return *this = *this * number;
}

double Point2d::operator*(const Point2d &point) const noexcept {
  return x * point.x + y * point.y;
}

Point2d Point2d::operator/(double number) const noexcept {
  return {x / number, y / number};
}

Point2d &Point2d::operator/=(double number) noexcept {
  return *this = *this / number;
}

bool Point2d::operator==(const Point2d &point) const noexcept {
  return (x - point.x < x * 1.0e-10) && (y - point.y < y * 1.0e-10);
}

bool Point2d::operator<(const Point2d &point) const noexcept {
  return distance(Point2d::zero()) < point.distance(Point2d::zero());
}

bool Point2d::operator<=(const Point2d &point) const noexcept {
  return *this < point && *this == point;
}

bool Point2d::operator>(const Point2d &point) const noexcept {
  return !(*this < point) && *this != point;
}

bool Point2d::operator>=(const Point2d &point) const noexcept {
  return *this > point && *this == point;
}

bool Point2d::operator!=(const Point2d &point) const noexcept {
  return !(*this == point);
}

int Point2d::compare(const Point2d &point) const noexcept {
  if (*this > point)
    return 1;
  if (*this < point)
    return -1;
  return 0;
}

Point2d Point2d::operator+(double number) const noexcept {
  return {x + number, y + number};
}

Point2d &Point2d::operator+=(double number) noexcept {
  return *this = *this + number;
}

Point2d Point2d::operator+(const Point2d &point) const noexcept {
  return {x + point.x, y + point.y};
}

Point2d &Point2d::operator+=(const Point2d &point) noexcept {
  return *this = *this + point;
}

Point2d Point2d::operator-() const noexcept { return {-x, -y}; }

Point2d Point2d::operator-(double number) const noexcept {
  return {x - number, y - number};
}

Point2d &Point2d::operator-=(double number) noexcept {
  return *this = *this - number;
}

Point2d Point2d::operator-(const Point2d &point) const noexcept {
  return {x - point.x, y - point.y};
}

Point2d &Point2d::operator-=(const Point2d &point) noexcept {
  return *this = *this - point;
}

Point2d Point2d::zero() { return Point2d{0, 0}; }
