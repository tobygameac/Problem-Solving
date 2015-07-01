class Solution {
 public:
  double myPow(double x, int n) {
    if (x == 1) {
      return 1;
    }
    if (x == -1) {
      return (n & 1) ? -1 : 1;
    }
    if (x == 0) {
      return !n;
    }
    if (n < 0) {
      return 1.0 / myPow(x, -n);
    }
    if (!n) {
      return 1;
    }
    if (n == 1) {
      return x;
    }
    double sqrtValue = myPow(x, n / 2);
    return sqrtValue * sqrtValue * ((n & 1) ? x : 1);
  }
  /*
   * Better solution
   * x = 1 / x, n = -n if n < 0
   */
};

int main() {
  return 0;
}
