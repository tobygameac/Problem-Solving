#include <vector>

class Solution {
 public:
  void GenerateCombination(int min_num, int max_num, int k, std::vector<int> &current_combination, std::vector<std::vector<int> > &combination_list) {
    if (!k) {
      combination_list.push_back(current_combination);
      return;
    }

    for (int i = min_num; i <= max_num; ++i) {
      current_combination.push_back(i);
      GenerateCombination(i + 1, max_num, k - 1, current_combination, combination_list);
      current_combination.pop_back();
    }
  }

  std::vector<std::vector<int> > combine(int n, int k) {
    std::vector<int> combination;
    std::vector<std::vector<int> > combination_list;
    GenerateCombination(1, n, k, combination, combination_list);
    return combination_list;
  }
};

int main() {
  return 0;
}
