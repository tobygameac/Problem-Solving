#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int> &nums) {
    int non_zero_count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i]) {
        nums[non_zero_count++] = nums[i];
      }
    }
    for (int i = non_zero_count; i < nums.size(); ++i) {
      nums[i] = 0;
    }
  }
};

int main() {
  return 0;
}
