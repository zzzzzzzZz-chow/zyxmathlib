#include "point.hpp"
#include <iostream>
int main() {
  Point2d a = {1, 2};
  Point2d b = {1, 5};
  double c = a.distance(b);
  std::cout << c << std::endl;
}
