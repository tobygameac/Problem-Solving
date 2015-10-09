#include <vector>

class Solution {
 public:
  int nthUglyNumber(int n) {
    std::vector<int> ugly_nums(1, 1);
    ugly_nums.reserve(n);
    int index[3] = {0, 0, 0};
    int base[3] = {2, 3, 5};
    int next_number, min_base_index;
    for (int i = ugly_nums.size(); i <= n; ++i) {
      for (int base_index = 0; base_index < 3; ++base_index) {
        for (; ugly_nums[index[base_index]] * base[base_index] <= ugly_nums.back(); ++index[base_index]);
        if (!base_index || ugly_nums[index[base_index]] * base[base_index] < next_number) {
          next_number = ugly_nums[index[base_index]] * base[base_index];
          min_base_index = base_index;
        }
      }
      ugly_nums.push_back(next_number);
      ++index[min_base_index];
    }
    return ugly_nums[n - 1];
  }
};

int main() {
  return 0;
}
