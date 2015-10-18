#include <vector>
#include <algorithm>

class Solution {
 public:
  void GenerateCombination(int min_index, int remaining, const std::vector<int> &candidates, std::vector<int> &current_combination, std::vector<std::vector<int> > &combination_list) {

    if (remaining <= 0) {
      if (!remaining) {
        combination_list.push_back(current_combination);
      }
      return;
    }

    for (int i = min_index; i < candidates.size() && candidates[i] <= remaining; ++i) {
      current_combination.push_back(candidates[i]);
      GenerateCombination(i, remaining - candidates[i], candidates, current_combination, combination_list);
      current_combination.pop_back();
    }
  }

  std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
    std::vector<int> current_combination;
    std::vector<std::vector<int> > combination_list;
    std::sort(candidates.begin(), candidates.end());
    GenerateCombination(0, target, candidates, current_combination, combination_list);
    return combination_list;
  }
};

int main() {
  return 0;
}
