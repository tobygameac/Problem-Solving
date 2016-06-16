class Solution {
 
 public:
  
  int rob(std::vector<int> &nums) {
    std::vector<int> answer = nums;
    const size_t N = nums.size();
    for (size_t i = 0; i < N; ++i) {
      if (i) {
        answer[i] = std::max(answer[i], answer[i - 1]);
      }
      if (i > 1) {
        answer[i] = max(answer[i], answer[i - 2] + nums[i]);
      }
    }
    return N ? answer.back() : 0;
  }

};
