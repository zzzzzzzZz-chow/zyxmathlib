#include "dynamic_vector.hpp"
#include <complex>
#include <cstdint>
#include <iostream>

template <typename Number> DynamicVector<Number>::DynamicVector() {}

template <typename Number>
DynamicVector<Number>::DynamicVector(
    const std::initializer_list<Number> &list) {
  data = list;
}

template <typename Number> DynamicVector<Number>::~DynamicVector() {}

template <typename Number> void DynamicVector<Number>::print() const noexcept {
  for (const auto &it : data)
    std::cout << it << ", ";
  std::cout << '\n';
}

template class DynamicVector<uint16_t>;
template class DynamicVector<uint32_t>;
template class DynamicVector<uint64_t>;
template class DynamicVector<int8_t>;
template class DynamicVector<int16_t>;
template class DynamicVector<int32_t>;
template class DynamicVector<int64_t>;
template class DynamicVector<float>;
template class DynamicVector<double>;
template class DynamicVector<long double>;
template class DynamicVector<bool>;
template class DynamicVector<std::complex<float>>;
template class DynamicVector<std::complex<double>>;
template class DynamicVector<std::complex<long double>>;
