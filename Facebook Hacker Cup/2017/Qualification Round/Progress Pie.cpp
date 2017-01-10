#include <cstdio>
#include <cmath>

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int P, X, Y;
    scanf("%d%d%d", &P, &X, &Y);

    int x = X - 50;
    int y = Y - 50;

    double angle = atan2(x, y) * 180.0 / acos(-1);
    while (angle < 0) {
      angle += 360;
    }
    while (angle >= 360) {
      angle -= 360;
    }
    
    double progress_angle = 360 * 0.01 * P;

    bool is_white = true;

    if (angle <= progress_angle) {
      int sqr_distance = x * x + y * y;
      if (sqr_distance <= 2500) {
        is_white = false;
      }
    }

    printf("Case #%d: %s\n", t, is_white ? "white" : "black");
  }
  return 0;
}
