#include <cstdio>

class Solution {
 public:
  int integerBreak(int n) {
    if (n == 2 || n == 3) {
      return n - 1;
    }
    int answer = 1;
    while (n >= 3) {
      if (n == 4) {
        answer *= 4;
        n -= 4;
      } else {
        answer *= 3;
        n -= 3;
      }
    }
    while (n >= 2) {
      answer *= 2;
      n -= 2;
    }
    return answer;
  }
};

int main() { 
  return 0;
}
