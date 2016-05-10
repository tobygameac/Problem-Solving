class Solution {
 public:
  int removeDuplicates(std::vector<int> &nums) {
    return std::unique(nums.begin(), nums.end()) - nums.begin();
  }
};
