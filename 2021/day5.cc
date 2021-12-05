#include <array>
#include <fstream>
#include <iostream>
#include <vector>

#include "absl/strings/numbers.h"
#include "absl/strings/str_split.h"

std::vector<std::string> get_input() {
  // std::ifstream input_file("../day5_test.txt");
  std::ifstream input_file("../day5_input.txt");
  std::vector<std::string> input;
  std::string line;
  while (getline(input_file, line)) {
    input.push_back(line);
  }
  return input;
}

void part1() {
  std::vector<std::vector<int>> board(1000, std::vector<int>(1000, 0));

  std::vector<std::string> input = get_input();
  for (const auto& l : input) {
    std::vector<std::string> point_strs = absl::StrSplit(l, " -> ");
    std::vector<std::string> tmp1 = absl::StrSplit(point_strs[0], ",");
    int x1 = atoi(tmp1[0].c_str());
    int y1 = atoi(tmp1[1].c_str());
    tmp1 = absl::StrSplit(point_strs[1], ",");
    int x2 = atoi(tmp1[0].c_str());
    int y2 = atoi(tmp1[1].c_str());

    if (x1 == x2) {
      if (y1 < y2) {
        for (int i = y1; i <= y2; i++) {
          board[x1][i]++;
        }
      } else {
        for (int i = y2; i <= y1; i++) {
          board[x1][i]++;
        }
      }
    } else if (y1 == y2) {
      if (x1 < x2) {
        for (int i = x1; i <= x2; i++) {
          board[i][y1]++;
        }
      } else {
        for (int i = x2; i <= x1; i++) {
          board[i][y1]++;
        }
      }
    } else {
      // Handle diagonal.
      int x = x1;
      int y = y1;
      int x_dir = (x1 < x2) ? 1 : -1;
      int y_dir = (y1 < y2) ? 1 : -1;
      while (x != x2 && y != y2) {
        board[x][y]++;
        x += x_dir;
        y += y_dir;
      }
      board[x][y]++;
    }

    // std::cout << "\n" << x1 << " " << y1 << " " << x2 << " " << y2 <<
    // std::endl; for (int i = 0; i < 10; i++) {
    //   for (int j = 0; j < 10; j++) {
    //     std::cout << board[j][i] << " ";
    //   }
    //   std::cout << std::endl;
    // }
  }

  std::cout << std::endl;
  int count = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      if (board[i][j] > 1) {
        count++;
      }
    }
  }
  std::cout << count << std::endl;
}

int main() { part1(); }