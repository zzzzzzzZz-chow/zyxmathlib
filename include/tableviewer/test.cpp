#include "table_viewer.hpp"
#include <string>

consteval int f() { return 2; }
constinit int a = f();

int main() {
  constexpr int a = f();
  TableViewer t;
  t.set_print_style(
      "what", [](std::any a) { return std::to_string(std::any_cast<int>(a)); });
  t.add_value("what", 123);
  t.set_print_style("赵宇轩", [](std::any a) {
    std::string s = std::to_string(std::any_cast<double>(a));
    s.resize(6);
    s += "%";
    return s;
  });
  t.add_value("赵宇轩", 1.0);
  t.add_value("赵宇轩", 1.0);
  t.print();
}
