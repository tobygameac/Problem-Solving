class Solution {
 
 public:
  
  std::vector<int> intersect(std::vector<int> &nums_1, std::vector<int> &nums_2) {
    if (nums_1.size() < nums_2.size()) {
      return intersect(nums_2, nums_1);
    }
    std::map<int, int> count_2;
    for (int n : nums_2) {
      ++count_2[n];
    }
    std::vector<int> ans;
    for (int n : nums_1) {
      if (--count_2[n] >= 0) {
        ans.push_back(n);
      }
    }
    return ans;
  }

};
