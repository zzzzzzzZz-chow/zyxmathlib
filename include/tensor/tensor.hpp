#include <array>
#include <cstddef>
#include <iostream>

static std::size_t space_level = 0;

template <std::size_t rank, std::size_t dim, typename NumberType = double>
class Tensor {
public:
  Tensor() {}

protected:
  std::array<Tensor<rank - 1, dim>, dim> data;
  friend std::ostream &operator<<(std::ostream &os, Tensor tensor) {
    for (std::size_t i{0}; i < space_level; ++i)
      os << " ";
    os << "{\n";
    ++space_level;
    for (const auto &it : tensor.data)
      os << it << ",";
    --space_level;
    os << '\n';
    for (std::size_t i{0}; i < space_level; ++i)
      os << " ";
    return os << "}";
  }
};

template <std::size_t dim, typename NumberType>
class Tensor<1, dim, NumberType> {
public:
  Tensor() {}

protected:
  std::array<Tensor<0, 0>, dim> data;
  friend std::ostream &operator<<(std::ostream &os, Tensor tensor) {
    for (std::size_t i{0}; i < space_level; ++i)
      os << " ";
    os << "{\n";
    ++space_level;
    for (const auto &it : tensor.data)
      os << it << ",\t";
    --space_level;
    os << '\n';
    for (std::size_t i{0}; i < space_level; ++i)
      os << " ";
    return os << '}';
  }
};

template <typename NumberType> class Tensor<0, 0, NumberType> {
public:
  Tensor() {}

protected:
  NumberType data;
  friend std::ostream &operator<<(std::ostream &os, Tensor tensor) {
    for (std::size_t i{0}; i < space_level; ++i)
      os << " ";
    return os << tensor.data;
  }
};

template <std::size_t dim, typename NumberType>
class Vector : Tensor<1, dim, NumberType> {
public:
  Vector() : Tensor<1, dim, NumberType>() {}
};

extern void print();
