#include <cstdio>
#include <iostream>
#include <limits>

int main(int argc, char const *argv[]) {

  const short kShortMin = std::numeric_limits<short>::min();
  const short kShortMax = std::numeric_limits<short>::max();
  int value1;
  // предлагаем пользователю ввести число в указанном диапазоне
  std::cout << "Please enter number for value1 in range [" << kShortMin
                                                           << " ... "
                                                           << kShortMax
                                                           << "]"
                                                           << std::endl;

  // ожидаем ввода от пользователя
  std::cin >> value1;

  if (value1 < kShortMin || value1 > kShortMax) {
    std::cout << "You entered an invalid value for value1, please try again\n";
    return 1;
  }

  int value2;
  std::cout << "Please enter number for value2 in range [" << kShortMin
                                                           << " ... "
                                                           << kShortMax
                                                           << "]"
                                                           << std::endl;

  // ожидаем ввода от пользователя
  std::cin >> value2;

  if (value2 < kShortMin || value2 > kShortMax) {
    std::cout << "You entered an invalid value, please try again\n";
    return 1;
  }

  std::cout << value1 << " " << value2 << std::endl;
  return 0;
}
