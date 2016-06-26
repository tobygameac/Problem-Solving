class Solution {
 
 public:
  
  int Partition(std::vector<int> &nums, int l, int r) {
    int pivot = l + (rand() % (r - l));
    std::swap(nums[pivot], nums[r - 1]);
    int target_index = l;
    for (int i = l; i < r - 1; ++i) {
      if (nums[i] >= nums[r - 1]) {
        std::swap(nums[i], nums[target_index++]);
      }
    }
    std::swap(nums[r - 1], nums[target_index]);
    return target_index;
  }

  int Kth(std::vector<int> &nums, int l, int r, int k) {
    int pivot = Partition(nums, l, r);
    if (k == pivot) {
      return nums[k];
    }
    if (k < pivot) {
      return Kth(nums, l, pivot, k);
    }
    return Kth(nums, pivot + 1, r, k);
  }

  int findKthLargest(std::vector<int> &nums, int k) {
    return Kth(nums, 0, nums.size(), k - 1);
  }

};
