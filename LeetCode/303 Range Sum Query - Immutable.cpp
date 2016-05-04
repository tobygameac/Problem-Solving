#include <cstdio>
#include <vector>

class NumArray {
 
 public:
   
  NumArray(std::vector<int> &nums) {
    const size_t N = nums.size();
    cummulative_sum = std::vector<int>(N + 1, 0);
    for (size_t i = 1; i <= N; ++i) {
      cummulative_sum[i] = nums[i - 1] + cummulative_sum[i - 1];
    }
  }

  int sumRange(int i, int j) {
    return cummulative_sum[j + 1] - cummulative_sum[i];
  }

  std::vector<int> cummulative_sum;
};

int main() { 
  return 0;
}
