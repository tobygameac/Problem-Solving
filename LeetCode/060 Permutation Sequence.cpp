class Solution {
 
 public:
  
  std::string getPermutation(int n, int k) {
    --k;
    std::vector<int> digits(n);
    for (int i = 0; i < n; ++i) {
      digits[i] = i + 1;
    }
    int combination = 1;
    for (int i = 2; i < n; ++i) {
      combination *= i;
    }
    std::string permutation;
    for (int i = n - 1; i >= 0; --i) {
      int target_index = k / combination;
      permutation += ('0' + digits[target_index]);
      digits.erase(digits.begin() + target_index);
      k = k % combination;
      if (i) {
        combination = combination / i;
      }
    }
    return permutation;
  }

};
