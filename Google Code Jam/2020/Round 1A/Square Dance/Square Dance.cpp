#include <iostream>
#include <string>
#include <vector>

unsigned long long Compete(const std::vector<std::vector<int> > &value)
{
  int R = value.size();
  if (!R) {
    return 0;
  }
  int C = value[0].size();

  // up, down, left, right
  std::pair<int, int> dir[4] = {std::make_pair(-1, 0), std::make_pair(1, 0), std::make_pair(0, -1), std::make_pair(0, 1)};
  std::vector<std::vector<std::pair<int, int> > > neighbor[4];
  std::vector<std::pair<int, int> > target;
  
  unsigned long long current_value = 0, total_value = 0;

  for (int d = 0; d < 4; ++d) {
    for (int r = 0; r < R; ++r) {
      neighbor[d].emplace_back();
      for (int c = 0; c < C; ++c) {
        if (!d) {
          current_value += value[r][c];
          target.emplace_back(std::make_pair(r, c));
        }
        neighbor[d][r].emplace_back(std::make_pair(r + dir[d].first, c + dir[d].second));
      }
    }
  }

  std::vector<std::vector<int> > last_round(R, std::vector<int>(C, -1));
  for (int round = 0; ; ++round) {
    std::vector<std::pair<int, int> > new_target;
    std::vector<std::pair<int, int> > removed;

    total_value += current_value;

    for (auto &position : target) {
      int r = position.first, c = position.second;
      int neighbor_sum = 0, neighbor_count = 0;
      for (int d = 0; d < 4; ++d) {
        std::pair<int, int> n = neighbor[d][r][c];
        int n_r = n.first, n_c = n.second;
        if ((n_r >= 0) && (n_r < R) && (n_c >= 0) && (n_c < C)) {
          ++neighbor_count;
          neighbor_sum += value[n_r][n_c];
        }
      }
      if (neighbor_sum > (value[r][c] * neighbor_count)) {
        current_value -= value[r][c];
        last_round[r][c] = round;
        removed.emplace_back(std::make_pair(r, c));
      }
    }

    for (auto &position : removed) {
      int r = position.first, c = position.second;
      for (int d = 0; d < 4; ++d) {
        std::pair<int, int> n = neighbor[d][r][c];
        int n_r = n.first, n_c = n.second;
        if ((n_r >= 0) && (n_r < R) && (n_c >= 0) && (n_c < C)) {
          if (last_round[n_r][n_c] != round) {
            last_round[n_r][n_c] = round;
            new_target.emplace_back(std::make_pair(n_r, n_c));
          }
          if (d == 0) { // up
            neighbor[1][n_r][n_c] = neighbor[1][r][c];
          }
          if (d == 1) { // down
            neighbor[0][n_r][n_c] = neighbor[0][r][c];
          }
          if (d == 2) { // left
            neighbor[3][n_r][n_c] = neighbor[3][r][c];
          }
          if (d == 3) { // right
            neighbor[2][n_r][n_c] = neighbor[2][r][c];
          }
        }
      }
    }

    target = new_target;

    if (!removed.size()) {
      break;
    }
  }

  return total_value;
}

int main()
{
  int T, R, C;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    std::cin >> R >> C;
    std::vector<std::vector<int> > value(R, std::vector<int>(C));
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        std::cin >> value[r][c];
      }
    }
    std::cout << "Case #" << t << ": " << Compete(value) << "\n";
  }
  return 0;
}
