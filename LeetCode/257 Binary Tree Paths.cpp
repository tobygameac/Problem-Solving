#include <cstdio>

class Solution {
 public:
  int integerBreak(int n) {
    int sum = 1;
    while (n >= 3) {
      sum *= 3;
      n -= 3;
    }
    while (n >= 2) {
      sum *= 2;
      n -= 2;
    }
    return sum;
  }
};

int main() { 
  return 0;
}
