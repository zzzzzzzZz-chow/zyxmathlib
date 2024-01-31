#pragma once
#include "dynamic_vector.hpp"
#include <array>
#include <cstddef>
#include <initializer_list>
template <std::size_t dim, typename Number = double> class StaticVector {
public:
  StaticVector() {}
  StaticVector(const std::initializer_list<Number> &list) {
    for (std::size_t i{0}; const auto &it : list) {
      if (i >= data.max_size()) [[unlikely]]
        break;
      if (i >= list.size()) [[unlikely]]
        data[i] = {};
      else
        data[i] = it;
    }
  }
  ~StaticVector() {}
  DynamicVector<Number> to_dynamic_vector() const {
    DynamicVector<Number> ret;
    for (const auto &it : data)
      ret.data.push_back(it);
    return ret;
  }

private:
  std::array<Number, dim> data;
};
