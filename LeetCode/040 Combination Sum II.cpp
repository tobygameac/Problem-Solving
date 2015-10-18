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
      GenerateCombination(i + 1, remaining - candidates[i], candidates, current_combination, combination_list);
      current_combination.pop_back();
    }
  }

  std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
    std::vector<int> current_combination;
    std::vector<std::vector<int> > combination_list;
    std::sort(candidates.begin(), candidates.end());
    GenerateCombination(0, target, candidates, current_combination, combination_list);


    std::sort(combination_list.begin(), combination_list.end());
    std::vector<std::vector<int> > combination_list_without_duplicated;
    combination_list_without_duplicated.reserve(combination_list.size());
    for (int i = 0; i < combination_list.size(); ++i) {
      if (!i || combination_list[i] != combination_list[i - 1]) {
        combination_list_without_duplicated.push_back(combination_list[i]);
      }
    }

    return combination_list_without_duplicated;
  }
};

int main() {
  return 0;
}
