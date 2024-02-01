#include "point.hpp"
int main() {
  Point2d a = {1, 2};
  Point2d b = {4, 6};
  std::cout << a.distance(b) << std ::endl;
}
