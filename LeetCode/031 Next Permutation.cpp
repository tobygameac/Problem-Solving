class Solution {
 
 public:
  
  void nextPermutation(std::vector<int> &nums) {
    const int N = nums.size();
    int k = N - 2;
    while (k >= 0 && nums[k] >= nums[k + 1]) {
      --k;
    }
    if (k >= 0) {
      int l = N - 1;
      while (l > k && nums[l] <= nums[k]) {
        --l;
      }
      std::swap(nums[l], nums[k]);
    }
    std::reverse(nums.begin() + k + 1, nums.end());
  }

};
