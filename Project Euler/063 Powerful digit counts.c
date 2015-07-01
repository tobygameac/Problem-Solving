#include <stdio.h>
#include <math.h>

int main() {
  int num, power, ans = 0;
  for (num = 1; num < 10000; ++num) {
    for (power = 0; power < 10000; ++power) {
      int digitOfNum = (power * log10(num)) + 1;
      ans += digitOfNum == power;
    }
  }
  printf("%d\n", ans);
  return 0;
}
