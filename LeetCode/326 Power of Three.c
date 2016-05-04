#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool isPowerOfThree(int n) {
  double times = log10(n) / log10(3);
  return times == (int)times;
}

int main() {
  return 0;
}
