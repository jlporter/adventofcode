#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::string> get_input() {
  // std::ifstream input_file("../day3_test.txt");
  std::ifstream input_file("../day3_input.txt");
  std::vector<std::string> input;
  std::string line;
  while (getline(input_file, line)) {
    input.push_back(line);
  }
  return input;
}

void part1() {
  std::vector<std::string> input = get_input();
  int line_count = 0;
  std::vector<int> bit_counts;
  for (const auto& line : input) {
    bit_counts.resize(line.length());
    for (int i = 0 ; i < line.length(); i++) {
      if (line[i] == '1') {
        bit_counts[i]++;
      }
    }
    line_count++;
  }

  std::string g, e;
  std::vector<char> most_common_bit;
  for (int i = 0; i < bit_counts.size(); i++) {
    // std::cout << bit_counts[i] << " " << bit_counts.size() << std::endl;
    if (bit_counts[i] > (line_count - bit_counts[i])) {
      g += "1";
      e += "0";
      most_common_bit.push_back('1');
    } else {
      g += "0";
      e += "1";
      most_common_bit.push_back('0');
    }
  }
  std::cout << g << " " << e << std::endl;
  std::cout << stoi(g, 0, 2) * std::stoi(e, 0, 2) << std::endl;
}

void part2() {
  std::vector<std::string> saved_input = get_input();
  std::vector<std::string> input = saved_input;
  std::vector<std::string> input_new;
  int num_bits = input[0].size();

  for (int i = 0; i < num_bits; i++) {
    // Count the number of 1s at this bit position.
    int bit_count = 0;
    for (auto l : input) {
      if (l[i] == '1') {
        bit_count++;
      }
    }
    char b = (bit_count >= (input.size() - bit_count)) ? '1' : '0';
    for (auto l : input) {
      if (l[i] == b) {
        input_new.push_back(l);
      }
    }
    input = input_new;
    input_new.clear();
    if (input.size() == 1) {
      break;
    }
  }
  std::string oxygen = input[0];

  input = saved_input;
  input_new.clear();

  for (int i = 0; i < num_bits; i++) {
    // Count the number of 1s at this bit position.
    int bit_count = 0;
    for (auto l : input) {
      if (l[i] == '1') {
        bit_count++;
      }
    }
    char b = (bit_count >= (input.size() - bit_count)) ? '0' : '1';
    for (auto l : input) {
      if (l[i] == b) {
        input_new.push_back(l);
      }
    }
    input = input_new;
    input_new.clear();
    if (input.size() == 1) {
      break;
    }
  }
  std::string co2 = input[0];
  std::cout << stoi(oxygen, 0, 2) * std::stoi(co2, 0, 2) << std::endl;
}

int main () {
  part1();  
  part2();  
}