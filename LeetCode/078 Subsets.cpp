class Solution {

 public:
  
  std::vector<std::vector<int> > subsets(std::vector<int> &nums) {
    std::vector<std::vector<int> > ans(1);
    ans.reserve(1 << (nums.size()));
    for (int n : nums) {
      const size_t N = ans.size();
      for (size_t i = 0; i < N; ++i) {
        ans.push_back(ans[i]);
        ans[N + i].push_back(n);
      }
    }
    return ans;
  }

};
