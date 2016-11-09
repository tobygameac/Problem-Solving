class Solution {

 public:

  int minMoves(std::vector<int> &nums) {
    int result = 0;
    int base = INT_MAX;
    for (int n : nums) {
      base = (n < base) ? n : base;
    }
    for (int n : nums) {
      result += (n - base);
    }
    return result;
  }

};
