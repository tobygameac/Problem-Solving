#include <iostream>
#include <string>
#include <vector>

void PascalWalk(int N)
{
  int max_row = std::min(30, N);
  N -= max_row;
  bool need_row[30] = {};
  for (int r = 29; r > 0; --r) {
    if (N >= ((1 << r) - 1)) {
      N -= (1 << r) - 1;
      need_row[r] = true;
    }
  }

  bool side = true;
  for (int r = 0; r < max_row + N; ++r) {
    if ((r < max_row) && need_row[r]) {
      for (int c = 0; c <= r; ++c) {
        std::cout << (r + 1) << " " << (side ? (r - c + 1) : (c + 1)) << "\n";
      }
      side = !side;
    } else {
      if (side) {
        std::cout << (r + 1) << " " << (r + 1) << "\n";
      } else {
        std::cout << (r + 1) << " 1\n";
      }
    }
  }
}

int main()
{
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    std::cin >> N;
    std::cout << "Case #" << t << ":\n";
    PascalWalk(N);
  }
  return 0;
}
