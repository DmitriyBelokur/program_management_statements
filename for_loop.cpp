#include <iostream>
#include <cstring>

int main(int argc, char const *argv[]) {

  // пример бесконечного цикла если неверно указать тип счетчика и значение в проверке условия
  uint16_t count = 300;
  for (uint8_t i = 0; i < count; ++i) {
   std::cout << (i + 1) << std::endl;
  }
  
  // разложение числа на цифры и проверка четности каждой цифры
  // стоит заметить что value; в секции для проверки продолжительности цикла это равносильно value != 0
  for (size_t value = 34567, digit = 0; value; value /= 10) {
    if ((digit = (value % 10)) % 2 == 0) {
      std::cout << "digit " << digit << " is even \n";
    } else {
      std::cout << "digit " << digit << " is odd \n";
    }
  }
  return 0;
}
