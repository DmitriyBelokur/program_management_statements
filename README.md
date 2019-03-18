# Операторы управляющие поведением программы
Что такое управляющие операторы? Это набор операторов которые влияют на ход выполнения проограммы, т.е. мы меняем порядок выполнения программы. До этого мы рассматривали последовательное выполнение программы, т.е. от начала блока и доконца выполняя последовательно все инструкции. Но иногда необходимо выполнить групу операторов или один оператор в зависимости от условия, или несколько раз выполнить одну и туже групу операторов. В С++ различают условные операторы и итерационные(циклы), а также оператор перехода. Разница в том как они могут быть выполнены.
Чаще условные операторы применяються с логическими операторами и операторами отношения
### Условный оператор if
Этот условный оператор выполняеться если истино его условие. Он имеет три формы:
```
// простой if
if (условие) {
  оператор;
}
// или
if (условие)
  оператор;

// в виде ветки, т.е. условные переходы, в случае истиности выполнить одно условие, в случае ложи выполнить другое условие
if (условие) {
  оператор; // в случае истиности
} else {
  оператор; // в случае успеха ложи
}

// и проверки условия в случае ложи
if (условие) {
  оператор; // в случае истиности
} else if (условие) {
  оператор;
}
```
```cpp
#include <cstdio>
#include <iostream>

void IsNumberPositive(int number) {
  printf("IsNumberPositive\n");
  if (number > 0) {
    printf("number > 0\n");
  } else if (number == 0) {
    printf("number == 0\n");
  } else {
    printf("number < 0\n");
  } 
}

bool IsOdd(size_t number) {
  return number & 1;
}


int main(int argc, char const *argv[]) {
  
  IsNumberPositive(10);
  IsNumberPositive(0);
  IsNumberPositive(-10);

  printf("Please enter number :");
  size_t value;
  std::cin >> value;

  if (IsOdd(value)) {
    printf("Number %zd is odd \n", value);
  } else {
    printf("Number %zd is even \n", value);
  }

  printf("Please enter number :");
  if ((std::cin >> value, IsOdd(value))) {
    printf("Number %zd is odd \n", value);
  } else {
    printf("Number %zd is even \n", value);
  }

  // работает только начиная с С++17
  /*if (size_t value1 = 0; std::cin >> value1) {
    if (IsOdd(value1)) {
      printf("Number %zd is odd \n", value1);
    } else {
      printf("Number %zd is even \n", value1);
    }
  }*/

  printf("Please enter number :");
  if (std::cin >> value) {
    printf("You are entered %zd\n", value);
  } else {
    printf("Error in stdin stream \n");
  }

  printf("Please enter number :");
  std::cin >> value;
  if (value > 100 && value < 200) {
    printf("value %d is in range (100..200):");
  } else {
    printf("value %d is not in range (100..200):");
  }

  printf("Please enter number :");
  std::cin >> value;
  if (value > 100 && value < 200) {
    if (value >= 50 && value <= 70) {
      printf("value %d is in range [50..70]:");
    } else {
      printf("value %d is in range (100..200):");
    }
  } else {
    printf("value %d is not in range (100..200):");
  }

  return 0;
}

```
## Оператор выбора switch
В простой форме оператор switch призван заментить многословный оператор if, т.е. вместо многословных `if else if`(который может быть более запутанный), используються читаемый выбор.
```cpp
if (x == 5) {

} else if (x == 7) {

} else if (x == 8) {

} else if (x == 10 || x == 20) {

}

switch (x) {
 case 5: {
  break;
 }
 case 7:
  break;
 case 8:
  break;
 case 10: case 20:
  break;
 default:
  break;
}
```
Важным замечанием switch оператора есть то что после каждой ветки должно идти так называемое прерываение выплнения ветки, иногда это break, а иногда это return, если этого не выполнить то будет выполняться следующая ветка после выпоняемой ветки. Иногда компилятор выдает предупреждение, что мы так называемое проваливаемся (fall through).
В С++17 есть специальный атрибут [[fallthrough]] который подавляет варнинги компилятора, о том что мы намерено так сделали, т.е. провал между ветками. Ну и показывает читаемому человеку что мы намерено так поступили.
```cpp

#include <iostream>

enum EnumTest{
  FIRST = 1,
  SECOND,
  THIRD,
  FOURTH
};

void PrintEnumValue(EnumTest value) {
  switch (value)
  {
    case FIRST:
      printf("FIRST\n");
      break;
    case SECOND:
      printf("SECOND\n");
      break;
    case THIRD:
      printf("THIRD\n");
      break;
    case FOURTH:
      printf("FOURTH\n");
      break;
    default:
      printf("UNDEFINED\n");
      break;
  }
}

enum Bitset{
  FIRST_SET_BIT = 1UL << 0,
  SECOND_SET_BIT = 1UL << 1,
  THIRD_SET_BIT = 1UL << 2,
  FOURTH_SET_BIT = 1UL << 3
};

void CheckSetBit(Bitset value, Bitset bit) {
  switch (value & bit)
  {
    case FIRST_SET_BIT:
      printf("Set first bit\n");
      break;
     case SECOND_SET_BIT:
      printf("Set second bit\n");
      break;
     case THIRD_SET_BIT:
      printf("Set third bit\n");
      break;
     case FOURTH_SET_BIT:
      printf("Set forth bit\n");
      break;
    default:
      printf("Unset bit\n");
      break;
  }
}

int main(int argc, char const *argv[]) {
  std::cout << "Please enter number" << std::endl;
  int value;
  std::cin >> value;
  switch (value)
  {
    case 1:
      printf("equal if (x == 1)\n");
      break;
    case 2:
      printf("equal else if (x == 2)\n");
      break;
    case 3: case 4:
      printf("equal else if (x == 3 || x == 4)\n");
      break;
    default:
      printf("equal else\n");
      break;
  }

  PrintEnumValue(EnumTest::FIRST);
  PrintEnumValue(static_cast<EnumTest>(value));

  Bitset flag = static_cast<Bitset>(Bitset::FIRST_SET_BIT | Bitset::SECOND_SET_BIT);
  CheckSetBit(flag, Bitset::SECOND_SET_BIT);
  CheckSetBit(flag, Bitset::FOURTH_SET_BIT);
  return 0;
}

```
## Операторы цикла
Циклические операторы в отличие от условных, призваны повторять операции n-е количество раз.
### Оператор цикла for
Повторяет условие пока условие не станит ложным. Использовать цикл for необходимо, если мы точно знаем сколько раз его надо выполнить

