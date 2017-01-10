#include <algorithm>
#include <cstdio>
#include <deque>

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N;
    scanf("%d", &N);
    std::deque<int> weights;
    while (N--) {
      int w;
      scanf("%d", &w);
      weights.emplace_back(w);
    }
    std::sort(weights.begin(), weights.end());

    int times = 0;

    while (weights.size()) {
      int max_w = weights.back();
      if (max_w >= 50) {
        ++times;
      } else {
        for (int i = 0; i < weights.size() - 1; ++i) {
          if (max_w * (i + 2) >= 50) {
            for (int j = 0; j <= i; ++j) {
              weights.pop_front();
            }
            ++times;
            break;
          }
        }
      }
      weights.pop_back();
    }

    printf("Case #%d: %d\n", t, times);
  }
  return 0;
}
