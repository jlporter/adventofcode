#include <fstream>
#include <iostream>
#include <vector>

void part1() {
  // std::ifstream input_file("../day3_test.txt");
  std::ifstream input_file("../day3_input.txt");
  std::string line;
  std::vector<int> bit_counts;
  int line_count = 0;
  while (getline(input_file, line)) {
    bit_counts.resize(line.length());
    for (int i = 0 ; i < line.length(); i++) {
      if (line[i] == '1') {
        bit_counts[i]++;
      }
    }
    line_count++;
  }

  std::string g, e;
  for (int i = 0; i < bit_counts.size(); i++) {
    // std::cout << bit_counts[i] << " " << bit_counts.size() << std::endl;
    if (bit_counts[i] > (line_count - bit_counts[i])) {
      g += "1";
      e += "0";
    } else {
      g += "0";
      e += "1";
    }
  }

  std::cout << g << " " << e << std::endl;
  std::cout << stoi(g, 0, 2) * std::stoi(e, 0, 2) << std::endl;
}

int main () {
  part1();  
}