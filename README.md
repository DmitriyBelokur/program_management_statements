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
  
  // IsNumberPositive(10);
  // IsNumberPositive(0);
  // IsNumberPositive(-10);

  printf("Please enter number :");
  size_t value;
  std::cin >> value;
  
  if (value > 0) {
    std::cout << "number > 0" << std::endl;
  } else if (number == 0) {
    std::cout << "number == 0" << std::endl;
  } else {
    std::cout << "number < 0" << std::endl;
  } 

  if (value & 1) { // check first(0) bit in value id set
    std::cout << "Number " << value << " is odd" << std::endl;
  } else {
    std::cout << "Number " << value << " is even" << std::endl;
  }

  // это условие служит для проверки коректное ли ввел пользователь ввел число с экрана
  std::cout << "Please enter number :" << std::endl;
  if (std::cin >> value) {
    std::cout << "You are entered " << value << std::endl;
  } else {
    std::cout << "error entering number"  << std::endl;
  }

  //  это проверка диапазона числа, т.е. входит ли число в заданный диапазон
  std::cout << "Please enter number :";
  std::cin >> value;
  if (value > 100 && value < 200) {
    if (value >= 50 && value <= 70) {
      std::cout << "value %d is in range [50..70]:" << std::endl;
    } else {
       std::cout << "value %d is in range (100..200):" << std::endl;
    }
  } else {
     std::cout << "value %d is not in range (100..200):" << std::endl;;
  }

  return 0;
}

```
В С++ есть еще проблема так называемого висячего else, т.е. else относиться к ближайшему if как  часть блока, например
```
{
// логическая ошибка мы ожидаем не ту выполняющую ветку else
if (a)
  if (b)
    foo ();
else
  bar ();
}

{
if (a)
 {
   if (b)
     foo();
   else
     bar();
  }
}

```
Вывод с этого следует очень простой, старайтесь в операторе `if` всегда выделять блок спомощью `{}` и у вас не будет множества логических ошибок. 

Но иногда есть некое название понятию `if-else` а именно спагети код. Т.е. вместо сложных запутанных конструкций `if-else` пишут `if` который бы проверял некоректное условие и выходил, этот способ дает больше читабельности вашего кода.
```cpp
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

```
## Оператор выбора switch
Опереатор выбор чем то аналогичный оператору `if-else` с линейной формой выбора. Но оператор выбора к сожалению не такой гибкий как оператор `if-else`
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
Важным замечанием switch оператора есть то что после каждой ветки должно идти так называемое прерываение выплнения ветки, иногда это break, а иногда это return, если этого не выполнить то будет выполняться следующая ветка после выпоняемой ветки. Иногда компилятор выдает предупреждение, что мы так называемое проваливаемся (fall through). Но иногда это нормальное поведение выполнение следующей ветки, но для этого надо добавить некий коментарии что вы намеренно так делаете.

```cpp

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

```

Стоит сделать важное замечание что значение выражение в ветках case должны быть или литералом или константой(т.е. compile time выражением), но не может быть переменной или константой значение которой может быть изестно на этапе выполнения программы.

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

```
Стоит помнить всегда что тип счетчика стоит выбирать как `size_t`, и тогда возможных проблем с бесконечным циклом вы точно не получите.
### Оператор while
Если например при работе c for мы знаем количество итераций, например при обходе массива, то при работе c оператором while, это если мы не значем точное количество операций, и итерационная переменная может быть гибкая. Еще важным отличием оператора while от for есть то что итерационная переменная всегда выполняеться в конце итерации цикла for, то такой итерации в цикле while нет.
Оператор while работает следующим образом пока условие истино выполняеться условие
```
while(условие) {
  body
}
```
```cpp
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

```
### Оператор цикла do while
Отличием оператора do while от while, то что выполниться точно один проход, т.е. условие проверяеться не в конце а в начале

```
do {

}while(условие);

```

```cpp
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

  return 0;
}
```

Кому более интересное практическое применения оператора `do while` рекомендую почитать эту ссылку http://www.diag.com/news/DoWhileFalse.html

