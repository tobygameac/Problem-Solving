class Solution {

 public:
  
  std::vector<std::vector<int> > subsets(std::vector<int> &nums) {
    const size_t N = nums.size();
    const size_t M = 1 << N;
    std::vector<std::vector<int> > ans(M);
    for (size_t i = 0; i < M; ++i) {
      std::vector<int> subset;
      for (size_t bit = 0; bit < N; ++bit) {
        if (i & (1 << bit)) {
          subset.push_back(nums[bit]);
        }
      }
      ans.push_back(subset);
    }
    return ans;
  }

};
