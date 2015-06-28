#include <stdio.h>

const int targetPercent = 99;

int isBouncy(int n) {
  char buf[99];
  sprintf(buf, "%d", n);
  int i, increasing = 1, decreasing = 1;
  for (i = 1; buf[i]; ++i) {
    increasing = increasing && (buf[i] >= buf[i - 1]);
    decreasing = decreasing && (buf[i] <= buf[i - 1]);
  }
  return !(increasing || decreasing);
}

int main() {
  int n, bouncyCount = 0;
  for (n = 1; ; ++n) {
    bouncyCount += isBouncy(n);
    if (bouncyCount * 100 == targetPercent * n) {
      printf("%d\n", n);
      break;
    }
  }
  return 0;
}
