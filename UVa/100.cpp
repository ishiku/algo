/* @JUDGE_ID: 1675874 100 C++ "Skiena Revilla 1.6.1" */

#include <algorithm>
#include <iostream>

using number = unsigned long long;

number loop_length(number n) {
  number loop_length = 1;

  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    ++loop_length;
  }

  return loop_length;
}

number max_loop_length(number a, number b) {
  if (a > b)
    std::swap(a, b);

  number max_loop_length{};
  for (auto i = a; i <= b; ++i) {
    max_loop_length = std::max(max_loop_length, loop_length(i));
  }
  return max_loop_length;
}

int main() {
  number a{}, b{};
  while (std::cin >> a >> b)
    std::cout << a << " " << b << " " << max_loop_length(a, b) << std::endl;
}

/*
Замечания:
На данный момент для данного N
- нельзя вычислить макимальное значение элемента в последовательности
- нельзя вычислить длину длину цикла.

Как следствие, подходящий тип для представления значений последовательности
можно определить только опытным путем.
*/