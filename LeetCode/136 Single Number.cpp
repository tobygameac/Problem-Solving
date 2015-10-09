#include <vector>

class Solution {
 public:
  int singleNumber(std::vector<int> &nums) {
    int mask = 0;
    for (const auto &num : nums) {
      mask ^= num;
    }
    return mask;
  }
};

int main() {
  return 0;
}
