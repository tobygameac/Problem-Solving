class Solution {
 
 public:
  
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int i = m + n - 1;
    int nums1_i = m - 1;
    int nums2_i = n - 1;
    while (nums1_i >= 0 && nums2_i >= 0) {
      if (nums1[nums1_i] > nums2[nums2_i]) {
        nums1[i--] = nums1[nums1_i--];
      } else {
        nums1[i--] = nums2[nums2_i--];
      }
    }
    while (nums1_i >= 0) {
      nums1[i--] = nums1[nums1_i--];
    }
    while (nums2_i >= 0) {
      nums1[i--] = nums2[nums2_i--];
    }
  }

};
