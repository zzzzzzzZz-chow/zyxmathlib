#include <functional>
#include <iostream>
class Test {
  template <typename T, typename... Args>
  void operator()(std::function<T(Args...)> fun, T result) {
    if (fun() == result)
      std::cout << "OK\n";
  }
};
