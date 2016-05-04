#include <cstdio>
#include <vector>

class Solution {
 public:
  bool canJump(std::vector<int> &nums) {
    size_t max_position = 0;
    for (size_t i = 0; i <= max_position && i < nums.size(); ++i) {
      max_position = (i + nums[i]) > max_position ? (i + nums[i]) : max_position;
    }
    return max_position >= nums.size() - 1;
  }
};

int main() {
  return 0;
}
