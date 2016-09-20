class Solution {
 
 public:
   
  int IntegerReplacement(long long n) {
    if (n <= 1) {
      return 0;
    }
    if (n & 1) {
      return 1 + std::min(IntegerReplacement(n + 1), IntegerReplacement(n - 1));
    }
    return 1 + IntegerReplacement(n / 2);
  }

  int integerReplacement(int n) {
    return IntegerReplacement(n);
  }

};
