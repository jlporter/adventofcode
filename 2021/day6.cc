#include <array>
#include <fstream>
#include <iostream>
#include <vector>

#include "absl/strings/str_split.h"
#include "absl/strings/string_view.h"

constexpr absl::string_view kInput = "3,4,1,1,5,1,3,1,1,3,5,1,1,5,3,2,4,2,2,2,1,1,1,1,5,1,1,1,1,1,3,1,1,5,4,1,1,1,4,1,1,1,1,2,3,2,5,1,5,1,2,1,1,1,4,1,1,1,1,3,1,1,3,1,1,1,1,1,1,2,3,4,2,1,3,1,1,2,1,1,2,1,5,2,1,1,1,1,1,1,4,1,1,1,1,5,1,4,1,1,1,3,3,1,3,1,3,1,4,1,1,1,1,1,4,5,1,1,3,2,2,5,5,4,3,1,2,1,1,1,4,1,3,4,1,1,1,1,2,1,1,3,2,1,1,1,1,1,4,1,1,1,4,4,5,2,1,1,1,1,1,2,4,2,1,1,1,2,1,1,2,1,5,1,5,2,5,5,1,1,3,1,4,1,1,1,1,1,1,1,4,1,1,4,1,1,1,1,1,2,1,2,1,1,1,5,1,1,3,5,1,1,5,5,3,5,3,4,1,1,1,3,1,1,3,1,1,1,1,1,1,5,1,3,1,5,1,1,4,1,3,1,1,1,2,1,1,1,2,1,5,1,1,1,1,4,1,3,2,3,4,1,3,5,3,4,1,4,4,4,1,3,2,4,1,4,1,1,2,1,3,1,5,5,1,5,1,1,1,5,2,1,2,3,1,4,3,3,4,3";
// constexpr absl::string_view kInput = "3,4,3,1,2";

int main() {
  std::vector<std::string> fish_strs = absl::StrSplit(kInput, ",");
  std::vector<long> counts_now(9);
  std::vector<long> counts_next(9);
  for (size_t i = 0; i < fish_strs.size(); i++) {
    counts_now[atoi(fish_strs[i].c_str())]++;
  }

for (int day = 0; day < 256; day++) {
  std::cout << "Day " << day << ":";
  for (auto c: counts_now) {
    std::cout << " " << c;
  }
  std::cout << std::endl;

  for (int i = 0; i < 8; i++) {
    counts_next[i] = counts_now[i+1];
  }
  counts_next[6] += counts_now[0];
  counts_next[8] = counts_now[0];
  counts_now = counts_next;
  std::fill(counts_next.begin(), counts_next.end(), 0);
}

long count = 0;
for (auto c: counts_now) {
  count  += c;
}

std::cout << "Count: " << count << std::endl;

}