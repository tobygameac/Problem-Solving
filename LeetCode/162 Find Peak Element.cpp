class Solution {
 
 public:
  
  int findPeakElement(std::vector<int> &nums) {
    size_t N = nums.size();
    for (size_t i = 0; i < N; ++i) {
      if ((!i || (nums[i] > nums[i - 1])) && ((i + 1 == N) || (nums[i] > nums[i + 1]))) {
        return i;
      }
    }
    return 0;
  }

};
