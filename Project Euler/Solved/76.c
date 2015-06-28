#include <stdio.h>

#define MAX_NUM 101

int main() {
  long long count[MAX_NUM] = {1, 1};
  int i, j;
  for (i = 1; i < MAX_NUM; ++i) {
    for (j = (2 < i ? i : 2); j < MAX_NUM; ++j) {
      count[j] += count[j - i];
    }
  }
  printf("%lld\n", count[100] - 1);
  return 0;
}
