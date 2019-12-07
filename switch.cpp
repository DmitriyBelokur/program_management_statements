
#include <iostream>

enum {
  YES_UPPER = 'Y',
  YES_LOWER = 'y',
  NO_UPPER = 'N',
  NO_LOWER = 'n'
};

int main(int argc, char const *argv[]) {
  std::cout << "Please enter Yes or No (Y/y N/n)\n";
  std::cout << ">>> ";
  char answer; 
  std::cin >> answer;
  switch (answer) {
   case YES_UPPER: case YES_LOWER: {
    std::cout << "You said yes" << std::endl;
    break;
   }
   case NO_UPPER: case NO_LOWER: {
    std::cout << "You said no" << std::endl;
    break;
   }
   default:
    std::cout << "Unknown command, please try again...\n";
  }
  return 0;
}
