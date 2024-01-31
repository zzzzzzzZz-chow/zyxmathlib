#include <iostream>
#include <string>

class Point2d {
public:
  /**
   * 默认构造函数
   * @code {
   *
   *   auto point = Point2d{};
   *
   *   -------------^^^^^^^^^^
   *
   * }
   */
  Point2d();
  /**
   * 拷贝构造函数
   * @para
   * const Point2d& 拷贝参照对象
   * @code {
   *
   *   auto point1 = Point2d{};
   *
   *   auto point2 = Point2d{point1};
   *
   *   --------------^^^^^^^^^^^^^^^^
   *
   * }
   */
  Point2d(const Point2d &);
  Point2d(std::initializer_list<double>);
  Point2d &operator=(const Point2d &);
  ~Point2d();
  operator std::string() const;
  friend std::ostream &operator<<(std::ostream &, const Point2d &);
  double distance(const Point2d &) const;
  Point2d operator*(double) const;
  double operator*(const Point2d &) const;
  bool operator==(const Point2d &) const;
  bool operator<(const Point2d &) const;
  bool operator<=(const Point2d &) const;
  bool operator>(const Point2d &) const;
  bool operator>=(const Point2d &) const;
  bool operator!=(const Point2d &) const;
  int compare(const Point2d &) const;

public:
  static Point2d zero();

private:
  double x;
  double y;
};
