#include <vector>
#include <algorithm>

using namespace std;

class NumWithIndex {
 public:
  NumWithIndex() {}

  int num;
  int index;

  bool operator < (const NumWithIndex& other) const {
    return (other.num != num) ? (other.num > num) : (other.index > index);
  }

  bool operator == (const NumWithIndex& other) const {
    return other.num == num && other.index == index;
  }
};

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<NumWithIndex> nums_with_index(nums.size());

    for (int i = 0; i < nums.size(); ++i) {
      nums_with_index[i].num = nums[i];
      nums_with_index[i].index = i;
    }

    sort(nums_with_index.begin(), nums_with_index.end());

    vector<int> ans;
    for (int i = 0, j = nums_with_index.size() - 1; i < j; ) {
      while (nums_with_index[i].num + nums_with_index[j].num > target) {
        --j;
      }
      if (nums_with_index[i].num + nums_with_index[j].num == target) {
        ans.push_back(nums_with_index[i].index);
        ans.push_back(nums_with_index[j].index);
        break;
      }
      ++i;
    }
    return ans;
  }
};

int main() {
  return 0;
}
