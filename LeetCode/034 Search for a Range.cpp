#include <vector>

using std::vector;

class Solution {
 public:
  int indexOfFirstTarget(vector<int>& nums, int l, int r, int target) {
    int m = (l + r) / 2;
    if (nums[m] == target) {
      if (!m || nums[m - 1] != target) {
        return m;
      }
      return indexOfFirstTarget(nums, 0, m - 1, target);
    }
    if (l >= r) {
      return -1;
    }
    if (target > nums[m]) {
      return indexOfFirstTarget(nums, m + 1, r, target);
    }
    return indexOfFirstTarget(nums, l, m - 1, target);
  }

  int indexOfLastTarget(vector<int>& nums, int l, int r, int target) {
    int m = (l + r) / 2;
    if (nums[m] == target) {
      if (m == nums.size() - 1 || nums[m + 1] != target) {
        return m;
      }
      return indexOfLastTarget(nums, m + 1, nums.size() - 1, target);
    }
    if (l >= r) {
      return -1;
    }
    if (target > nums[m]) {
      return indexOfLastTarget(nums, m + 1, r, target);
    }
    return indexOfLastTarget(nums, l, m - 1, target);
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2);
    int index1 = indexOfFirstTarget(nums, 0, nums.size() - 1, target);
    if (index1 == -1) {
      ans[0] = ans[1] = -1;
      return ans;
    }
    int index2 = indexOfLastTarget(nums, 0, nums.size() - 1, target);
    ans[0] = index1;
    ans[1] = index2;
    return ans;
  }
};

int main() {
  return 0;
}
