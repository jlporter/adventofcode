#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "absl/strings/str_split.h"
#include "absl/strings/string_view.h"

void part1() {
  std::ifstream input_file("../day8_test.txt");
  // std::ifstream input_file("../day8_input.txt");
  std::vector<std::string> input;
  std::string line;
  int count = 0;
  while (getline(input_file, line)) {
    std::vector<std::string> tmp = absl::StrSplit(line, " | ");
    std::vector<std::string> outputs = absl::StrSplit(tmp[1], " ");
    for (const auto& o : outputs) {
      int l = o.length();
      if (l == 2 || l == 4 || l == 3 || l == 7) {
        count++;
      }
    }
  }

  // std::cout << "Count = " << count << std::endl;
}

void part2() {
  // std::ifstream input_file("../day8_test.txt");
  std::ifstream input_file("../day8_input.txt");
  std::string line;
  std::unordered_map<std::string, int> segment_display_codes {
    {"abcefg", 0},
    {"cf", 1},
    {"acdeg", 2},
    {"acdfg", 3},
    {"bcdf", 4},
    {"abdfg", 5},
    {"abdefg", 6},
    {"acf", 7},
    {"abcdefg", 8},
    {"abcdfg", 9}
  };
  int total_count = 0;

  while (getline(input_file, line)) {
    std::vector<std::string> tmp = absl::StrSplit(line, " | ");
    std::vector<std::string> input_codes = absl::StrSplit(tmp[0], " ");
    std::vector<std::string> output_codes = absl::StrSplit(tmp[1], " ");

    // Count characters in input codes.
    std::unordered_map<char, int> input_char_counts;
    std::string code_len_2, code_len_4;
    for (auto in : input_codes) {
      if (in.length() == 2) {
        code_len_2 = in;
      } else if (in.length() == 4) {
        code_len_4 = in;
      }
      for (auto c : in) {
        input_char_counts[c]++;
      }
    }

    std::unordered_map<char, char> mappings;
    for (auto count : input_char_counts) {
      if (count.second == 6) {
        mappings[count.first] = 'b';
      } else if (count.second == 4) {
        mappings[count.first] = 'e';
      } else if (count.second == 9) {
        mappings[count.first] = 'f';
      }
    }
    
    // Determine the mapping for c.
    mappings[mappings.contains(code_len_2[0]) ? code_len_2[1] : code_len_2[0]] = 'c';

    // Determine mapping for d.
    for (auto c : code_len_4) {
      if (!mappings.contains(c)) {
        mappings[c] = 'd';
        break;
      }
    }

    for (auto count : input_char_counts) {
      if (count.second == 7 && !mappings.contains(count.first)) {
        mappings[count.first] = 'g';
      } else if (count.second == 8 && !mappings.contains(count.first)) {
        mappings[count.first] = 'a';
      }
    }

    int count = 0;
    for (auto output_code : output_codes) {
      std::string decoded;
      for (auto c : output_code) {
        decoded += mappings[c];
      }
      std::sort(decoded.begin(), decoded.end());
      // std::cout << output_code << " " << segment_display_codes[decoded] << std::endl;
      count = count*10 + segment_display_codes[decoded];
    }
    total_count += count;
    // std::cout << count << std::endl;
  }

  std::cout << total_count << std::endl;

}

int main() {
  // part1();
  part2();
}