#include "point.hpp"
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
using namespace std;

Point2d::Point2d() : x{0}, y{0} {}

Point2d::Point2d(const Point2d &point2d) : x{point2d.x}, y{point2d.y} {}

Point2d::Point2d(std::initializer_list<double> list) {
  if (list.size() > 2)
    throw std::range_error("size() > 2");
  if (list.size() == 0)
    x = 0, y = 0;
  if (list.size() == 1)
    x = *list.begin(), y = 0;
  else
    x = *list.begin(), y = *(list.begin() + 1);
}

Point2d::~Point2d() {}

Point2d::operator string() const {
  return "x = " + std::to_string(x) + "\t" + "y = " + std::to_string(y);
}

ostream &operator<<(ostream &os, const Point2d &point) {
  return os << static_cast<string>(point);
}

double Point2d::distance(const Point2d &point) const {
  std::cout << *this << '\n' << point << '\n';
  return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
}

Point2d Point2d::operator*(double number) { return {x * number, y * number}; }

double Point2d::operator*(const Point2d &point) {
  return x * point.x + y * point.y;
}

Point2d zero() { return Point2d{}; }
