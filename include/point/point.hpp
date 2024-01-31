#include <iostream>
#include <string>

class Point2d {
public:
  Point2d();
  Point2d(const Point2d &);
  Point2d(std::initializer_list<double>);
  ~Point2d();
  operator std::string() const;
  friend std::ostream &operator<<(std::ostream &, const Point2d &);
  double distance(const Point2d &) const;
  Point2d operator*(double);
  double operator*(const Point2d &);

public:
  static Point2d zero();

private:
  double x;
  double y;
};
