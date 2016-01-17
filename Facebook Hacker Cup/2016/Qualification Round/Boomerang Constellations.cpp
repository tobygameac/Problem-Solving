#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>

int SquareDistance(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
  return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    std::vector<std::pair<int, int> > coordinates;

    size_t N;
    std::cin >> N;
    for (size_t i = 0; i < N; ++i) {
      int x, y;
      std::cin >> x >> y;
      coordinates.push_back(std::make_pair(x, y));
    }

    std::map<int, size_t> distance_pairs_count[2222];

    for (size_t i = 0; i < coordinates.size(); ++i) {
      for (size_t j = 0; j < coordinates.size(); ++j) {
        if (i == j) {
          continue;
        }
        int distance = SquareDistance(coordinates[i], coordinates[j]);
        ++distance_pairs_count[i][distance];
      }
    }

    size_t ans = 0;
    for (size_t i = 0; i < coordinates.size(); ++i) {
      for (auto distance_pairs_iterator : distance_pairs_count[i]) {
        size_t pair_size = distance_pairs_iterator.second;
        ans += (pair_size * (pair_size - 1)) / 2;
      }
    }

    std::cout << "Case #" << t << ": " << ans << "\n";
  }
  return 0;
}
