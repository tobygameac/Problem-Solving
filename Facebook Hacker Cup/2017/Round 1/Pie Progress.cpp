#include <algorithm>
#include <iostream>

size_t cost[333][333];

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t N, M;
    std::cin >> N >> M;

    for (size_t day = 0; day <= N; ++day) {
      for (size_t eat = 0; eat <= N; ++eat) {
        cost[day][eat] = 2e12;
      }
    }


    cost[0][0] = 0;

    for (size_t day = 1; day <= N; ++day) {
      int price[333];
      for (size_t i = 0; i < M; ++i) {
        std::cin >> price[i];
      }
      std::sort(price, price + M);
      for (size_t need = day; need <= N; ++need) {
        size_t price_sum = 0;
        for (size_t use = 0; (use <= need) && (use <= M); ++use) {
          cost[day][need] = std::min(cost[day][need], cost[day - 1][need - use] + price_sum + use * use);
          if (use < M) {
            price_sum += price[use];
          }
        }
      }
    }

    std::cout << "Case #" << t << ": " << cost[N][N] << "\n";
  }
  return 0;
}
