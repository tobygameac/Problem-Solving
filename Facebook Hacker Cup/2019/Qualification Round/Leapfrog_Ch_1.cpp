#include <cstdio>
#include <cmath>

char buf[9999];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%s", buf);
    int beta = 0, lilypad = 0;
    for (int i = 0; buf[i]; ++i) {
      beta += (buf[i] == 'B');
      lilypad += (buf[i] == '.');
    }
    printf("Case #%d: %s\n", t, ((beta >= lilypad) && lilypad) ? "Y" : "N");
  }
  return 0;
}
