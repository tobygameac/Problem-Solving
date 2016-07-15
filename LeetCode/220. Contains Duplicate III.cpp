class Solution {
 
 public:
  
  bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t) {
    const size_t N = nums.size();
    std::vector<std::pair<int, int> > sorted_list(N);
    for (size_t i = 0; i < N; ++i) {
      sorted_list[i] = std::make_pair(nums[i], i);
    }
    std::sort(sorted_list.begin(), sorted_list.end());
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = i + 1; j < N && (sorted_list[j].first <= t + sorted_list[i].first); ++j) {
        if (std::abs(sorted_list[i].second - sorted_list[j].second) <= k) {
          return true;
        }
      }
    }
    return false;
  }

};
