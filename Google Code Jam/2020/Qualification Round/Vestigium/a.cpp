#include <cstdio>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N, k = 0, repeatedR = 0, repeatedC = 0;
    scanf("%d", &N);
    int existedR[101][101] = {}, existedC[101][101] = {};
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < N; ++c) {
        int m;
        scanf("%d", &m);
        if (r == c) {
          k += m;
        }
        ++existedR[r][m];
        ++existedC[c][m];
      }
    }
    for (int r = 0; r < N; ++r) {
      for (int c = 1; c <= N; ++c) {
        if (existedR[r][c] > 1) {
          ++repeatedR;
          break;
        }
      }
    }
    for (int c = 0; c < N; ++c) {
      for (int r = 1; r <= N; ++r) {
        if (existedC[c][r] > 1) {
          ++repeatedC;
          break;
        }
      }
    }
    printf("Case #%d: %d %d %d\n", t, k, repeatedR, repeatedC);
  }
  return 0;
}
