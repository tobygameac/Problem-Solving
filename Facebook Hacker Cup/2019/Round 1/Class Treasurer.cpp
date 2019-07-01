#include <cstdio>
#include <algorithm>

const int MOD = 1e9 + 7;
const int MAX_N = 1111111;
int cost[MAX_N];
char vote[MAX_N];

int main() {
  cost[0] = 2;
  for (int i = 1; i < 1000000; ++i) {
    cost[i] = (cost[i - 1] * 2) % MOD;
  }

  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N, K;
    scanf("%d%d", &N, &K);
    scanf("%s", vote);

    int a = 0, b = 0, total_cost = 0;
    for (int i = N - 1; i >= 0; --i) {
      if (vote[i] == 'B') {
        ++b;
      } else {
        ++a;
      }
      if (b > (a + K)) {
        total_cost = (total_cost + cost[i]) % MOD;
        --b;
        ++a;
      }
      if (a > b) {
        a = b = 0;
      }
    }
    printf("Case #%d: %d\n", t, total_cost);
  }
  return 0;
}
