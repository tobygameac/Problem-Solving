#include <vector>
#include <algorithm>

class Solution {
 public:
   bool find(std::vector<int> &nums, int l, int r, int target) {
     if (l < 0 || r >= nums.size()) {
       return false;
     }
     while (l <= r) {
       int m = (l + r) / 2;
       if (nums[m] == target) {
         return true;
       }
       if (nums[m] > target) {
         r = m - 1;
       } else {
         l = m + 1;
       }
     }
     return false;
   }

   std::vector<std::vector<int> > threeSum(std::vector<int> &nums) {
     std::sort(nums.begin(), nums.end());
     std::vector<std::vector<int> > answer;
     for (int i = 0; i < nums.size(); ++i) {
      if (i && (nums[i] == nums[i - 1])) {
        continue;
      }
      for (int j = i + 1; j < nums.size(); ++j) {
        if ((j > i + 1) && (nums[j] == nums[j - 1])) {
          continue;
        }
        if (find(nums, j + 1, nums.size() - 1, -nums[i] - nums[j])) {
          answer.push_back(std::vector<int>{nums[i], nums[j], -nums[i] - nums[j]});
        }
      }
     }
     return answer;
  }
};

int main() {
  return 0;
}
