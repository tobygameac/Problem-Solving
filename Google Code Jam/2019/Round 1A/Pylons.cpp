#include <algorithm>
#include <cstdio>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

bool solved;

struct Position {
  int r, c;
};

std::vector<Position> answer;

bool AvailablePosition(const Position &a, const Position &b) {
  if (a.r == b.r) {
    return false;
  }
  if (a.c == b.c) {
    return false;
  }
  if ((a.r - a.c) == (b.r - b.c)) {
    return false;
  }
  if ((a.r + a.c) == (b.r + b.c)) {
    return false;
  }
  return true;
}

void Visit(Position current_position, std::vector<Position> &remaining, std::vector<Position> &path) {
  if (solved) {
    return;
  }

  if (!remaining.size()) {
    solved = true;
    answer = path;
    return;
  }

  for (int i = 0; i < remaining.size(); ++i) {
    if (AvailablePosition(current_position, remaining[i])) {
      Position next_position = remaining[i];

      path.push_back(next_position);
      remaining.erase(remaining.begin() + i);
      Visit(next_position, remaining, path);
      remaining.insert(remaining.begin() + i, next_position);
      path.pop_back();
    }
  }
}

std::vector<Position> Solve(int R, int C) {
  Position start_position{0, 0};

  std::vector<Position> remaining;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      if (!r && !c) { // start
        continue;
      }
      remaining.push_back((Position){r, c});
    }
  }

  std::vector<Position> path;
  path.push_back((Position){0, 0});

  solved = false;
  Visit(start_position, remaining, path);

  if (solved) {
    return answer;
  }

  return std::vector<Position>();
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int R, C;
    scanf("%d%d", &R, &C);

    bool transposed = false;
    if (R > C) {
      transposed = true;
      std::swap(R, C);
    }
    
    std::vector<Position> possible_path;

    if ((R <= 5) && (C <= 5)) {
      std::vector<Position> path = Solve(R, C);
      for (int i = 0; i < path.size(); ++i) {
        possible_path.push_back((Position){path[i].r, path[i].c});
      }
    } else if (R & 1) {
      int remain_c = C, solve_c = 0;
      while (remain_c >= 8) {
        std::vector<Position> path = Solve(3, 4);
        for (int i = 0; i < path.size(); ++i) {
          possible_path.push_back((Position){path[i].r, path[i].c + solve_c});
        }
        remain_c -= 4;
        solve_c += 4;
      }
      std::vector<Position> path = Solve(3, remain_c);
      for (int i = 0; i < path.size(); ++i) {
        possible_path.push_back((Position){path[i].r, path[i].c + solve_c});
      }
      for (int solve_r = 3; solve_r < R; solve_r += 2) {
        std::vector<Position> path = Solve(2, C);
        for (int i = 0; i < path.size(); ++i) {
          possible_path.push_back((Position){path[i].r + solve_r, path[i].c});
        }
      }
    } else {
      for (int solve_r = 0; solve_r < R; solve_r += 2) {
        std::vector<Position> path = Solve(2, C);
        for (int i = 0; i < path.size(); ++i) {
          possible_path.push_back((Position){path[i].r + solve_r, path[i].c});
        }
      }
    }

    printf("Case #%d: %s\n", t, possible_path.size() ? "POSSIBLE" : "IMPOSSIBLE");

    for (int i = 0; i < possible_path.size(); ++i) {
      if (transposed) {
        std::swap(possible_path[i].r, possible_path[i].c);
      }
      printf("%d %d\n", possible_path[i].r + 1, possible_path[i].c + 1);
    }

  }
  return 0;
}
