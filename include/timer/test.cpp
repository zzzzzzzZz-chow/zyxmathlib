#include "../number/number.hpp"
#include "timer.hpp"

int main() {
  Number iii{};
  {
    Timer a{&std::cout};
    for (int i = 0; i < 100000000; ++i)
      ++iii;
  }
  std::cout << "iii" << iii << '\n';
  int ii{0};
  {
    Timer a(&std::cout);
    for (int i = 0; i < 100000000; ++i)
      ++ii;
  }
  std::cout << "ii" << ii << '\n';
}
