class Solution {
 
 public:

  void SubsetsWithDup(std::map<int, size_t> &nums_count, std::map<int, size_t>::iterator it, std::vector<int> current_set, std::vector<std::vector<int> > &subsets) {
    if (it == nums_count.end()) {
      subsets.push_back(current_set);
      return;
    }
    int n = it->first;
    size_t count = it->second;
    ++it;
    for (size_t i = 0; i <= count; ++i) {
      SubsetsWithDup(nums_count, it, current_set, subsets);
      current_set.push_back(n);
    }
  }

  std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
    std::map<int, size_t> nums_count;
    for (int n : nums) {
      ++nums_count[n];
    }
    std::vector<std::vector<int> > subsets;
    SubsetsWithDup(nums_count, nums_count.begin(), std::vector<int>(), subsets);
    return subsets;
  }

};
