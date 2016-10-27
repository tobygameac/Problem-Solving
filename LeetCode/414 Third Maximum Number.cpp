class Solution {

 public:

  int thirdMax(std::vector<int> &nums) {
    const size_t N = nums.size();
    if (!N) {
      return 0;
    }
    std::vector<int> top = {nums[0]};
    for (size_t i = 1; i < N; ++i) {
      bool repeated = false;
      for (auto t : top) {
        if (nums[i] == t) {
          repeated = true;
        }
      }
      if (!repeated) {
        if (top.size() < 3) {
          top.push_back(nums[i]);
          std::sort(top.begin(), top.end());
        } else {
          for (int k = 2; k >= 0; --k) {
            if (nums[i] > top[k]) {
              for (size_t j = 0; j < k; ++j) {
                top[j] = top[j + 1];
              }
              top[k] = nums[i];
              break;
            }
          }
        }
      }
    }
    return (top.size() < 3) ? top.back() : top[0];
  }

};
