#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t N;
    std::cin >> N;

    std::bitset<2555> states;

    for (size_t i = 0; i < 2 * N - 1; ++i)  {
      for (size_t j = 0; j < N; ++j) {
        size_t height;
        std::cin >> height;
        states.flip(height);
      }
    }

    std::cout << "Case #" << t << ":";
    for (size_t i = 0; i < states.size(); ++i) {
      if (states[i]) {
        std::cout << " " << i;
      }
    }
    std::cout << "\n";
  }
  return 0;
}
