#include "table_viewer.hpp"
#include <algorithm>
using namespace std;

void TableViewer::set_print_style(const string &title,
                                  const function<string(const any &)> &fun) {
  style[title] = fun;
}

void TableViewer::add_value(const string &title, any value) {
  auto iter = std::find_if(data.begin(), data.end(),
                           [&](const auto &it) { return it.first == title; });
  if (iter == data.end()) {
    data.emplace_back(title, vector<any>{value});
    return;
  }
  iter->second.emplace_back(value);
}

void TableViewer::print(ostream &os) {
  for (const auto &it : data) {
    os << it.first;
    for (const auto &it2 : it.second) {
      string str = style[it.first](it2);
      str.resize(7);
      os << "\t" << str;
    }
    os << '\n';
  }
}
