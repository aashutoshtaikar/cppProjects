#include <iostream>
#include <string>
#include <variant>
#include <vector>

class TempClass {
  int x{5};
  friend std::ostream& operator<<(std::ostream& out, const TempClass& tclass);
};

std::ostream& operator<<(std::ostream& out, const TempClass& tclass) {
  out << tclass.x;
  return out;
}

template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};

template <class... Ts>
overloaded(Ts...)->overloaded<Ts...>;

int main() {
  TempClass tmp_obj{};
  using SupportedTypes = std::variant<int, double, const char*, TempClass>;

  std::vector<SupportedTypes> vec{1, "ash", 3.2, tmp_obj};
  for (auto& v : vec) {
    std::visit(
        overloaded{
            [](auto arg) { std::cout << arg << ' '; },
            [](double arg) { std::cout << std::fixed << arg << ' '; },
        },
        v);
  }
  return 0;
}
