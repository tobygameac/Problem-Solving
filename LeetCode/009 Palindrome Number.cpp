#include <cmath>

class Solution {
 public:
  int getNthDigit(int x, int n) {
    long long power = pow(10, n);
    return ((long long)x % (power * 10)) / power;
  }

  bool isPalindrome(int x) {
    if (x < 0) {
      return 0;
    }
    int digitCount = log10(x) + 1;
    for (int i = 0; i < (digitCount / 2); ++i) {
      if (getNthDigit(x, i) != getNthDigit(x, digitCount - i - 1)) {
        return 0;
      }
    }
    return 1;
  }
};

int main() {
  return 0;
}
