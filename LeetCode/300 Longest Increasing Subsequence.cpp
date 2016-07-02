class Solution {
 
 public:
  
  int lengthOfLIS(std::vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    std::vector<int> lis(1, nums[0]);
    const size_t N = nums.size();
    for (size_t i = 1; i < N; ++i) {
      if (nums[i] > lis.back()) {
        lis.push_back(nums[i]);
      } else {
        *lower_bound(lis.begin(), lis.end(), nums[i]) = nums[i];
      }
    }
    return lis.size();
  }

};
