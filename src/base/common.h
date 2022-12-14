#ifndef SRC_BASE_COMMON_H_
#define SRC_BASE_COMMON_H_

#include <memory>  

// ANSI colors
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"
#define RESET "\e[0;0m"

enum LogLevel {
  TRACE,
  DEBUG,
  INFO,
  WARN,
  ERROR,
  FATAL,
};

using std::unique_ptr;
using std::shared_ptr;

template <class... Ts>
struct Overloaded : Ts... {
  using Ts::operator()...;
};
template <class... Ts>
Overloaded(Ts...) -> Overloaded<Ts...>;

#endif  // SRC_BASE_COMMON_H_
