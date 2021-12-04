#include <iostream>
#include <fstream>
#include <vector>

int main () {
    // std::ifstream input_file("../day1_test.txt");
    std::ifstream input_file("../day1_input.txt");
    std::string line;
    std::vector<int> input;
    while (getline(input_file, line)) {
       std::cout << line << std::endl;
       input.push_back(atoi(line.c_str()));
    }

    int num_increases = 0;
    int prev_depth = input[0];
    for (const auto& depth : input) {
        if (depth > prev_depth) {
            num_increases++;
        }
        prev_depth = depth;
    }
    std::cout << "Part 1 Num increases: " << num_increases << std::endl;

    num_increases = 0;
    for (int i = 0; i < input.size() - 3; i++) {
        if ((input[i + 1] + input [i + 2] + input[i + 3]) > 
            (input[i + 0] + input [i + 1] + input[i + 2])) {
                num_increases++;
            }
    }
    std::cout << "Part 2 Num increases: " << num_increases << std::endl;
}