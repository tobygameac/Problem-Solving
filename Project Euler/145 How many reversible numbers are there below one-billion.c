#include <stdio.h>

#define MAX_NUM (1e9 + 1)

int isReversible(int n) {
  int tempN = n, revN = 0;
  while (tempN) {
    revN = (revN * 10) + (tempN % 10);
    tempN /= 10;
  }
  int sum = n + revN;
  while (sum) {
    if (!((sum % 10) & 1)) {
      return 0;
    }
    sum /= 10;
  }
  return (n % 10) != 0;
}

int main() {
  int n, count = 0;
  for (n = 1; n < MAX_NUM; ++n) {
    count += isReversible(n);
  }
  printf("%d\n", count);
  return 0;
}
