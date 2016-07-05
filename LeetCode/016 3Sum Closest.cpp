class Solution {
 
 public:
  
  int threeSumClosest(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    const size_t N = nums.size();
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < N - 2; ++i) {
      int j = i + 1, k = N - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == target) {
          return sum;
        }
        if (std::abs(sum - target) < std::abs(closest - target)) {
          closest = sum;
        }
        if (sum > target) {
          --k;
        } else {
          ++j;
        }

      }
    }
    return closest;
  }

};

class Solution {
 
 public:
  
  int SearchClosest(std::vector<int> &nums, int l, int r, int target) {
    int closest = nums[l];
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        return target;
      }
      if (std::abs(nums[mid] - target) < std::abs(closest - target)) {
        closest = nums[mid];
      }
      if (nums[mid] > target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return closest;
  }

  int threeSumClosest(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    const size_t N = nums.size();
    int closest = nums[0] + nums[1] + nums[2];
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = i + 1; (j + 1) < N; ++j) {
        int sum = nums[i] + nums[j] + SearchClosest(nums, j + 1, N, target - (nums[i] + nums[j]));
        if (std::abs(sum - target) < std::abs(closest - target)) {
          closest = sum;
        }
        if (closest >= target && sum >= closest) {
          break;
        }
      }
    }
    return closest;
  }

};
