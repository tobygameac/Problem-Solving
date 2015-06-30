#include <stdio.h>

#define MAX_SIZE 99
#define MAX_VALUE 1e8

int matrix[MAX_SIZE][MAX_SIZE];
int minSum[MAX_SIZE][MAX_SIZE];

int min(int a, int b) {
  return (a < b) ? a : b;
}

int main() {
  char buf[9999];
  int R = 0, C, r, c;
  while (gets(buf)) {
    int num = 0, numCount = 0;
    for (c = 0; ; ++c) {
      if (!buf[c]) {
        matrix[R][numCount++] = num;
        break;
      }
      if (buf[c] >= '0' && buf[c] <= '9') {
        num = num * 10 + buf[c] - '0';
      } else {
        matrix[R][numCount++] = num;
        num = 0;
      }
    }
    ++R;
    C = numCount;
  }

  for (r = 0; r < R; ++r) {
    for (c = 0; c < C; ++c) {
      minSum[r][c] = MAX_VALUE;
    }
  }

  for (r = 0; r < R; ++r) {
    minSum[r][0] = matrix[r][0];
  }

  for (c = 1; c < C; ++c) {
    int times = R;
    while (times--) {
      for (r = 0; r < R; ++r) {
        minSum[r][c] = min(min(minSum[r][c], minSum[r][c - 1]), min(r ? minSum[r - 1][c] : MAX_VALUE, (r < R - 1) ? minSum[r + 1][c] : MAX_VALUE)) + matrix[r][c];
      }
    }
  }

  int ans = MAX_VALUE;
  for (r = 0; r < R; ++r) {
    ans = min(ans, minSum[r][C - 1]);
  }

  printf("%d\n", ans);
  return 0;
}
