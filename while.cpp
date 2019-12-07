#include <iostream>


int main(int argc, char const *argv[]) {

  // обнуление числа спомощью битовой арифметики, т.е. применяем оператор сдвига
  size_t value = 23;
  while(value >>= 1) {
    std::cout << "One iteration shift right value = " << value << std::endl;
  }
  std::cout << "value is " << value << std::endl;

  std::cout << "Please enter number ";
  std::cin >> value;

  while(value != 0) {
    std::cout << --value << " ";
  }
  std::cout << std::endl;
  
  // выше два цикла абсолютно одинаковы но использую разный подход
  return 0;
}
