#include <stdio.h>
#include <math.h>

int main() {
  int line = 1, maxLine = 1;
  double maxValue = 0;
  int base, e;
  while (scanf("%d,%d", &base, &e) != EOF) {
    double value = e * log(base);
    if (value > maxValue) {
      maxValue = value;
      maxLine = line;
    }
    ++line;
  }
  printf("%d\n", maxLine);
  return 0;
}
