#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10000
#define MAX_NUM 50000000

int notPrime[MAX_SIZE];
int prime[MAX_SIZE];
int primeCount;

long long square[MAX_SIZE];
long long cube[MAX_SIZE];
long long fourth[MAX_SIZE];

bool combinatable[MAX_NUM];

void buildPrimeTable() {
  int i, j;
  notPrime[0] = notPrime[1] = 1;
  for (i = 0; i < MAX_SIZE; ++i) {
    if (!notPrime[i]) {
      for (j = i + i; j < MAX_SIZE; j += i) {
        notPrime[j] = 1;
      }
    }
  }
  for (i = 0; i < MAX_SIZE; ++i) {
    if (!notPrime[i]) {
      prime[primeCount++] = i;
    }
  }
}

int main() {
  buildPrimeTable();
  int n, i, j, k, ans = 0;
  for (i = 0; i < primeCount; ++i) {
    square[i] = prime[i] * prime[i];
    cube[i] = square[i] * prime[i];
    fourth[i] = square[i] * square[i];
  }
  for (i = 0; i < primeCount; ++i) {
    for (j = 0; j < primeCount; ++j) {
      for (k = 0; k < primeCount; ++k) {
        long long sum = square[i] + cube[j] + fourth[k];
        if (sum < MAX_NUM) {
          combinatable[sum] = 1;
        }
      }
    }
  }
  for (n = 0; n < MAX_NUM; ++n) {
    ans += combinatable[n];
  }
  printf("%d\n", ans);
  return 0;
}
