/* @JUDGE_ID: 1675874 10189 C++ "Skiena Revilla 1.6.2" */
#include <iostream>
#include <string>
#include <vector>

using field_t = std::vector<std::string>;

void process_field(field_t &field) {
  const int N = static_cast<int>(field.size());
  const int M = static_cast<int>(field[0].size());
  for (int row = 1; row < N - 1; ++row)
    for (int col = 1; col < M - 1; ++col) {
      int mine_count = 0;

      if (field[static_cast<size_t>(row)][static_cast<size_t>(col)] == '*')
        continue;

      for (int drow = -1; drow < 2; ++drow)
        for (int dcol = -1; dcol < 2; ++dcol)
          if (field[static_cast<size_t>(row + drow)]
                   [static_cast<size_t>(col + dcol)] == '*')
            ++mine_count;

      std::string num = std::to_string(mine_count);
      field[static_cast<size_t>(row)][static_cast<size_t>(col)] = num[0];
    }
}

bool input_field(std::istream &is, field_t &field) {
  field.clear();

  int n{}, m{};
  is >> n >> m;

  if (n == m && n == 0)
    return false;

  field.push_back(std::string(static_cast<size_t>(m + 2), '.'));

  for (int i = 0; i < n; ++i) {
    std::string field_line{"."};
    std::string line;
    is >> line;
    field_line.append(line);
    field_line.append(".");
    field.push_back(field_line);
  }

  field.push_back(std::string(static_cast<size_t>(m + 2), '.'));

  return true;
}

void output_field(std::ostream &os, int field_no, field_t const &field) {
  const auto N = field.size();
  const auto M = field[0].size();

  if (field_no > 1)
    os << "\n";

  os << "Field #" << field_no << ":\n";
  for (size_t row = 1; row < N - 1; ++row) {
    for (size_t col = 1; col < M - 1; ++col)
      os << field[row][col];
    os << "\n";
  }
}

int main() {
  int field_no = 0;
  field_t field;

  while (input_field(std::cin, field)) {
    ++field_no;
    process_field(field);
    output_field(std::cout, field_no, field);
  }
}
