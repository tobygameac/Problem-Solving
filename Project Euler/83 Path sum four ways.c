#include <stdio.h>

#define MAX_SIZE 99
#define MAX_VALUE 1e8

int matrix[MAX_SIZE][MAX_SIZE];
int minSum[MAX_SIZE][MAX_SIZE];

int min(int a, int b) {
  return (a < b) ? a : b;
}

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

void traversal(int R, int C, int r, int c, int sum) {
  minSum[r][c] = sum + matrix[r][c];
  int d;
  for (d = 0; d < 4; ++d) {
    int nextR = r + dr[d];
    int nextC = c + dc[d];
    if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C) {
      if (minSum[r][c] + matrix[nextR][nextC] < minSum[nextR][nextC]) {
        traversal(R, C, r + dr[d], c + dc[d], minSum[r][c]);
      }
    }
  }
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

  traversal(R, C, 0, 0, 0);

  printf("%d\n", minSum[R - 1][C - 1]);
  return 0;
}
