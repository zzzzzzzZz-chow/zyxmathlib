#pragma once
#include <initializer_list>
#include <vector>

template <typename Number> class DynamicVector {
  template <std::size_t dim, typename Number1> friend class StaticVector;

public:
  DynamicVector();
  DynamicVector(const std::initializer_list<Number> &list);
  ~DynamicVector();

  void print() const noexcept;

private:
  std::vector<Number> data;
};
