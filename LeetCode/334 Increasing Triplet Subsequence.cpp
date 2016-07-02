class Solution {
 
 public:
  
  bool increasingTriplet(std::vector<int> &nums) {
    const size_t N = nums.size();
    if (N < 3) {
      return false;
    }
    int a = nums[0], b = nums[1];
    bool found_b = false;
    for (size_t i = 1; i < N; ++i) {
      if (found_b && (nums[i] > b)) {
        return true;
      }
      if (nums[i] > a) {
        if (found_b) {
          b = std::min(b, nums[i]);
        } else {
          found_b = true;
          b = nums[i];
        }
      } else {
        a = nums[i];
      }
    }
    return false;
  }

};
