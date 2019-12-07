#include <iostream>

int main(int argc, char const *argv[]) {
  char ch;
  do {
    size_t value;
    std::cout << "Please enter number " << std::endl;
    std::cin >> value;
    std::cout << "You are enter " << value << std::endl;
    //если раскомитеть эту строку, то компилятор выдаст ошибку, что переменная опредена в не области видимости
/*    char ch = 'Y'; 
  } while (ch == 'Y');
*/
   std::cout << "Exit? Y : N" << std::endl;
   std::cin >> ch;
  } while (ch != 'Y');

  http://www.diag.com/news/DoWhileFalse.html


  return 0;
}
