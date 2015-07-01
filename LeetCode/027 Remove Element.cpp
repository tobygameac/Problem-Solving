#include <cstdio>
#include <vector>

using std::vector;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    vector<int> modifiedVector;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        modifiedVector.push_back(nums[i]);
      }
    }
    nums = modifiedVector;
    return nums.size();
  }
};

int main() {
  return 0;
}
