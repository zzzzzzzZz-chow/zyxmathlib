#include <cstdint>
#include <iostream>
#include <vector>
class Number {
public:
  Number() : fast_mode{true} {}
  Number(std::int32_t number) : m_z{number} {}
  Number &operator++() {
    if (fast_mode) {
      ++fast_int;
      // if (fast_int > 1000000000) {
      // fast_mode = false;
      //}
    } else {
      for (std::size_t i = 0, size = m_z.size(); i < size; ++i)
        if (m_z[i] > 1000000000) {
          m_z[i] -= 1000000000;
          if (carry == false)
            carry = true;
          else if (i != size - 1)
            m_z[i + 1] += 1;
          else
            m_z.push_back(1);
        }
      ++m_z[0];
    }
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &os, const Number &that) {
    if (that.fast_mode)
      os << that.fast_int << std::endl;
    else {
      for (auto rit = that.m_z.rbegin(), rend = that.m_z.rend(); rit != rend;
           ++rit)
        os << *rit;
    }
    return os;
  }

private:
  std::vector<std::int32_t> m_z{};
  bool fast_mode{true};
  int fast_int{0};
  bool carry{false};
};
