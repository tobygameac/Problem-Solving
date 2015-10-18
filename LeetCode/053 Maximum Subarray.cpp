#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int> &nums) {
    int sum = nums.size() ? nums[0] : 0, ans = sum;
    for (int i = 1; i < nums.size(); ++i) {
      sum = nums[i] + ((sum > 0) ? sum : 0);
      ans = (sum > ans) ? sum : ans;
    }
    return ans;
  }
};

int main() {
  return 0;
}
