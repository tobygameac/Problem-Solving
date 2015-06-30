#include <stdio.h>

const int MAX_N = 10000000;

int digitSum(int n) {
  int sum = 0;
  while (n) {
    sum += (n % 10) * (n % 10);
    n /= 10;
  }
  return sum;
}

int main() {
  int n = 1, ans = 0;
  for (; n < MAX_N; ++n) {
    int sum = n;
    do {
      sum = DigitSum(sum);
    } while ((sum != 1) && (sum != 89));
    ans += (sum == 89);
  }
  printf("%d\n", ans);
  return 0;
}
