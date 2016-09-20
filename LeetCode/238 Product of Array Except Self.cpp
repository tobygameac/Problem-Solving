class Solution {
 
 public:
  
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    const size_t N = nums.size();
    std::vector<int> result(N);
    for (int i = N - 1; i >= 0; --i) {
      result[i] = nums[i] * ((i < (N - 1)) ? result[i + 1] : 1);
    }
    int pre = 1;
    for (int i = 0; i < N; ++i) {
      result[i] = pre * ((i < (N - 1)) ? result[i + 1] : 1);
      pre *= nums[i];
    }
    return result;
  }

};
