#include <cstdio>
#include <cstring>

char gPath[111111];

void ModifyPath(char *path) {
  for (int i = 0; path[i]; ++i) {
    path[i] = (path[i] == 'S') ? 'E' : 'S';
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N;
    scanf("%d", &N);
    scanf("%s", gPath);
    ModifyPath(gPath);
    printf("Case #%d: %s\n", t, gPath);
  }
  return 0;
}
