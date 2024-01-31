#include "static_vector.hpp"
#include <complex>
#include <stdint.h>
template <std::size_t N> void fun() {
  StaticVector<N, uint8_t> a{};
  StaticVector<N, uint16_t> b{};
  StaticVector<N, uint32_t> c{};
  StaticVector<N, uint64_t> d{};
  StaticVector<N, int8_t> e{};
  StaticVector<N, int16_t> f{};
  StaticVector<N, int32_t> g{};
  StaticVector<N, int64_t> h{};
  StaticVector<N, float> i{};
  StaticVector<N, double> j{};
  StaticVector<N, long double> k{};
  StaticVector<N, std::complex<float>> l{};
  StaticVector<N, std::complex<double>> m{};
  StaticVector<N, std::complex<long double>> n{};
  if constexpr (N > 1)
    fun<N - 1>();
}

template void fun<1024>();
