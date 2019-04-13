#include <algorithm>
#include <cstdio>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
  int T, N, M;
  scanf("%d%d%d", &T, &N, &M);
  for (int t = 1; t <= T; ++t) {

    int remains[7] = {};
    int guess[7] = {16, 3, 5, 7, 11, 13, 17};

    for (int n = 0; n < 7; ++n) {

      for (int i = 0; i < 18; ++i) {
        printf("%d%s", guess[n], (i == 17) ? "\n" : " ");
      }
      fflush(stdout);

      for (int i = 0; i < 18; ++i) {
        int offset;
        scanf("%d", &offset);
        remains[n] = (remains[n] + offset) % guess[n];
      }
    }

    int answer = -1;
    for (int m = 0; m <= M; ++m) {
      bool ok = true;
      for (int n = 0; ok && (n < 7); ++n) {
        ok = ((m % guess[n]) == remains[n]);
      }
      if (ok) {
        answer = m;
        break;
      }
    }


    printf("%d\n", answer);
    fflush(stdout);

    int result;
    scanf("%d", &result);

    if (result == -1) {
      return 0;
    }
  }
  return 0;
}
