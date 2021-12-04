#include <fstream>
#include <iostream>
#include <array>
#include <vector>

#include "absl/strings/str_split.h"

struct spot {
  int val;
  bool marked;
};

typedef std::array<std::array<spot, 5>, 5> board;

std::vector<std::string> get_input() {
  // std::ifstream input_file("../day4_test.txt");
  std::ifstream input_file("../day4_input.txt");
  std::vector<std::string> input;
  std::string line;
  while (getline(input_file, line)) {
    input.push_back(line);
  }
  return input;
}

bool check_winner(board b) {
  for (int i = 0; i < 5; i++) {
    if (b[i][0].marked && b[i][1].marked && b[i][2].marked && b[i][3].marked &&
        b[i][4].marked) {
      return true;
    }
    if (b[0][i].marked && b[1][i].marked && b[2][i].marked && b[3][i].marked &&
        b[4][i].marked) {
      return true;
    }
  }
  return false;
}

int compute_score(board b) {
  int score = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (!b[i][j].marked) {
        score += b[i][j].val;
      }
    }
  }
  return score;
}

void part1() {
  std::vector<std::string> input = get_input();

  // Parse the first line, which contains the calls.
  std::vector<std::string> calls_tmp = absl::StrSplit(input[0], ",");
  std::vector<int> calls;
  for (auto c : calls_tmp) {
    calls.push_back(std::atoi(c.c_str()));
  }

  // Parse the boards
  input.erase(input.begin(), input.begin() + 2);

  std::vector<board> boards;
  while (true) {
    board b;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        spot s{std::atoi(input[i].substr(j * 3, j * 3 + 2).c_str()), false};
        b[i][j] = s;
      }
    }
    boards.push_back(b);
    if (input.size() <= 5) {
      break;
    }
    input.erase(input.begin(), input.begin() + 6);
  }

  bool found_first_winner = false;
  std::vector<bool> board_has_won(boards.size());
  int boards_left = boards.size();

  for (int call : calls) {
    // Mark the call.
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        for (int b = 0; b < boards.size(); b++) {
          if (boards[b][i][j].val == call) {
            boards[b][i][j].marked = true;
          }
        }
      }
    }
    // Check for winner
    for (int b = 0; b < boards.size(); b++) {
      if (!board_has_won[b] && check_winner(boards[b])) {
        board_has_won[b] = true;
        boards_left--;
        std::cout << "Board " << b << " is winner" << std::endl;
        std::cout << "Score " << compute_score(boards[b]) * call << std::endl;
      }
    }
  }
}

int main() { part1(); }