class Solution {
 
 public:
  
  int rob(std::vector<int> &nums) {
    const size_t N = nums.size();
    if (!N) {
      return 0;
    }
    int best_answer = 0;
    std::vector<int> answer(N);
    for (size_t i = 0; i < N; ++i) {
      answer[i] = nums[i];
      if (i) {
        answer[i] = std::max(answer[i], answer[i - 1]);
      }
      if (i > 1) {
        answer[i] = max(answer[i], answer[i - 2] + nums[i]);
      }
    }
    if (N > 1) {
      best_answer = std::max(best_answer, answer[N - 2]);
      answer[0] = 0;
      for (size_t i = 0; i < N; ++i) {
        answer[i] = nums[i];
        if (i) {
          answer[i] = std::max(answer[i], answer[i - 1]);
        }
        if (i > 1) {
          answer[i] = max(answer[i], answer[i - 2] + nums[i]);
        }
      }
    }
    best_answer = std::max(best_answer, answer[N - 1]);
    return answer[0];
  }

};
