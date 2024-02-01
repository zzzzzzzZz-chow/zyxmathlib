#include "table_viewer.hpp"
#include <string>

int main() {
  TableViewer t;
  t.set_print_style(
      "what", [](std::any a) { return std::to_string(std::any_cast<int>(a)); });
  t.add_value("what", 123);
  t.set_print_style("赵宇轩", [](std::any a) {
    return std::to_string(std::any_cast<double>(a));
  });
  t.add_value("赵宇轩", 1.0);
  t.add_value("赵宇轩", 1.0);
  t.print();
}
