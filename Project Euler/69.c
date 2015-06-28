#include <stdio.h>
#include <math.h>

#define MAX_NUM 1000001

int isPrime[MAX_NUM];

int gcd(int a, int b) {
  while ((a %= b) && (b %= a));
  return a + b;
}

int main() {
  int i, j, n;
  for (n = 0; n < MAX_NUM; ++n) {
    isPrime[n] = (n > 1);
    for (i = 2; isPrime[n] && i <= sqrt(n); ++i) {
      if (!(n % i)) {
        isPrime[n] = 0;
      }
    }
  }
  double maxValue = 0;
  for (i = 2; i < MAX_NUM; ++i) {
    int phi = 0;
    if (isPrime[i]) {
      phi = i - 1;
    } else {
      for (j = 1; j < i; ++j) {
        phi += isPrime[j] || ((gcd(i, j) == 1));
      }
    }
    double value = i / phi;
    if (value > maxValue) {
      maxValue = value;
      n = i;
    }
  }
  printf("%d\n", n);
  return 0;
}
