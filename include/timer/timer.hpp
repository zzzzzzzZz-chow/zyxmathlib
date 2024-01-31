#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <thread>
#include <variant>

class Timer {
public:
  explicit Timer(std::ostream *os) : m_os{os} {}
  explicit Timer(std::shared_ptr<std::ofstream> os) : m_os{os} {}
  Timer(std::function<void()> callableTask) : m_task{callableTask} {}
  ~Timer() {
    if (m_os)
      std::visit(
          [&](auto &os) {
            *os << (std::chrono::steady_clock::now() - m_time_point).count()
                << std::endl;
          },
          *m_os);
  }

private:
  std::chrono::steady_clock::time_point m_time_point{
      std::chrono::steady_clock::now()};
  std::optional<std::variant<std::ostream *, std::shared_ptr<std::ofstream>>>
      m_os{std::nullopt};
  std::optional<std::function<void()>> m_task{std::nullopt};

  inline static std::thread m_thread{};
};
