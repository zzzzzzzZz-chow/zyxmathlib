#include <any>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
class TableViewer {
public:
  TableViewer() = default;
  TableViewer(const TableViewer &) = delete;
  TableViewer(TableViewer &&) = delete;
  TableViewer &operator=(const TableViewer &) = delete;
  TableViewer &operator=(TableViewer &&) = delete;

  void set_print_style(const std::string &,
                       const std::function<std::string(const std::any &)> &);

  void add_value(const std::string &, std::any);

  void print(std::ostream & = std::cout);

private:
  std::vector<std::pair<std::string, std::vector<std::any>>> data;
  std::map<std::string, std::function<std::string(const std::any &)>> style;
};
