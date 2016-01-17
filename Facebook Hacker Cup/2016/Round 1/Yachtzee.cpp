#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t N;
    std::cin >> N;
    long long A, B;
    std::cin >> A >> B;

    long long total_need = 0;
    std::vector<long long> cost;
    std::vector<long long> cumulative_sum;
    for (size_t i = 0; i < N; ++i) {
      long long C;
      std::cin >> C;
      
      cost.push_back(C);

      total_need += C;
      cumulative_sum.push_back(total_need);
    }

    double sum_per_round = 0;

    for (long long money = 0; money < total_need; ) {
      long long remaining = money % total_need;

      size_t cumulative_sum_index = std::upper_bound(cumulative_sum.begin(), cumulative_sum.end(), remaining) - cumulative_sum.begin();

      long long money_bound = money + cumulative_sum[cumulative_sum_index] - remaining;

      long long money_gap = money_bound - money;

      long long remaining_l = remaining - (cumulative_sum_index ? cumulative_sum[cumulative_sum_index - 1] : 0);
      long long remaining_r = remaining_l + money_gap;

      sum_per_round += money_gap * (double)(remaining_l + remaining_r) * 0.5;

      money = money_bound;
    }

    double expected_left = 0;

    size_t step = 0;
    bool skip_mid = false;
    for (long long money = A; money < B; ) {

      long long remaining = money % total_need;

      if (!remaining && !skip_mid) {
        long long round_bound = B - B % total_need;
        expected_left += sum_per_round * (round_bound - money) / total_need;
        money = round_bound;
        skip_mid = true;
        continue;
      }

      size_t cumulative_sum_index = std::upper_bound(cumulative_sum.begin(), cumulative_sum.end(), remaining) - cumulative_sum.begin();

      long long money_bound = money + cumulative_sum[cumulative_sum_index] - remaining;
      money_bound = std::min(money_bound, B);

      long long money_gap = money_bound - money;

      long long remaining_l = remaining - (cumulative_sum_index ? cumulative_sum[cumulative_sum_index - 1] : 0);
      long long remaining_r = remaining_l + money_gap;

      expected_left += money_gap * (double)(remaining_l + remaining_r) * 0.5;

      money = money_bound;
    }

    expected_left /= (double)(B - A);

    std::cout << "Case #" << t << ": " << std::fixed << std::setprecision(10) << expected_left << "\n";
  }
  return 0;
}
