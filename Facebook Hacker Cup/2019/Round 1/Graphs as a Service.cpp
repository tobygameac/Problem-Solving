#include <cstdio>
#include <cmath>


int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N, M;
    scanf("%d%d", &N, &M);
    int dis[99][99], target[99][99];
    for (int i = 0; i < 99; ++i) {
      for (int j = 0; j < 99; ++j) {
        dis[i][j] = target[i][j] = -1;
      }
    }
    bool impossible = false;
    for (int i = 0; i < M; ++i) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      if ((dis[x][y] != -1) && (dis[x][y] != z)) {
        impossible = true;
      }
      if (x == y) {
        impossible = true;
      }
      dis[x][y] = dis[y][x] = target[x][y] = target[y][x] = z;
    }
    
    if (!impossible) {
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          for (int m = 1; m <= N; ++m) {
            if ((dis[i][m] != -1) && (dis[m][j] != -1)) {
              int new_distance = dis[i][m] + dis[m][j];
              if ((new_distance < dis[i][j]) || (dis[i][j] == -1)) {
                dis[i][j] = new_distance;
              }
            }
          }
        }
      }
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          if ((target[i][j] != -1) && (dis[i][j] != target[i][j])) {
            impossible = true;
          }
        }
      }
    }

    if (impossible) {
      printf("Case #%d: Impossible\n", t);
    } else {

      int e = 0;
      for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
          e += (target[i][j] != -1);
        }
      }

      printf("Case #%d: %d\n", t, e);

      for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
          if (target[i][j] != -1) {
            printf("%d %d %d\n", i, j, target[i][j]);
          }
        }
      }
    }
  }
  return 0;
}
