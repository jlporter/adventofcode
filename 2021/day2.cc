#include <fstream>
#include <iostream>
#include <vector>

void part1() {
  // std::ifstream input_file("../day2_test.txt");
  std::ifstream input_file("../day2_input.txt");
  std::string line;
  std::vector<int> input;

  // Part 1
  int horizontal = 0;
  int depth = 0;

  while (getline(input_file, line)) {
    // std::cout << line << std::endl;
    int space_pos = line.find(" ");
    std::string dir = line.substr(0, space_pos);
    std::string dist_str = line.substr(space_pos + 1, line.length());
    int dist = atoi(dist_str.c_str());
    if (dir == "forward") {
        horizontal += dist;
    } else if (dir == "down") {
        depth += dist;
    } else if (dir == "up") {
        depth -= dist;
    }
  }
  std::cout << "horizontal = " << horizontal << " depth = " << depth << " total = " << horizontal * depth << std::endl;

}

void part2() {
  // std::ifstream input_file("../day2_test.txt");
  std::ifstream input_file("../day2_input.txt");
  std::string line;
  std::vector<int> input;

  // Part 1
  int aim = 0;
  int horizontal = 0;
  int depth = 0;

  while (getline(input_file, line)) {
    // std::cout << line << std::endl;
    int space_pos = line.find(" ");
    std::string dir = line.substr(0, space_pos);
    std::string dist_str = line.substr(space_pos + 1, line.length());
    int dist = atoi(dist_str.c_str());
    if (dir == "forward") {
        horizontal += dist;
        depth += aim * dist;
    } else if (dir == "down") {
        aim += dist;
    } else if (dir == "up") {
        aim -= dist;
    }
    std::cout << "horizontal = " << horizontal << " depth = " << depth << " aim = " << aim << std::endl;
  }
  std::cout << "horizontal = " << horizontal << " depth = " << depth << " total = " << horizontal * depth << std::endl;

}

int main() {
    part1();
    part2();
}