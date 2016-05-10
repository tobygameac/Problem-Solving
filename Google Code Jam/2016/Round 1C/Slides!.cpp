#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t B, M;
    std::cin >> B >> M;
    std::cout << "Case #" << t << ": ";
    if (M > ((size_t)1 << (B - 2))) {
      std::cout << "IMPOSSIBLE\n";
      continue;
    }
    std::cout << "POSSIBLE\n";
    std::vector<std::string> map(B, std::string(B, '0'));
    for (size_t r = 0; r < B; ++r) {
      for (size_t c = r + 1; c < B - 1; ++c) {
        map[r][c] = '1';
      }
    }
    for (size_t r = B - 2; r >= 1; --r) {
      size_t ways = ((size_t)1 << (r - 1));
      if (M >= ways) {
        map[r][B - 1] = '1';
        M -= ways;
      }
    }
    map[0][B - 1] = '0' + M;
    for (const std::string s : map) {
      std::cout << s << "\n";
    }
  }
  return 0;
}

