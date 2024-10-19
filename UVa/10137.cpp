/* @JUDGE_ID: 1675874 10137 C++ "Skiena Revilla 1.6.2" */

#include <iomanip>
#include <iostream>
#include <vector>

using expenses_t = std::vector<double>;

int calc_sum(expenses_t const &expenses) {
  double avg{};
  for (auto e : expenses)
    avg += e;
  avg /= static_cast<double>(expenses.size());

  double sum_a{}, sum_b{};
  for (double e : expenses) {
    if (avg > e)
      sum_a += static_cast<int>(avg - e);

    if (avg < e)
      sum_b += static_cast<int>(e - avg);
  }
  return std::max(sum_a, sum_b);
}

bool read_expenses(std::istream &is, expenses_t &expenses) {
  expenses.clear();

  int n{};
  is >> n;
  if (n == 0)
    return false;

  for (int i = 0; i < n; ++i) {
    double d{};
    is >> d;
    expenses.push_back(d * 100.0);
  }

  return true;
}

int main() {
  expenses_t expenses;
  while (read_expenses(std::cin, expenses)) {
    std::cout << "$" << std::fixed << std::setprecision(2)
              << calc_sum(expenses) / 100.00 << std::endl;
  }
}

/*
"Выбрать минимальную сумму денег, которая должна поменять хозяина,
для того, чтобы уравнять (с точностью до цента) расходы всех студентов."

Что такое сумма которая должна поменять хозяина
и что значит ее минимальность (не минимальность).

Сумма которая должна поменять хозяина - это сумма которую должники должны
передать кредиторам чтобы расходы всех студентов уравнялись (с точностью до
цента).

Что значит минимальность этой суммы? Пока видится - дебеторы должны заплатить
так чтобы было лучшее уравновешивание и не больше этого.

Лучшее уравновешивание наступает когда переплата/недоплата сторон минимальна.
Вычислим среднее.

Вычислим суммы целых частей переплат/недоплат.

Используя максимальную их них в качестве суммы рассчетов - получим лучшее
уравновешивание взаиморасчетов.
*/