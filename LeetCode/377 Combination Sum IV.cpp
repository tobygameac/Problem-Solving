class Solution {
 
 public:
  
  int combinationSum4(std::vector<int> &nums, int target) {
    std::vector<int> count(target + 1, 0);
    count[0] = 1;
    for (int i = 1; i <= target; ++i) {
      for (int num : nums) {
        count[i] += (i >= num) ? count[i - num] : 0;
      }
    }
    return count[target];
  }

};

class Solution {
 
 public:

  int CombinationSum4(std::vector<int> &nums, std::vector<int> &records, int target) {
    if (records[target] >= 0) {
      return records[target];
    }
    if (!target) {
      return (records[target] = 1);
    }
    records[target] = 0;
    for (int num : nums) {
      if (target >= num) {
        records[target] += CombinationSum4(nums, records, target - num);
      } else {
        break;
      }
    }
    return records[target];
  }

  int combinationSum4(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> records(target + 1, -1);
    return CombinationSum4(nums, records, target);
  }

};
