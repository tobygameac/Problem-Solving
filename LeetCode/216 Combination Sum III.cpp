class Solution {
 
 public:
  
  void CombinationSum(int digit, int target, int remaining, std::vector<int> &record, std::vector<std::vector<int> > &ans) {
    if (!remaining) {
      if (!target) {
        ans.push_back(record);
      }
      return;
    }
    if (target <= 0) {
      return;
    }

    for (int d = digit; d <= 9 && d <= target; ++d) {
      record.push_back(d);
      CombinationSum(d + 1, target - d, remaining - 1, record, ans);
      record.pop_back();
    }
  }

  std::vector<std::vector<int> > combinationSum3(int k, int n) {
    std::vector<std::vector<int> > ans;
    std::vector<int> record;
    CombinationSum(1, n, k, record, ans);
    return ans;
  }

};