Его синтаксис следующий
```
for (начальное инициализация; условие; итерация )
```

Каждый из элементов цикла for может быть опущен, т.е может иметь вид
```
for(;;) // такой цикл называеться бесконечным
```
Смысл опреатора следующий, сначало выполняеться инициализация, потом проверяеться условие, выполнить тело цикла а затем итерацию, и т.д выполнять пока условие истино.
```cpp
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[]) {
/*  for(;;) {
    std::cout << "please enter number for summ count or zero for exit" << std::endl;
    size_t count;
    std::cin >> count;
    long long summ = 0;
    if (count > 0) {
      for (size_t i = 0; i < count; ++i) {
        std::cout << "please enter number for summ value" << std::endl;
        int tmp;
        std::cin >> tmp;
        summ += tmp;
      }
      auto avarage = summ / static_cast<double>(count);
      std::cout << "Avarage of summ " << summ << " is " << avarage << std::endl;
    } else {
      break;
    }
  }
*/
  const char *str = "Hello World";
  size_t count;
  for (count = 0; *str; ++count, ++str)
    ;
  std::cout << "count char in string " << str << " is " << count << std::endl;
  std::cout << "Check with standard library function " << strlen("Hello World") << std::endl;

  
  str = "Hello World";
  size_t count_alpha = 0;
  for (size_t i = 0; str[i] != '\0';) {
    count_alpha += (str[i++] == 'l');
  }

  std::cout << "count char 'l' in string " << str << " is " << count_alpha << std::endl;

  for (size_t value = 34567, digit = 0; value; value /= 10) {
    if ((digit = (value % 10)) % 2 == 0) {
      std::cout << "digit " << digit << " is even \n";
    } else {
      std::cout << "digit " << digit << " is odd \n";
    }
  }
  std::cout << std::endl;

  return 0;
}
```