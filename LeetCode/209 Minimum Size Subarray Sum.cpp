class Solution {
 
 public:
  

  int minSubArrayLen(int s, std::vector<int> &nums) {
    const size_t N = nums.size();
    int sum = 0;
    size_t start_index = 0, need = N + 1;
    for (size_t i = 0; i < N; ++i) {
      sum += nums[i];
      while (sum >= s) {
        need = std::min(need, i - start_index + 1);
        sum = sum - nums[start_index++];
      }
    }
    return (need > N) ? 0 : need;
  }

};

class Solution {
 
 public:
  

  int minSubArrayLen(int s, std::vector<int> &nums) {
    const size_t N = nums.size();
    int sum = 0;
    size_t start_index = 0, need = N + 1;
    for (size_t i = 0; i < N; ++i) {
      sum += nums[i];
      if (sum >= s) {
        need = std::min(need, i - start_index + 1);
        if (i) {
          sum = sum - nums[start_index++];
        }
      }
    }
    return (need > N) ? 0 : need;
  }

  int minSubArrayLen(int s, std::vector<int> &nums) {
    const size_t N = nums.size();
    std::vector<int> sum(N + 1);
    for (size_t i = 1; i <= N; ++i) {
      sum[i] = sum[i - 1] + nums[i - 1];
    }
    size_t need = N + 1;
    for (size_t l = 1; l <= N; ++l) {
      auto target = lower_bound(sum.begin() + l, sum.end(), s + sum[l] - nums[l - 1]);
      if (target != sum.end()) {
        size_t r = target - sum.begin();
        need = std::min(need, r - l + 1);
      }
    }
    return (need > N) ? 0 : need;
  }

};
