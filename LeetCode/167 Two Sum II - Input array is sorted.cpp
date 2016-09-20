class Solution {
 
 public:
  
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    const size_t N = numbers.size();
    size_t l = 0, r = N - 1;
    while ((numbers[l] + numbers[r]) != target) {
      if ((numbers[l] + numbers[r]) < target) {
        ++l;
      } else {
        --r;
      }
    }
    return std::vector<int>{l + 1, r + 1};
  }

};
