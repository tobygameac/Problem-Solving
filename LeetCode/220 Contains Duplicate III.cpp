class Solution {
 
 public:
  
  int Split(std::vector<int> &nums, int l, int r) {
    int pivot_index = l + rand() % (r - l);
    std::swap(nums[pivot_index], nums[r - 1]);
    int target_index = l;
    for (int i = l; i < r - 1; ++i) {
      if (nums[i] < nums[r - 1]) {
        std::swap(nums[i], nums[target_index++]);
      }
    }
    std::swap(nums[r - 1], nums[target_index]);
    return target_index;
  }

  void SplitWithKth(std::vector<int> &nums, int l, int r, int k) {
    int pivot_index = Split(nums, l, r);
    if (pivot_index == k) {
      return;
    }
    if (pivot_index < k) {
      SplitWithKth(nums, pivot_index + 1, r, k);
    } else {
      SplitWithKth(nums, l, pivot_index, k);
    }
  }

  void wiggleSort(std::vector<int> &nums) {
    const int N = nums.size();
    SplitWithKth(nums, 0, N, N / 2 - !(N & 1));
    std::reverse(nums.begin(), nums.begin() + N / 2 - !(N & 1));
    std::reverse(nums.begin() + N / 2 - !(N & 1), nums.end());
    for (int i = 1, j = N - 1 - !(N & 1); i < j; i += 2, --j) {
      std::swap(nums[i], nums[j]);
    }
  }

};
