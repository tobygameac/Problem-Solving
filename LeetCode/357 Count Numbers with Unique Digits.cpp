class Solution {
 
 public:
  
  int countNumbersWithUniqueDigits(int n) {
    if (n <= 0) {
      return !n;
    }
    int total_sum = 10, sum = 9;
    for (int digit = 2, possible = 9; digit <= n; ++digit, --possible) {
      sum = sum * possible;
      total_sum = total_sum + sum;
    }
    return total_sum;
  }

};
