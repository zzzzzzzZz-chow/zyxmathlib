#pragma once
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

  Point2d(double x, double y);

  /**
   * 拷贝赋值函数
   * @para
   * const Point2d&
   * @code {
   *
   * Point2d point;
   *
   * point = Point2d{};
   *
   * --------^^^^^^^^^^
   *
   * }
   */
  Point2d &operator=(const Point2d &);

  /**
   * 析构函数
   */
  ~Point2d() = default;

  /**
   * 字符串转换函数
   * @code {
   *
   * Point2d point{};
   *
   * std::string string = point;
   *
   * ------------^^^^^^^^^^^^^^^
   *
   * }
   */
  [[nodiscard]] operator std::string() const;

  /**
   * 流输出函数
   * @code {
   *
   * std::cout << Point2d{};
   *
   * ----------^^^^^^^^^^^^^
   *
   * }
   */
  friend std::ostream &operator<<(std::ostream &, const Point2d &);

  /**
   * 两点之间的距离函数
   * @para
   * const Point2d&
   * @code {
   *
   * Point2d point1 = {1, 2};
   *
   * Point2d point2 = {2, 3};
   *
   * point1.distance(point2);
   *
   * ------^^^^^^^^^^^^^^^^^^
   *
   * }
   */
  [[nodiscard]] double distance(const Point2d &) const noexcept;

  /**
   * 向量数乘运算函数
   * @para
   * double
   */
  [[nodiscard]] Point2d operator*(double) const noexcept;

  Point2d &operator*=(double) noexcept;

  /**
   * 向量点乘运算函数
   * @para
   * const Point2d&
   */
  [[nodiscard]] double operator*(const Point2d &) const noexcept;

  [[nodiscard]] Point2d operator/(double) const noexcept;

  Point2d &operator/=(double) noexcept;

  /**
   * 判断两点是否处于同一位子
   * @para
   * const Pont2d&
   */
  [[nodiscard]] bool operator==(const Point2d &) const noexcept;

  /**
   * 判断是否更接近原点
   * @para
   * const Point2d&
   */
  [[nodiscard]] bool operator<(const Point2d &) const noexcept;

  /**
   * 判断是否更接近原点
   * @para
   * const Point2d&
   */
  [[nodiscard]] bool operator<=(const Point2d &) const noexcept;

  /**
   * 判断是否更远离原点
   * @para
   * const Point2d&
   */
  [[nodiscard]] bool operator>(const Point2d &) const noexcept;

  /**
   * 判断是否更远离原点
   * @para
   * const Point2d&
   */
  [[nodiscard]] bool operator>=(const Point2d &) const noexcept;

  /**
   * 判断是否不处于同一位子
   * @para
   * const Point2d&
   */
  [[nodiscard]] bool operator!=(const Point2d &) const noexcept;

  /**
   * 判断谁更接近原点
   * @para
   * const Point2d&
   */
  [[nodiscard]] int compare(const Point2d &) const noexcept;

  [[nodiscard]] Point2d operator+(double) const noexcept;

  Point2d &operator+=(double) noexcept;

  [[nodiscard]] Point2d operator+(const Point2d &) const noexcept;

  Point2d &operator+=(const Point2d &) noexcept;

  [[nodiscard]] Point2d operator-() const noexcept;

  [[nodiscard]] Point2d operator-(double) const noexcept;

  Point2d &operator-=(double) noexcept;

  [[nodiscard]] Point2d operator-(const Point2d &) const noexcept;

  Point2d &operator-=(const Point2d &) noexcept;

public:
  /**
   * 获取原点坐标
   */
  [[nodiscard]] static Point2d zero();

private:
  double x;
  double y;
};
