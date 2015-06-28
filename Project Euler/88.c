#include <stdio.h>

int solved;

int productSum(int n, int times, int minNum, int product, int sum) {
  if (solved) {
    return;
  }
  if (!n || !times) {
    if (!n && !times && product == sum) {
      solved = 1;
    }
    return;
  }
  int i;
  for (i = minNum; i <= n; ++i) {
    productSum(n - i, times - 1, i, product * i, sum + i);
  }
}

int main() {
  int k, n = 1, ans = 0;
  for (k = 2; k <= 12000; ++k) {
    solved = 0;
    while (!solved) {
      productSum(n, k, 1, 1, 0);
      ++n;
    }
    --n;
    ans += n;
    printf("%d : %d\n", k, n);
  }
  printf("%d\n", ans);
  return 0;
}
