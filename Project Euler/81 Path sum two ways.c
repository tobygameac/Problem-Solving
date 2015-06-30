#include <stdio.h>

#define MAX_SIZE 99

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
  minSum[0][0] = matrix[0][0];

  for (r = 1; r < R; ++r) {
    minSum[r][0] = minSum[r - 1][0] + matrix[r][0];
  }
  for (c = 1; c < C; ++c) {
    minSum[0][c] = minSum[0][c - 1] + matrix[0][c];
  }

  for (r = 1; r < R; ++r) {
    for (c = 1; c < C; ++c) {
      minSum[r][c] = min(minSum[r][c - 1], minSum[r - 1][c]) + matrix[r][c];
    }
  }

  printf("%d\n", minSum[R - 1][C - 1]);
  return 0;
}
