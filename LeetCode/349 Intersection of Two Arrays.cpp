class Solution {
 
 public:
  
  std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    std::vector<int> result;
    int N = nums1.size(), M = nums2.size();
    for (size_t i = 0, j = 0; i < N; ++i) {
      if (i && nums1[i] == nums1[i - 1]) {
        continue;
      }
      while (j < M && nums2[j] < nums1[i]) {
        ++j;
      }
      if (j < M && nums2[j] == nums1[i]) {
        result.push_back(nums1[i]);
      }
    }
    return result;
  }

};
