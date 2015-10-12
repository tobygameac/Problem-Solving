#include <cmath>
#include <vector>
#include <string>

class Solution {
 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> combination_list;
    combination_list.reserve(pow(4, digits.size()));
    generate_possible_combination(digits, 0, "", combination_list);
    return combination_list;
  }

  void generate_possible_combination(const std::string &digits, int depth, std::string current_string, std::vector<std::string> &combination_list) {
    if (depth == digits.size()) {
      if (depth) {
        combination_list.push_back(current_string);
      }
      return;
    }
    int digit = digits[depth] - '0';
    if (digit >= 0 && digit <= 9) {
      for (int i = 0; i < possible_char_list[digit].size(); ++i) {
        std::string new_string = current_string + possible_char_list[digit][i];
        generate_possible_combination(digits, depth + 1, new_string, combination_list);
      }
    }
  }
  
  const std::string possible_char_list[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

int main() {
  return 0;
}
